#include "quickunion.h"
#include <iostream>

using namespace std;

int main(){

    Quickunion test(10000);
    cout << "inst worked" << endl;

    cout << "Finding the root node of p=0 should be zero: " << test.FindGuy(4) << endl;

    cout << "Size of the group that 1 is in (1): " << test.getSize(1) << endl;

    cout << "Is p=0 and q=1 connected (should be false (0)): " << test.ConnectedGuy(1,0) << endl;

    cout << "Union p=1 and q=0 together: " << endl;
    test.UnionGuy(0, 1);

    cout << "Is p=0 and q=1 connected (should be true (1)): " << test.ConnectedGuy(1,0) << endl;

    test.UnionGuy(9, 0);
    cout << "Is p=9 and q=1 connected (should be true (1)): " << test.ConnectedGuy(9,1) << endl;

    cout << "Size of the group that 1 is in (3): " << test.getSize(1) << endl;
    return 0;
}
