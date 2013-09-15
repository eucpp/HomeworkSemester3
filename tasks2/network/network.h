#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <QVector>

#include "computer.h"

class Network
{
public:
    /**
      *
      */
    Network(QVector<Computer> computers);

    /**
      *
      */
    void bind(int first, int second);
    /**
      *
      */
    void unbind(int first, int second);
    /**
      *
      */
    bool isBound(int first, int second);
    /**
      *
      */
    void nextStep();
    /**
      *
      */
    void heal(int id);
    /**
      *
      */
    void print();
    /**
      *
      */
    bool isInfected(int id);
};

#endif // NETWORK_H
