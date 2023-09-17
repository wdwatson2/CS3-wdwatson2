#include <iostream>

using namespace std;

#define N 10000

bool quickfind(const int & p, const int & q, const int id[])
{
    return (id[p] == id[q]);
}


int main(){

    int i, p, q, t, id[N], height[N];

    //We initialize the ith array entry to i for 0 <= i < N
    for(i = 0; i< N; i++)
    {
        id[i] = i;
        height[i] = 0;
    }

    //This version is even more optimized.
    //same as quick_union,
    //but now we keep track of the size of the groups
    //and only union the smaller group to the larger group

    while(cin >> p >> q)
    {


        for (i = p; i != id[i]; i = id[i]);
        for (t = q; t != id[t]; t = id[t]);

        if (i == t)
            continue;


        if (height[i] = height[t])
        {
            id[t] = i;
            height[i] = height[i]+1; //height grows by one
        }
        else if (height[i] < height[t])
        {
            id[i] = t;
            //height of i group becomes height of t group
            height[i] = height[t];
        }
        else
        {
            id[t] = i;
            //height of t group becomes the height of i group
            height[t] = height[i];
        }
        
    
        cout << p << ' ' << q << endl;
    }

    return 0;
}