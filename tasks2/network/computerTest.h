#ifndef COMPUTERTEST_H
#define COMPUTERTEST_H

#include <QTest>

#include "computer.h"

class ComputerTest: public QObject
{
    Q_OBJECT
private slots:
    void infectTest()
    {
        Computer pc(Computer::Windows);

        for (int i = 0; i < 20; i++)
        {
            pc.infect();
        }

        QCOMPARE(pc.isInfected(), true);
    }
};

#endif // COMPUTERTEST_H
