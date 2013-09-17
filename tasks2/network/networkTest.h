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
    void nextStepTest1()
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
            QCOMPARE(network.isInfected(i), true);
        }
    }
    // пошагово проверям состояние сети (компьютеры создаются со специальным параметром, вероятность заражения = 100%,
    // так что на каждом шаге гарантировано будут происходить заражения
    //
    // Граф такой (сначало заражён только A):
    // A -- D -- F
    // | \  |    |
    // B  C-E    G
    void nextStepTest2()
    {
        QVector<Computer> computers(7);
        for (int i = 0; i < 7; i++)
        {
            computers[i] = Computer(Computer::Test);
        }
        computers[0].infect();
        Network network(computers);
        network.bind(0, 1);
        network.bind(0, 2);
        network.bind(0, 3);
        network.bind(2, 4);
        network.bind(3, 4);
        network.bind(3, 5);
        network.bind(5, 6);

        network.print();

        network.nextStep();
        QCOMPARE(network.isInfected(1), true);
        QCOMPARE(network.isInfected(2), true);
        QCOMPARE(network.isInfected(3), true);
        QCOMPARE(network.isInfected(4), false);
        QCOMPARE(network.isInfected(5), false);
        QCOMPARE(network.isInfected(6), false);
        network.print();

        network.nextStep();
        QCOMPARE(network.isInfected(4), true);
        QCOMPARE(network.isInfected(5), true);
        QCOMPARE(network.isInfected(6), false);
        network.print();

        network.nextStep();
        QCOMPARE(network.isInfected(6), true);
        network.print();
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
