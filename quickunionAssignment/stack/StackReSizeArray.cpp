#include "StackReSizeArray.h"
#include <iostream>
#include <math.h>

using namespace std;

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
    T temp = s[N];
    s[N] = NULL;
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

