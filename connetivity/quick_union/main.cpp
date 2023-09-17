#include <iostream>

using namespace std;

#define N 10000

bool quickfind(const int & p, const int & q, const int id[])
{
    return (id[p] == id[q]);
}


int main(){

    int i, p, q, t, id[N];

    //We initialize the ith array entry to i for 0 <= i < N
    for(i = 0; i< N; i++)
        id[i] = i;

    //While reading in two numbers seperated by space

    //This version is slghlty more optimized.
    //find is now slower because when checking if they are part of the same group,
    //you must climb the pointers until you reach the root or the object that points to itself
    //the root is the representative and then like the previous, if the representative of both objects
    //is the same then they are in the same group
    //otherwise to union unconnected groups,
    //we can just have the reprentaive of p point to the representaive of q connceting p and q's groups.

    while(cin >> p >> q)
    {


        for (i = p; i != id[i]; i = id[i]);
        for (t = q; t != id[t]; t = id[t]);
        if (i == t)
            continue;
        id[i] = t;
    
        cout << p << ' ' << q << endl;
    }

    return 0;
}