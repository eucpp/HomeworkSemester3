#include <QtCore/QCoreApplication>

#include <iostream>

#include "func.h"
#include "test.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (argc != 0)
    {
        QString cmd(argv[1]);
        if (cmd == "-t")
        {
            Test test;
            QTest::qExec(&test);
        }
    }

    QVector<int> array;
    cout << "Enter elements of array: " << endl;
    char ch =cin.get();
    while (ch != '\n')
    {
        if (ch == ' ')
        {
            ch = cin.get();
            continue;
        }
        cin.putback(ch);
        int elem = 0;
        cin >> elem;
        array.append(elem);
        ch = cin.get();
    }

    int num = countZeros(array);
    cout << "Num of zeros in array = " << num << endl;
    
    return a.exec();
}
