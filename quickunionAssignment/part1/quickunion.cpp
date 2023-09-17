#include "quickunion.h"
#include <iostream>

using namespace std;

/*
    public:
    //constructor *NEEDS PARAMETERS FOR ALL METHODS*
        Quickunion(int N);

    //destructor (destorys Id array when needed)
        ~Quickunion();

    //union operation
        void UnionGuy(int p, int q);

    //find operation
        void FindGuy(int p);

    //connected operation
        bool ConnectedGuy(int p, int q);

    private:
        int* Id;
*/


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
    // This is the find operation with path compression
    // Always connect p to q
    for (i = p; i != Id[i]; i = Id[i])
        Id[i] = Id[Id[i]];
    for (t = q; t != Id[t]; t = Id[t])
        Id[t] = Id[Id[t]];

    if (i == t)
    {
        cout << p << " and " << q << " are in the same component. Skipping Union operation." << endl;
    }
    else
    {
        Id[i] = t;
        Sz[t] += Sz[i];
        cout << "union operation was successful" << endl;
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
    return Sz[a];
}