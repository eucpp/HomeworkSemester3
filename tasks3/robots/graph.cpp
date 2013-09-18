#include "graph.h"

Graph::Graph(int v):
    analyzed(v),
    reachableClasses(v)
{
    for (int i = 0; i < v; i++)
    {
        analyzed[i] = false;

        matrix.append(QVector<bool>());
        for (int j = 0; j < v; j++)
        {
            matrix[i].append(false);
        }
    }

}

void Graph::bind(int i, int j)
{
    matrix[i][j] = true;
    matrix[j][i] = true;
}

void Graph::unbind(int i, int j)
{
    matrix[i][j] = false;
    matrix[j][i] = false;
}

bool Graph::isBound(int i, int j)
{
    return matrix[i][j];
}

QSet<int> Graph::get2ndReachable(int v)
{
    if (analyzed[v])
    {
        return reachableClasses[v];
    }

    QSet<int> reachable2nd;
    reachable2nd.insert(v);
    // в стеке запоминаются вершины достижимые из данной, которые нужно рекурсивно проанализировать
    QStack<int> vertices;
    vertices.append(v);
    while (!vertices.isEmpty())
    {
        int nextV = vertices.pop();
        QVector<bool> row = matrix[nextV];
        // стэк достижимых вершин первого порядка
        QStack<int> reachable1st;
        for (int i = 0; i < row.size(); i++)
        {
            if (row[i])
            {
                reachable1st.append(i);
            }
        }
        while (!reachable1st.isEmpty())
        {
            QVector<bool> col = matrix[reachable1st.pop()];
            for (int i = 0; i < col.size(); i++)
            {
                if (col[i])
                {
                    // сначала проверяем, не были ли уже мы в этой вершине
                    if (reachable2nd.contains(i))
                    {
                        continue;
                    }
                    else
                    {
                        // проверяем, мб для этой вершины уже составлено множество достижимых
                        // тогда просто возвращаем его
                        if (analyzed[i])
                        {
                            return reachableClasses[i];
                        }
                        // если не были, добавляем в множество достижимых и в стэк проверяемых вершин
                        reachable2nd.insert(i);
                        vertices.append(i);
                    }
                }
            }
        }
    }
    // добавляем посещённые вершины в список классов достижимости
    // чтобы сократить вычисления при следущем обращении к одной из этих вершин
    QSet<int> iterate = reachable2nd;
    for (QSet<int>::const_iterator itr = iterate.begin(); itr != iterate.end(); ++itr)
    {
        analyzed[*itr] = true;
        reachableClasses[*itr] = reachable2nd;
    }

    return reachable2nd;
}

QVector<QSet<int> > Graph::getReachableClasses()
{
}
