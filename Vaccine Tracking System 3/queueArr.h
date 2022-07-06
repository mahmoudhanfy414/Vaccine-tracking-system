#pragma once
using namespace std;
template <class T>
class queueArr
{
    T* arr;
    int count, size;
    int front, back;
public:
    queueArr();
    int length();
    void push(T value);
    void pop();
    bool empty();
    T Front();
    void expand();
    ~queueArr();
};