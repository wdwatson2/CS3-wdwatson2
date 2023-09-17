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
    Id = new int[N];
    if(Id == 0)
        exit(1);
}

// Destructor
Quickunion::~Quickunion()
{
    delete[] Id;
}

// Union operation
void Quickunion::UnionGuy(int p, int q)
{
    
}