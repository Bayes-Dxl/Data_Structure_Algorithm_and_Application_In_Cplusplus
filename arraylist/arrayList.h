//
// Created by Hxy on 2022/3/22.
//

#ifndef UNTITLED_ARRAYLIST_H
#define UNTITLED_ARRAYLIST_H
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include "linearList.h"
#include "myExceptions.h"
#include "changeLength1D.h"

#define  ITERATOR   //开启stl itertor 宏






template <class T>
class arrayList : public linearList<T>
{
public:
    explicit arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T> & theList);
    ~arrayList(){delete[] element;}

    [[nodiscard]] bool empty() const {return listSize == 0;}
    [[nodiscard]] int size() const {return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream & out) const;
//    friend ostream &operator<<(ostream &os, const arrayList &list);
    [[nodiscard]] int capacity() const {return arrayLength;}




#ifdef ITERATOR
    class itertor;
    itertor begin () {return itertor(element);}
    itertor end() {return itertor(element + listSize);}
    class itertor // : std::iterator<std::bidirectional_iterator_tag, T>
    {

    public:
        typedef bidirectional_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;

        // constructor
        explicit itertor(T* thePosition = 0){ position = thePosition;}
        //dereferencing operators
        T& operator*() const {return *position;}
        T* operator->() const {return &*position;}

        itertor & operator++(){ ++position; return *this; }
        itertor  operator++(int) { itertor old = *this; ++position; return old; }

        itertor& operator--()   // predecrement
        { --position; return *this; }

        itertor operator--(int) // postdecrement
        {
            itertor old = *this;
            --position;
            return old;
        }

        bool operator!=(const itertor right) const
        {return position != right.position;}
        bool operator==(const itertor right) const
        {return position == right.position;}

    protected:
        T* position;
    };
#endif

protected:
    // rightClose : true(default) ——>   theIndex < 0 && theIndex >= listSize
    // rightClose ：false   ——>  theIndex < 0 && theIndex >= listSize
    // 若索引theIndex无效，则抛出异常
    void checkIndex(int theIndex, bool rightClosed = true) const;
    T * element;  //储存线性表一维数组
    int arrayLength; //一维数组的容量
    int listSize; //线性表元素个数

};

template<class T>
arrayList<T>::arrayList(int initialCapacity) {
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;

}

template<class T>
arrayList<T>::arrayList(const arrayList<T> & theList) {
    // 复制构造函数
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element+listSize, element);
}

template<class T>
void arrayList<T>::checkIndex(int theIndex, bool rightClosed ) const {
    // Verify that theIndex is between 0 and listSize-1
    if(rightClosed){
        if(theIndex < 0 || theIndex >= listSize)
        {
            std::ostringstream s;
            s << "index = " << theIndex << " size = " << listSize;
            throw illegalIndex(s.str());
        }
    }
    else{
        if(theIndex < 0 || theIndex > listSize)
        {
            std::ostringstream s;
            s << "index = " << theIndex << " size = " << listSize;
            throw illegalIndex(s.str());
        }
    }

}

template<class T>
T &arrayList<T>::get(int theIndex) const {
    checkIndex(theIndex, false);
    return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T &theElement) const {
    //return index of first occurence of theElement;
    //return -1 if theElement not in list
    int theIndex = (int)(find(element, element + listSize, theElement) - element) ;
    //    int theIndex = (int)(find(element, element + listSize, theElement)-element);
    if (theIndex == listSize)
        return -1;
    else return theIndex;
}

template<class T>
void arrayList<T>::erase(int theIndex) {
    //Delete the element whose index is theIndex.
    //Throw illegal exception if no such element.
    checkIndex(theIndex);
    copy(element + theIndex + 1, element + listSize,
                                 element + theIndex);
    element[--listSize].~T();
}

template<class T>
void arrayList<T>::insert(int theIndex, const T &theElement) {
//    checkIndex(theIndex);
    if (theIndex < 0 || theIndex > listSize)
    {// invalid index
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    if (listSize == arrayLength)
    {
        changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }
    copy_backward(element + theIndex, element + listSize, element + listSize +1);
    element[theIndex] = theElement;
    listSize ++ ;
}

template<class T>
void arrayList<T>::output(ostream & out) const {
    copy(element, element + listSize, ostream_iterator<T>(cout, " "));
//    for (T a = itertor(element); a != end(element); a++)
//        out << * element << " ";
//    out << std::endl;
}


template<class T>
ostream &operator<<(ostream &out, const arrayList<T> & list) {
//    os << static_cast<const linearList<T> &>(list) << " element: " << list.element << " arrayLength: "
//       << list.arrayLength << " listSize: " << list.listSize;
//    return os;
    list.output(out);
    return out;
}
#endif //UNTITLED_ARRAYLIST_H


