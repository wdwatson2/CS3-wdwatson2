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
    while(cin >> p >> q)
    {
        if (quickfind(p, q, id)) //find 
            continue;
        
        //union operation is applied if the two objects are not connected
        //We iterate over the array looking for entries that have the same value as the one at p
        //if we hit an entry with the same value as what is at p, then we change its value to what is at q
        //After exausting the search, we print p and q to indicate that a new connection was made

        //another way to look at is the indexes of p and q are the objects themselves
        //the int that the objects point to is the representative of their group
        //initially everyone points to themselves, meaning everyone is the representative of themselves
        //find figures out if two objects are connected if by checking if they point to the same representative
        //if they do not, then they are not connected and the union operation can be applied
        //this union operation is slow because it searches the entire array each time it is called
        //the representaive of p is t, and it checks every objects representative.
        //if another object has the same representative as p, then that object now points to the representative of q
        //basically taking that object and connecting it to group that q is
        for(t = id[p], i=0; i<N; i++) //union
        {
            if (id[i] == t)
                id[i] = id[q];
        }
        cout << p << ' ' << q << endl;
    }

    return 0;
}