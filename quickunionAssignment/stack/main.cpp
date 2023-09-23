#include "StackReSizeArray.h"
#include <iostream>

using namespace std;


int main()
{

    StackReSizeArray<char> guy1;

    guy1.push('g');

    cout << "G pushed success" << endl;

    guy1.push('u');

    cout << "u pushed success" << endl;

    cout << guy1.pop() << " SHOULD BE U" << endl;

    return 0;
}