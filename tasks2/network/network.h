#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <iostream>
#include <QVector>

#include "computer.h"

class Network
{
public:
    /**
      *
      */
    Network(QVector<Computer> _computers);

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
      *
      */
    void nextStep();
    /**
      *
      */
    void heal(int id);
    /**
      * Печатает матрицу сети, выделяя цветами заражённые и находящиеся в опасности компы.
      */
    void print();
    /**
      *
      */
    bool isInfected(int id);
private:
    QVector<Computer> computers;
    QVector< QVector<bool> > matrix;
};

#endif // NETWORK_H
