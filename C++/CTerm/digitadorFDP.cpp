#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

int main(){

    int N, X, sc, d, t, c, sum, r, di;

    cout << "Inserte N: ";
    cin >> N;

    for(int i = 1; i <= N; i++){

        sc = 0;
        sum = 0;

        cout << "Inserte X: ";
        cin >> X;

        while(X >= 10){
            
            d = X / 10;
            t = d * 10;
            c = X - t;
            sc = sc + c;
            X = d;
        } 

        sum = sc + X;

        r = 0;

        for(int i = 1; i <= sum; i++){

            di = sum % i;

            if(di == 0){
                r = r + 1;
            }
        }

        if (r == 2){
            cout << sum << " es primo!" << endl;
        } else {
            cout << sum << " no es primo!" << endl;
        }
    }

    system("pause");
    return 0;
}