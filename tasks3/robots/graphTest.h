#ifndef GRAPHTEST_H
#define GRAPHTEST_H

#include <QTest>

#include "graph.h"

class GraphTest : public QObject
{
    Q_OBJECT
private slots:
    // Тестируем на графе (движение начинается с A, в скобках достижимые):
    //
    //          (C)
    //          / \
    // (A) --  B   E -- (F)
    //          \ /
    //          (D)
    void get2ndReachableTest1()
    {
        Graph graph(6);
        graph.bind(0, 1);
        graph.bind(1, 2);
        graph.bind(1, 3);
        graph.bind(2, 4);
        graph.bind(3, 4);
        graph.bind(4, 5);

        QSet<int> actual = graph.get2ndReachable(0);

        QSet<int> expected;
        expected  << 0 << 2 << 3 << 5;
        QCOMPARE(actual, expected);
    }
    // Тестируем на графе (движение начинается с A, в скобках достижимые):
    //
    //    (B) ---
    //    /     |
    //  (A) -- (C)
    //
    void get2ndReachableTest2()
    {
        Graph graph(3);
        graph.bind(0, 1);
        graph.bind(0, 2);
        graph.bind(1, 2);

        QSet<int> actual = graph.get2ndReachable(0);

        QSet<int> expected;
        expected  << 0 << 1 << 2;
        QCOMPARE(actual, expected);
    }
    // Тестируем на графе (движение начинается с A, в скобках достижимые):
    //
    //                  (F)
    //                  / \
    // (A) -- (B) -- (C) -- (E)
    //                |
    //               (D)
    void get2ndReachableTest3()
    {
        Graph graph(6);
        graph.bind(0, 1);
        graph.bind(1, 2);
        graph.bind(2, 3);
        graph.bind(2, 4);
        graph.bind(2, 5);
        graph.bind(4, 5);

        QSet<int> actual = graph.get2ndReachable(0);

        QSet<int> expected;
        expected  << 0 << 1 << 2 << 3 << 4 << 5;
        QCOMPARE(actual, expected);
    }
    // Тестируем на графе (в скобках 2 класса):
    //
    //          (C)
    //          / \
    // (A) -- [B] [D] -- (F)
    //          \ /
    //          (D)
    void getReachableClassesTest()
    {
        Graph graph(6);
        graph.bind(0, 1);
        graph.bind(1, 2);
        graph.bind(1, 3);
        graph.bind(2, 4);
        graph.bind(3, 4);
        graph.bind(4, 5);
        QVector<int> vertices;
        vertices << 0 << 1 << 2 << 3 << 4 << 5 << 6;

        QVector< QSet<int> > actual = graph.getReachableClasses();

        QSet<int> class1;
        class1  << 0 << 2 << 3 << 5;
        QSet<int> class2;
        class2  << 1 << 4;
        QCOMPARE(actual[0], class1);
        QCOMPARE(actual[1], class2);
        QCOMPARE(actual[2], class1);
        QCOMPARE(actual[3], class1);
        QCOMPARE(actual[4], class2);
        QCOMPARE(actual[5], class1);

    }
};

#endif // GRAPHTEST_H
