#include "quickunion.h"
#include <iostream>
#include <fstream>


using namespace std;


void processInstructions(ifstream& inst, int N, int M);

int main(){

    ifstream inst("input.txt");
    processInstructions(inst, 5, 6);



    return 0;
}

void processInstructions(ifstream& inst, int N, int M)
/*
N - Size of array
M - Number of instructions
*/
{
    char instruction;
    int num1, num2;

    Quickunion whatever(N);

    for(int i = 0; i < M; i++)
    {
        inst >> instruction;
        if (instruction == 'U' || instruction == 'u')
        {
            inst >> num1 >> num2;
            whatever.UnionGuy(num1, num2);
            cout << "Successful Union" << endl;
        }
        else //Must be query
        {
            inst >> num1;
            cout << "The size of the group that "<< num1 <<" is in is: "  << whatever.getSize(num1) << endl;
        }
    }
}