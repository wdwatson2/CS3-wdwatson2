#ifndef QUICKUNION_H
#define QUICKUNION_H

#include <iostream>
using namespace std;

class Quickunion
{
    public:
    //constructor
        Quickunion(int N);

    //destructor (destroys Id array when needed)
        ~Quickunion();

    //union operation
        void UnionGuy(int p, int q);

    //find operation
        int FindGuy(int p);

    //connected operation
        bool ConnectedGuy(int p, int q);

    // Get size of the group that a is in 
        int getSize(int a);

    private:
        int* Id;
        int* Sz;
        int i,t;
};

// Constructor for initiallizing Id array
Quickunion::Quickunion(int N)
{
    int temp;

    Id = new int[N];
    if(Id == 0)
        exit(1);

    Sz = new int[N];
    if(Sz == 0)
        exit(1);

    for(temp = 0; temp< N; temp++)
    {
        Id[temp] = temp;
        Sz[temp] = 1;
    }
}

// Destructor
Quickunion::~Quickunion()
{
    delete[] Id;
}

// Union operation
void Quickunion::UnionGuy(int p, int q)
{
    // int temp;
    // This is the find operation with path compression by halving
    for (i = p; i != Id[i]; i = Id[i])
        Id[i] = Id[Id[i]];
    for (t = q; t != Id[t]; t = Id[t])
        Id[t] = Id[Id[t]];

    if (i == t)
    {
    }
    //Weighted quick-union     
    if (Sz[i] < Sz[t])
    {
        Id[i] = t;
        Sz[t] += Sz[i];
    }
    else
    {
        Id[t] = i;
        Sz[i] += Sz[t];
    }
}

// Find operation determines the root of p
int Quickunion::FindGuy(int p)
{
    for (i = p; i != Id[i]; i = Id[i])
    {
    }

    return i;
}

// Connected operation determines if p and q are connected
bool Quickunion::ConnectedGuy(int p, int q)
{
    for (i = p; i != Id[i]; i = Id[i])
    {
    }
    for (t = q; t != Id[t]; t = Id[t])
    {
    }

    if (i == t)
        return true;

    return false;  
}

int Quickunion::getSize(int a)
{
    // Climbing to the root of the group
    for (i = a; i != Id[i]; i = Id[i])
    {
    }
    return Sz[i];
}

#endif