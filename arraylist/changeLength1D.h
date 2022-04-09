//
// Created by Hxy on 2022/3/23.
//

#ifndef UNTITLED_CHANGELENGTH1D_H
#define UNTITLED_CHANGELENGTH1D_H

#include "myExceptions.h"
using namespace std;
template<class T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
    if (newLength < 0)
        throw illegalParameterValue("new length must be >= 0");
    T*temp = new T[newLength];
    int number = min(oldLength, newLength);
    copy(a, a + number, temp);
    delete [] a;
    a = temp;
}

#endif //UNTITLED_CHANGELENGTH1D_H
