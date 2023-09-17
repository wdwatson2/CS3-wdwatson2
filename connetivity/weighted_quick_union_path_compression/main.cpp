#include <iostream>

using namespace std;

#define N 10000

bool quickfind(const int & p, const int & q, const int id[])
{
    return (id[p] == id[q]);
}


int main(){

    int i, p, q, t, id[N], sz[N];

    //We initialize the ith array entry to i for 0 <= i < N
    for(i = 0; i< N; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }

    //This version is even more optimized.
    //same as weighted quick union but with path compression by halving
    //path compression operates during find
    //everytime we are at a node,
    //we take it point to the same node as the node above it is pointing to
    

    while(cin >> p >> q)
    {


        for (i = p; i != id[i]; i = id[i])
            id[i] = id[id[i]];
        for (t = q; t != id[t]; t = id[t])
            id[t] = id[id[t]];

        if (i == t)
            continue;

        if (sz[i] < sz[t])
        {
            id[i] = t;
            sz[t] += sz[i];
        }
        else
        {
            id[t] = i;
            sz[i] += sz[t];
        }
        
    
        cout << p << ' ' << q << endl;
    }

    return 0;
}