#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

using namespace std;

void printArray(int vec[], int size){

    cout << "[ ";

    for(int i = 0; i < size - 1; i++)
    {
        cout << vec[i] << " , ";
    }

    cout << vec[size - 1] << " ]" << endl;
}

int main(){

    int vec[10] = {};

    printArray(vec, 10);

    srand(time(NULL));

    for(int i = 0; i < 10; i++){

        vec[i] = rand()%9;
    }

    printArray(vec,10);

}