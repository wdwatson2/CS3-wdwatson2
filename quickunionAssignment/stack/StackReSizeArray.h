#ifndef STACK_H
#define STACK_H

template<typename T>
class StackReSizeArray
{
private:
    T* s;
    int N, capacity;
public:
    StackReSizeArray();
    void push(T item);
    T pop();
protected:
    void resize(int newCapcity);
};

#endif
