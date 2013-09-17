#ifndef COMPUTER_H
#define COMPUTER_H

#include <QTime>

class Computer
{
public:
    enum OS
    {
        Windows,
        Mac,
        Linux,
        // тестовый параметр, вероятность заражения 100%
        Test
    };

    Computer(OS _os = Windows, bool _infected = false);

    /**
      *
      */
    void infect();
    /**
      *
      */
    bool isInfected();
    /**
      *
      */
    void heal();
    /**
      *
      */
    OS getOS();
    /**
      *
      */
    void setOS(OS _os);
private:
    OS os;
    bool infected;

    static int WinInfectPercent;
    static int MacInfectPercent;
    static int LinInfectPercent;
};

#endif // COMPUTER_H
