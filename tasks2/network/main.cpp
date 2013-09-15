#include <QtCore/QCoreApplication>

#include <QTest>

#include "computerTest.h"
#include "networkTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    if (argc != 0)
    {
        QString cmd(argv[1]);
        if (cmd == "-t")
        {
            ComputerTest test1;
            QTest::qExec(&test1);

            NetworkTest test2;
            QTest::qExec(&test2);
        }
    }

    return a.exec();
}
