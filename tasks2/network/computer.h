#ifndef COMPUTER_H
#define COMPUTER_H

class Computer
{
public:
    enum OS
    {
        Windows,
        Mac,
        Linux
    };

    Computer(OS _os = Windows);

    void infect();
    bool isInfected();

    OS getOS();
    void setOS(OS _os);
};

#endif // COMPUTER_H
