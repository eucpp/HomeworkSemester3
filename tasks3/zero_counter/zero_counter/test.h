#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QTest>

#include "func.h"

class Test : public QObject
{
    Q_OBJECT

private slots:
    void test1()
    {
        QVector<int> array(10, 0);

        QCOMPARE(countZeros(array), 10);
    }

    void test2()
    {
        QVector<int> array(10, 0);
        array[1] = 1;
        array[5] = 5;
        array[9] = 9;

        QCOMPARE(countZeros(array), 7);
    }


    void test3()
    {
        QVector<int> array(10, 0);
        for (QVector<int>::iterator itr = array.begin() ; itr != array.end(); itr++)
        {
            (*itr) = 1;
        }

        QCOMPARE(countZeros(array), 0);
    }
    
};

#endif // TEST_H
