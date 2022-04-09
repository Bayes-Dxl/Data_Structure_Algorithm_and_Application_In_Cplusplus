//
// Created by Hxy on 2022/3/25.
//
#include "vectorList.h"
#include <iostream>
using namespace std;
int main()
{
    vectorList<int> myVector(5);
    try {
        myVector.insert(0, 2);
        myVector.insert(1, 1);
        myVector.insert(2,3);
        myVector.insert(2,4);
        myVector.insert(2,5);
        myVector.insert(2,6);
        myVector.insert(0, 2);
        myVector.insert(1, 1);
        myVector.insert(2,3);
        myVector.insert(2,4);
        myVector.insert(2,5);
        myVector.insert(2,6);
        myVector.insert(0, 2);
        myVector.insert(1, 1);
        myVector.insert(2,3);
        myVector.insert(2,4);
        myVector.insert(2,5);
        myVector.insert(2,6);
        myVector.erase(2);
    }
    catch (illegalIndex &e) {
         e.outputMessage();
    }



    for(int i = 0; i < myVector.size(); i++)
    {
        cout << myVector.get(i) << " ";
    }
    cout << endl;
    cout << myVector;
    cout << endl << myVector.indexOf(3) << endl;

    std::reverse(myVector.begin(), myVector.end());
    cout << myVector << endl;

    myVector.half();
    myVector.half_1();
    cout << myVector << endl;
    cout << "meld() test !" << endl;
    vectorList<int> y1(2);
    y1.insert(0, 1);
    y1.insert(1, 1);
    y1.insert(2, 1);
    y1.insert(3, 5);
    y1.insert(4, 6);
    y1.insert(5, 7);

    vectorList<int> y2(2);
    y2.insert(0, 2);
    y2.insert(1, 2);
    y2.insert(0, 2);

    // 21212121
    // 212111
    vectorList<int> y3(10);
    y3.meld(y2,y1);
    cout << y3;


//    for(vectorList<int>::Iterator i = y3.begin_2();  i != y3.end_2();)
//    {
//        cout << *i << " - "  << endl;
//    }




}