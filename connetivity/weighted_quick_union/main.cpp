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
    //same as quick_union,
    //but now we keep track of the size of the groups
    //and only union the smaller group to the larger group

    while(cin >> p >> q)
    {


        for (i = p; i != id[i]; i = id[i])
            cout << "accessed array 1" << endl;
        for (t = q; t != id[t]; t = id[t])
            cout << "accessed array 2" << endl;

        if (i == t)
            continue;

        if (sz[i] < sz[t])
        {
            id[i] = t;
            cout << "accessed array 3" << endl;
            sz[t] += sz[i];
        }
        else
        {
            id[t] = i;
            cout << "accessed array 4" << endl;
            sz[i] += sz[t];
        }
        
    
        cout << p << ' ' << q << endl;
    }

    return 0;
}