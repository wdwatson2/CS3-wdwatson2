#ifndef QUICKUNION_H
#define QUICKUNION_H


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

#endif