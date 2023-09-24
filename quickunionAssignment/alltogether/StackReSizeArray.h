#ifndef STACK_H
#define STACK_H

#include <math.h>

using namespace std;

template<typename T>
class StackReSizeArray
{
private:
    T* s;
    int N=0, capacity;
public:
    StackReSizeArray();
    void push(T item);
    T pop();
protected:
    void resize(int newCapcity);
};


template<typename T>
StackReSizeArray<T>::StackReSizeArray(): capacity(1)
{
    s = new T[capacity];
    if(s == 0)
        exit(1);
}

template<typename T>
void StackReSizeArray<T>::push(T item)
{
    if(N==capacity)
    {
        resize(2*capacity);
    }
    s[N++]=item;
}

template<typename T>
T StackReSizeArray<T>::pop()
{
    if(N == round(.25*capacity))
    {
        resize(round(.5*capacity));
    }
    T temp = s[N-1];
    N = N-1;
    return temp;
}

template<typename T>
void StackReSizeArray<T>::resize(int newCapacity)
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
