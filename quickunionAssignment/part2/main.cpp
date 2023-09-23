#include "quickunion.h"
#include <iostream>
#include <fstream>
#include <random> //create random list of operations

using namespace std;

void processInstructions(ifstream& inst, int N, int M);

int main(){
    //generating the random list of 50 instructions with an array of size 100
    int M = 50, N=100;
    fstream fileout;
    fileout.open("input.txt", ios::out);
    streambuf* stream_buffer_cerr = cerr.rdbuf();//redirecting cerr stream
    streambuf* stream_buffer_input = fileout.rdbuf(); //redirecting fileout stream

    //This may seem like a lot of work to generate random numbers but it ensures
    //that we are getting discrete, uniform random numbers on the interval 
    //(0, 99). mt19937 is a random integer generator, but to ensure that
    //the numbers we generate are uniform, we only use it to generate the seeds.
    //Sense we have two different operations, the first generated number is going to be
    //a number corresponding to the operation type (even->Query, odd->Union).

    random_device rd; //used to obtain a seed for mt19937 generator
    mt19937 gen(rd()); //generates psuedo random int
    uniform_int_distribution<> dis(0, N-1); //creating a discrete uniform distribution with range(0, 99) which corresponds to the indices of the list
    cerr.rdbuf(stream_buffer_input); //opening output file stream with cerr stream
    cerr << N << endl; //writing the size of the array
    cerr << M << endl; //writing the number of operations
    for (int n = 0; n < M; ++n)
    {
        int rando1 = dis(gen); //will be used to determine type of operation
        if(rando1%2==0) //if even
        {
            //Query operation
            int randoquery = dis(gen);
            cerr << "Q " << randoquery << endl;
        }
        else
        {
            //Union operation
            int randoUnion1 = dis(gen), randoUnion2 = dis(gen); //have to generate two numbers for this operation
            cerr << "U " << randoUnion1 << " " << randoUnion2 << endl;
        }
    }
    cerr.rdbuf(stream_buffer_cerr); //redirecting cerr back to its original stream
    fileout.close(); //closing the fileout stream

    // Reading in a file that contains some instructions to demonstrate the function
    ifstream inst("input.txt");

    //Actually calling the function
    processInstructions(inst, N, M);
    
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