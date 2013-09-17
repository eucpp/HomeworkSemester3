#include "network.h"

using std::cout;
using std::endl;

Network::Network(QVector<Computer> _computers):
    computers(_computers)
{
    for (int i = 0; i < computers.size(); i++)
    {
        matrix.append(QVector<bool>());
        for (int j = 0; j < computers.size(); j++)
        {
            matrix[i].append(false);
        }
    }
}

void Network::nextStep()
{
    QVector<Computer> copy = computers;
    for (int i = 0; i < copy.size(); i++)
    {
        if (!computers[i].isInfected())
        {
            continue;
        }
        QVector<bool> connections = matrix[i];
        for (int j = 0; j < connections.size(); j++)
        {
            if (connections[j])
            {
                copy[j].infect();
            }
        }
    }
    computers = copy;
}

void Network::heal(int id)
{
    computers[id].heal();
}

void Network::print()
{
    char red[] = "\033[0;31m";
    char yellow[] = "\033[1;33m";
    char green[] = "\033[1;32m";
    char nocolor[] = "\033[0m";

    cout << endl;
    // выводим верхнюю строку со списком компов
    // сначала делаем отступ (т.к каждая следующая строка начинается с имени компа и ОС)
    cout << "      |";
    for (int i = 0; i < computers.size(); i++)
    {
        QVector<bool> connections = matrix[i];
        // выводим номер компьютера красным, если он заражён
        if (computers[i].isInfected())
        {
            cout << red;
        }
        else
        {
            // жёлтым, если он связан с заражённым
            bool dangerous = false;
            for (int j = 0; j < connections.size(); j++)
            {
                if (connections[j] && computers[j].isInfected())
                {
                    cout << yellow;
                    dangerous = true;
                    break;
                }
            }
            // зелёным, если всё в порядке
            if (!dangerous)
            {
                cout << green;
            }
        }
        cout << " " << (char)(i + 'A') << nocolor << " |";
    }
    cout << endl;

    // далее выводим строки
    for (int i = 0; i < computers.size(); i++)
    {
        QVector<bool> connections = matrix[i];
        // выводим номер компьютера и его ОС красным, если они заражены
        if (computers[i].isInfected())
        {
            cout << red;
        }
        else
        {
            // жёлтым, если он связан с заражённым
            bool dangerous = false;
            for (int j = 0; j < connections.size(); j++)
            {
                if (connections[j] && computers[j].isInfected())
                {
                    cout << yellow;
                    dangerous = true;
                    break;
                }
            }
            // зелёным, если всё в порядке
            if (!dangerous)
            {
                cout << green;
            }
        }
        cout << (char)(i + 'A') << " ";
        switch (computers[i].getOS())
        {
        case Computer::Windows:
        {
            cout << "win";
            break;
        }
        case Computer::Mac:
        {
            cout << "mac";
            break;
        }
        case Computer::Linux:
        {
            cout << "lin";
            break;
        }
        case Computer::Test:
            cout << "tst";
            break;
        }
        cout << nocolor << " | ";

        for (int j = 0; j < connections.size(); j++)
        {
            if (connections[j])
            {
                if (computers[i].isInfected() || computers[j].isInfected())
                {
                    cout << yellow;
                }
                cout << 1;
                if (computers[i].isInfected() || computers[j].isInfected())
                {
                    cout << nocolor;
                }
                cout << " | ";
            }
            else
            {
                cout << 0 << " | ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool Network::isInfected(int id)
{
    return computers[id].isInfected();
}

void Network::bind(int i, int j)
{
    matrix[i][j] = true;
    matrix[j][i] = true;
}

void Network::unbind(int i, int j)
{
    matrix[i][j] = false;
    matrix[j][i] = false;
}

bool Network::isBound(int i, int j)
{
    return matrix[i][j];
}
