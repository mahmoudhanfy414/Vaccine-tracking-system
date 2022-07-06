#include "queueArr.h"
template<class T>
queueArr<T>::queueArr()
{
    size = 50;
    count = 0;
    front = back = -1;
    arr = new T[size];
}
template<class T>
int queueArr<T>::length()
{
    return count;
}
template<class T>
void queueArr<T>::push(T x)
{
    if (count == size)
    {
      expand();
    }
    if (front == -1)
        front = 0;
    back = (back + 1) % size;
    arr[back] = x;
    count++;
}
template<class T>
void queueArr<T>::pop()
{
    front = (front + 1) % size;
    count--;
    if (count == 0)
        front = back = -1;
}
template<class T>
T queueArr<T>::Front()
{
    return arr[front + (front == -1)];
}
template<class T>
bool queueArr<T>::empty()
{
    return (count == 0);
}
template<class T>
void queueArr<T>::expand()
{
    size = size * 2;
    T *a = new T[size];
    for (int i = 0; i < count; i++)
    {
        a[i] = arr[i];
    }
    delete[]arr;
    arr = a;
}
template <class T>
queueArr<T>::~queueArr()
{

}