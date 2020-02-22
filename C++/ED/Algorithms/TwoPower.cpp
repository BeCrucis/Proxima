#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

int powerA(int n){
    if (n < 0){
        return -1;
    }

    if (n == 0){
        return 1;
    }

    return powerA(n-1)*2;
}

int powerB(int n){
    if (n < 0){
        return -1;
    }

    if (n == 0){
        return 1;
    }

    return powerB(n-1) + powerB(n-1);
}

int main(){

    int n = 10;

    cout << "2 elevado a " << n << " es: " << powerB(n) << endl;
    system("pause");
}