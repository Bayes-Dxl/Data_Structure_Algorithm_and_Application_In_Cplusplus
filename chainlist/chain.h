#ifndef _CHAIN_H
#define _CHAIN_H
#include "../arraylist/linearList.h"
#include "../arraylist/myExceptions.h"
#include "chainNode.h"
#include <algorithm>
#include <sstream>

#define CHAIN_ITERATOR

template<typename T>
class  chain : public linearList<T>
{
public:
    chain(int initialCapacity = 10);
    chain(chain<T>&);
    ~chain();

    bool empty() const    {return listSize == 0;}
    // return true iff list is empty
    int size()  const     {return listSize;}
    // return number of elements in list
    T& get (int theIndex) const;
    // return element whose index is theIndex
    int indexOf(const T& theElement) const;
    // return index of first occurence of theElement
    void erase(int theIndex) ;
    // remove the element whose index is theIndex
    void insert(int theIndex, const T& theElement);
    // insert theElement so that its index is theIndex
    void output(ostream& out) const;
    // insert list into stream out

    #ifdef CHAIN_ITERATOR
    class iterator;
    iterator begin() {return iterator(firstNode);}
    iterator end() {return iterator(NULL);}
    class iterator
    {
    public:
        typedef forward_iterator_tag iterator_categort;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;

        // construct
        iterator(chainNode<T>* theNode=NULL):node(theNode){}

        // dereference operators
        T& operator*() const  {return node->element;}
        T* operator->() const {return &node->element;}

        // increment
        iterator& operator++() //preincrement
        {
            node = node->next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator old = *this;
            node = node->next;
            return old;
        }

        //equality testing

        bool operator!=(const iterator right) const
        { return node != right.node; }
        bool operator==(const iterator right) const
        { return node == right.node; }
    protected:
        chainNode<T>* node;
    };
    #endif  // CHAIN_ITERATOR

protected:
    void checkIndex(int theIndex) const; //如果索引无效，则抛出异常
    chainNode<T>  *firstNode;             //指向链表的第一个元素
    int listSize;
};

template <typename T>
chain<T>::chain(int initialCapacity)
{
    if(initialCapacity<1)
    {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode = NULL;
    listSize = 0;
}

template<typename T>
chain<T>::chain(chain<T> & theList)
{
    listSize = theList.listSize;
    if(listSize == 0)
    {
        firstNode = NULL;
        return;
    }

    // 赋值theList的节点：firstNode （链表头节点）
    chainNode<T> *sourceNode = theList.firstNode;
    firstNode = new chainNode<T>(sourceNode->element);
    sourceNode = sourceNode->next;
    // firstNode是链表头， 用targetNode遍历整个链表（theList）。
    chainNode<T>* targetNode = firstNode;
    while(sourceNode != NULL)
    {
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL; // 链表结束
}

template<typename T>   // 重复删除链表首元素，知道链表为空，（要用临时变量先保存第二个元素节点的指针）
chain<T>::~chain() {
    while(firstNode != 0)
    {
        chainNode<T> * nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<typename T>  // 返回初次找到的索引，否则返回 -1；
int chain<T>::indexOf(const T &theElement) const
{
    chainNode<T> * currentNode = firstNode;
    int index{};
    while (currentNode != NULL && currentNode->element != theElement)
    {
        currentNode = currentNode->next;
        index++;
    }
    if(currentNode==NULL)
        return  -1;
    else
        return index;
}

template<typename T>
T& chain<T>::get(int theIndex) const
{
    // 先检查theIndex 不存在则抛出异常
    checkIndex(theIndex);
    chainNode<T> * currentNode = firstNode;
    for(int index{}; index !=theIndex; index++)
        currentNode = currentNode->next;
    return currentNode->element;
}

template<typename T>
void chain<T>::checkIndex(int theIndex) const {
    if(theIndex < 0 || theIndex > listSize)
    {
        ostringstream s;
        s << "illegal index!  the index is " << theIndex
          << " must be > 0 and < "           << listSize;
        illegalParameterValue(s.str());
    }
}

template<typename T>
void chain<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    chainNode<T> * deleteNode;
    if(theIndex == 0)
    {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else
    {
        chainNode<T>* p = firstNode;
        for(int index{}; index < theIndex -1; index++)
            p = p->next;
        deleteNode = p->next;
        p->next = p->next->next;
    }
    delete deleteNode;
    listSize--;

}

// 在theIndex位置插入元素theElement
template<typename T>
void chain<T>::insert(int theIndex, const T &theElement)
{
    checkIndex(theIndex);
    // 找到theIndex的前一个节点。先判断是否在头部插入
    if(0==theIndex)
        firstNode = new chainNode<T>(theElement, firstNode);
    else
    {
        chainNode<T> *p = firstNode;
        for(int index{}; index < theIndex-1; ++ index)
            p = p->next;
        p->next = new chainNode<T>(theElement, p->next);
    }
    listSize++;
}

template<typename T>
void chain<T>::output(ostream& out) const
{
    for(auto *p = firstNode; p != NULL; p = p->next)
        out << p->element << " ";
}

template<typename T>
ostream& operator<<(ostream& out, const chain<T>& x)
{
    x.output(out);
    return out;
}

#endif //_CHAIN_H

