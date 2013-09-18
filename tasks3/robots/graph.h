#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <QStack>
#include <QSet>
#include <QDebug>

/**
  * Простая реализация графа с помощью матрицы смежности.
  */
class Graph
{
public:
    /**
      * Создаёт новый граф.
      *
      * @var v кол-во вершин.
      */
    Graph(int v);

    /**
      *
      */
    void bind(int i, int j);
    /**
      *
      */
    void unbind(int i, int j);
    /**
      *
      */
    bool isBound(int i, int j);

    /**
      * Возвращает множество вершин достижимых из v, если двигаться через одну вершину.
      */
    QSet<int> get2ndReachable(int v);
    /**
      * Возвращает классы эквивалентности по отношению достижимости (через одну вершину) для всех для вершин.
      */
    QVector< QSet<int> > getReachableClasses();
private:
    QVector< QVector<bool> > matrix;

    /**
      * В каждом элементе вектора хранится множество достижимых из данной вершины вершин
      */
    QVector< QSet<int> > reachableClasses;
    /**
      * Если какая-то вершина уже была проанализирована и включена в какой-либо класс эквивалентности,
      * в соотствующей ячейке хранится true.
      */
    QVector<bool> analyzed;
};

#endif // GRAPH_H
