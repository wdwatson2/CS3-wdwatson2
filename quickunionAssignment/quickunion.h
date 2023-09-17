#ifndef QUICKUNION_H
#define QUICKUNION_H

using namespace std;

class Quickunion
{
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

};

#endif