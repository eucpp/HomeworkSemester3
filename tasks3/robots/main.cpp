#include <QtCore/QCoreApplication>

#include <iostream>
#include <QTest>

#include "graphTest.h"

using std::cout;
using std::endl;
using std::cin;

/**
  * Задача о роботах.
  * Алгоритм такой:
  *
  * Роботы могут ходить через вершину, оставаться в той же вершине => отношение достижимости роботом какой-то вершины -
  * эквиваленция.
  * Весь граф разбивается на классы эквивалентности.
  * Если в каком-то классе только один робот, значит он не может встретиться ни с каким другим роботом и
  * уничтожится.
  * Если же в классе больше одного робота, то начиная с какого-то хода любой робот может достичь любой вершины,
  * значит можно построить такую последовательность движений роботов, что они все уничтожатся.
  * Достаточно проверить, что в каждом классе больше 1 робота.
  *
  * 1) Для каждого робота строим множество достижимых вершин.
  * 2) Сравниваем эти множества между собой, повторяющиеся удаляем.
  * 3) Проверяем, что в каждом множестве вершин есть хотя бы два робота.
  */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (argc != 0)
    {
        QString cmd(argv[1]);
        if (cmd == "-t")
        {
            GraphTest test1;
            QTest::qExec(&test1);
            a.quit();
        }
    }

    cout << "Enter number of vertices in graph: " << endl;
    int v = 0;
    cin >> v;
    Graph graph(v);
    cout << "For each vertex enter the list of binded vertices:" << endl;
    cin.get();
    for (int i = 0; i < v; i++)
    {
        cout << i << ": ";
        char ch = cin.get();
        while (ch != '\n')
        {
            if (ch == ' ')
            {
                ch = cin.get();
                continue;
            }
            cin.putback(ch);
            int vertex = 0;
            cin >> vertex;
            graph.bind(i, vertex);
            ch = cin.get();
        }
        cout << endl;
    }
    QVector<int> robots;
    cout << "Enter placement of robots: " << endl;
    char ch = cin.get();
    while (ch != '\n')
    {
        if (ch == ' ')
        {
            ch = cin.get();
            continue;
        }
        cin.putback(ch);
        int robot = 0;
        cin >> robot;
        robots.append(robot);
        ch = cin.get();
    }
    cout << endl;

    bool result = true;
    QVector< QSet<int> > classes = graph.getReachableClasses();
    for (int i = 0; i < classes.size(); i++)
    {
        int robotsInClass = 0;
        for (int j = 0; j < robots.size(); j++)
        {
            if (classes[i].contains(robots[j]))
            {
                robotsInClass++;
            }
        }
        if (robotsInClass == 1)
        {
            result = false;
            break;
        }
    }

    if (result)
    {
        cout << "Robots can be destroyed!" << endl;
    }
    else
    {
        cout << "Robots can't be destroyed!" << endl;
    }

    
    return a.exec();
}
