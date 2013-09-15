#ifndef NETWORKTEST_H
#define NETWORKTEST_H

#include <QTest>

#include "network.h"

class NetworkTest: public QObject
{
    Q_OBJECT
private slots:
    // тестируем соединение компьютеров
    void bindTest()
    {
        QVector<Computer> computers(2);
        Network network(computers);

        network.bind(0, 1);

        QCOMPARE(network.isBound(1, 0), true);
    }
    // тестируем разъединение
    void unBindTest()
    {
        QVector<Computer> computers(2);
        Network network(computers);
        network.bind(0, 1);

        network.unbind(0, 1);

        QCOMPARE(network.isBound(1, 0), false);
    }
    // заражаем один компьютер, соединяем его со всеми остальными, ждём несколько ходов,
    // проверяем, заразилась ли вся сеть
    void nextStepTest()
    {
        QVector<Computer> computers(4);
        while (!computers[0].isInfected())
        {
            computers[0].infect();
        }
        Network network(computers);
        for (int i = 1; i < 4; i++)
        {
            network.bind(0, i);
        }

        for (int i = 0; i < 20; i++)
        {
            network.nextStep();
        }

        for (int i = 0; i < 4; i++)
        {
            QCOMPARE(computers[i].isInfected(), true);
        }
    }
    // тестируем излечение
    void healTest()
    {
        QVector<Computer> computers(1);
        while (!computers[0].isInfected())
        {
            computers[0].infect();
        }
        Network network(computers);

        network.heal(0);

        QCOMPARE(network.isInfected(0), false);
    }
};

#endif // NETWORKTEST_H
