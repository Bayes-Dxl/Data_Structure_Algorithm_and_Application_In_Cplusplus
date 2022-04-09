//
// Created by Hxy on 2022/4/1.
//

#ifndef UNTITLED_CHAINNODE_H
#define UNTITLED_CHAINNODE_H
template<typename T>
struct chainNode
{
    T element;
    chainNode<T> * next;
    chainNode()= default;
    explicit chainNode(const T& element){this->element = element;}
    chainNode(const T& element, chainNode<T>* next)
    {
        this->element = element;
        this->next = next;
    }
};

#endif //UNTITLED_CHAINNODE_H
