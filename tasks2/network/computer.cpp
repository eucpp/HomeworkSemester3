#include "computer.h"

int Computer::WinInfectPercent = 80;
int Computer::MacInfectPercent = 50;
int Computer::LinInfectPercent = 10;

Computer::Computer(OS _os, bool _infected):
    os(_os),
    infected(_infected)
{
}

void Computer::infect()
{
    qsrand(QTime::currentTime().msec());
    int roll = qrand() % 100;
    switch (os)
    {
    case Windows:
        if (roll < WinInfectPercent)
        {
            infected = true;
        }
        break;
    case Mac:
        if (roll < MacInfectPercent)
        {
            infected = true;
        }
        break;
    case Linux:
        if (roll < LinInfectPercent)
        {
            infected = true;
        }
        break;
    }
}

bool Computer::isInfected()
{
    return infected;
}

Computer::OS Computer::getOS()
{
    return os;
}

void Computer::setOS(Computer::OS _os)
{
    os = _os;
}
