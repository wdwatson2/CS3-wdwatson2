#ifndef QUEUE_H
#define QUEUE_H

#include <math.h>

using namespace std;

template<typename T>
class QueueReSizeArray
{
private:
    T* s;
    int N=0, capacity;
public:
    QueueReSizeArray();
    void push(T item);
    T pop();
protected:
    void resize(int newCapcity);
};


template<typename T>
QueueReSizeArray<T>::QueueReSizeArray(): capacity(1)
{
    s = new T[capacity];
    if(s == 0)
        exit(1);
}

template<typename T>
void QueueReSizeArray<T>::push(T item)
{
    if(N==capacity)
    {
        resize(2*capacity);
    }
    s[N++]=item;
}

template<typename T>
T QueueReSizeArray<T>::pop() //THIS IS THE ONLY DIFFERENCE BETWEEN STACK AND QUEUE
{
    if(N == round(.25*capacity))
    {
        resize(round(.5*capacity));
    }
    
    T temp = s[0];
    T* copy = new T[capacity];
    if(copy == 0)
        exit(1);
    
    for(int i=0; i<N;i++)
    {
        copy[i] = s[i+1];
    }
    delete[] s;
    s = copy;
    N = N-1;
    return temp;
}

template<typename T>
void QueueReSizeArray<T>::resize(int newCapacity)
{
    T* copy = new T[newCapacity];
    if(copy == 0)
        exit(1);
    
    for(int i=0; i<N;i++)
    {
        copy[i] = s[i];
    }
    delete[] s;
    s = copy;
    capacity = newCapacity;
}



#endif
