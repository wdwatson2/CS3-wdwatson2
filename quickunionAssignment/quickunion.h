#ifndef QUICKUNION_H
#define QUICKUNION_H


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
        int FindGuy(int p);

    //connected operation
        bool ConnectedGuy(int p, int q);

    private:
        int* Id;
        int i,t;
};

#endif