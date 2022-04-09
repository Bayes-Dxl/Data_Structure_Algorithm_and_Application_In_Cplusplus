//
// Created by Hxy on 2022/3/22.
//



// exception classes for various error types

#ifndef myExceptions_H
#define myExceptions_H
#include <string>
#include <utility>

using namespace std;

// illegal parameter value
class  illegalParameterValue
{
public:
    explicit illegalParameterValue(string theMessage = "Illegal parameter value")
    {message = std::move(theMessage);}
    void outputMessage() {cout << message << endl;}
private:
    string message;
};

// illegal input data
class illegalInputData
{
public:
    explicit illegalInputData(string theMessage = "Illegal data input")
    {message = std::move(theMessage);}
    void outputMessage() {cout << message << endl;}
private:
    string message;
};

// illegal index
class illegalIndex
{
public:
    explicit illegalIndex(string theMessage = "Illegal index")
    {message = std::move(theMessage);}
    void outputMessage() {cout << message << endl;}
private:
    string message;
};

// matrix index out of bounds
class matrixIndexOutOfBounds
{
public:
    explicit matrixIndexOutOfBounds
            (string theMessage = "Matrix index out of bounds")
    {message = std::move(theMessage);}
    void outputMessage() {cout << message << endl;}
private:
    string message;
};

// matrix size mismatch
class matrixSizeMismatch
{
public:
    explicit matrixSizeMismatch(string theMessage =
    "The size of the two matrics doesn't match")
    {message = std::move(theMessage);}
    void outputMessage() {cout << message << endl;}
private:
    string message;
};

// stack is empty
class stackEmpty
{
public:
    explicit stackEmpty(string theMessage =
    "Invalid operation on empty stack")
    {message = std::move(theMessage);}
    void outputMessage() {cout << message << endl;}
private:
    string message;
};

// queue is empty
class queueEmpty
{
public:
    explicit queueEmpty(string theMessage =
    "Invalid operation on empty queue")
    {message = std::move(theMessage);}
    void outputMessage() {cout << message << endl;}
private:
    string message;
};

// hash table is full
class hashTableFull
{
public:
    explicit hashTableFull(string theMessage =
    "The hash table is full")
    {message = std::move(theMessage);}
    void outputMessage() {cout << message << endl;}
private:
    string message;
};

// edge weight undefined
class undefinedEdgeWeight
{
public:
    explicit undefinedEdgeWeight(string theMessage =
    "No edge weights defined")
    {message = std::move(theMessage);}
    void outputMessage() {cout << message << endl;}
private:
    string message;
};

// method undefined
class undefinedMethod
{
public:
    explicit undefinedMethod(string theMessage =
    "This method is undefined")
    {message = std::move(theMessage);}
    void outputMessage() {cout << message << endl;}
private:
    string message;
};
#endif
