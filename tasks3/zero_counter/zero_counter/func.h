#ifndef FUNC_H
#define FUNC_H

#include <QVector>

/**
  * Функция считает кол-во нулевых элементов в массиве.
  */
inline int countZeros(QVector<int> array)
{
    int res = 0;
    for (QVector<int>::iterator itr = array.begin() ; itr != array.end(); itr++)
    {
        if ((*itr) == 0)
        {
            res++;
        }
    }
    return res;
}

#endif // FUNC_H
