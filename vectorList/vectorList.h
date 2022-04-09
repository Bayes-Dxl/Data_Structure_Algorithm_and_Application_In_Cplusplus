//
// Created by Hxy on 2022/3/25.
//

#ifndef UNTITLED_VECTORLIST_H
#define UNTITLED_VECTORLIST_H

#include "../arraylist/linearList.h"
#include "../arraylist/myExceptions.h"
#include <vector>
#include <sstream>





template <typename T>
class vectorList : public linearList<T>
{
public:
    explicit vectorList(int initialCapactity = 10);
    vectorList(const vectorList<T> &);
    ~vectorList(){delete element;}

    //ADT
    [[nodiscard]] bool empty() const {return element->empty();}
    [[nodiscard]] int size() const {return (int) element->size();}
    T & get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;
    void half();
    void half_1();
    void meld( vectorList<T>  & a,  vectorList<T>  & b);  // vectorList交叉合并

    int capacity() const {return (int)element->capacity();}

    typedef typename std::vector<T>::iterator iterator;
    iterator begin() {return element->begin();}
    iterator end() {return element->end();}

protected:
    void  checkIndex(int theIndex) const;
    vector <T>* element;


};
template<class T>
vectorList<T>::vectorList(int initialCapactity)
{
    if (initialCapactity < 1)
    {
        ostringstream  s;
        s << "Initial capacity = " << initialCapactity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    element = new vector<T>;
    element->reserve(initialCapactity);
}

template <typename T>
vectorList<T>::vectorList(const vectorList<T> & theList)
{
    element = new vector<T>(*theList.element);
}

template <typename T>
void vectorList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    element->erase(begin()+theIndex);

}

template<typename T>
void vectorList<T>::insert(int theIndex, const T& theElement)
{
    if(theIndex<0 || theIndex > size())
    {
        ostringstream  s;
        s << "index = " << theIndex << " size = " << size();
        throw illegalIndex(s.str());
    }
    element->insert(element->begin() + theIndex, theElement);


}

template<typename T>
void vectorList<T>::half()
{
//    if(empty())
//        return ;
//    for (int i = 1; i < size(); i = i+1)
//    {
//        erase(i);
//    }


//    element->erase(remove_if(element->begin(),element->end(),[](int i){return i%2 == 0;}),element->end())  ;
    vector<T> temp;
    cout << endl << " ------------------" << endl;
    for(auto i = 0; i < size(); i = i + 3)
    {
        temp.emplace_back(element->at(i));
        cout << element->at(i) << " ";
    }
    cout << endl << " ------------------" << endl;
    *element=temp;
}


template<typename T>
void vectorList<T>::half_1()
{

    vector<T> temp;
    cout << endl << " ------------------" << endl;
    for(auto i = 0; i < size(); i = i + 3)
    {
        temp.emplace_back(get(i));
        cout << element->at(i) << " ";
    }
    cout << endl << " ------------------" << endl;
    *element=temp;
}


template<typename T>
T &vectorList<T>::get(int theIndex) const {
    return element->at(theIndex);
}

template<typename T>
void vectorList<T>::output(ostream &out) const {
    copy(element->begin(), element->end(), ostream_iterator<T>(cout," "));
}

template <class T>
ostream & operator <<(ostream& out,  const vectorList<T>& x){
    x.output(out);
    return out;
}

template<typename T>
int vectorList<T>::indexOf(const T &theElement) const {
    int theIndex = (int)(find(element->begin(), element->end(), theElement) - element->begin()) ;
//        int theIndex = (int)(find(element, element + listSize, theElement)-element);
    if (theIndex == size())
        return -1;
    return theIndex;
}

template<typename T>
void vectorList<T>::checkIndex(int theIndex) const {

}

template<class T>
void vectorList<T>::meld(  vectorList<T> & a,   vectorList<T> & b) {
    /*******
    if(a.size()>b.size())
    {
        int i = 0;
        element->clear();
        for( i = 0; i < b.size(); i++ )
        {
            element->emplace_back(b.get(i));
            element->emplace_back(a.get(i));
        }
        copy_backward(a.element->begin()+i, a.end(), element->end());
        for(; i < a.size(); i++)
            element->emplace_back(a.element->at(i));  // 可行
    }
     *******/

    int i = 0;        auto j = 0;
    element->resize(a.size()+b.size());
    if(a.size()>b.size())
    {
        for( ; i < b.size(); i++ )
        {
            element->at(j++) = b.get(i);
            element->at(j++) = a.get(i);
        }
        copy(a.element->begin()+i, a.end(), element->begin()+2*i);
       // copy(a.element->begin()+i, a.end(), element->begin()+2*i);
    }
    else{
        for( ; i < a.size(); i++ )
        {
            element->at(j++) = b.get(i);
            element->at(j++) = a.get(i);
        }
        copy(b.element->begin()+i, b.end(), element->begin()+2*i);
    }    //  todo 可以新增swap方法，这里不适合用swap减少代码，否则 a, b发生改变  2022/3/31 20:14 待处理






}




#endif //UNTITLED_VECTORLIST_H
