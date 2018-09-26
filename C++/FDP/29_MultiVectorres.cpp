#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int main(){

    int y, n, i, a[100], b[100], c[100];

    cout << "Inserte el largo de los vectores: ";
    cin >> n;

    for(i = 1; i <= n ; ++i){
        cout << "Inserte el valor " << i << " de a: ";
        cin >> a[i];
        
    }

    for(i = 1; i <= n ; ++i){
        cout << setw(3) << a[i] << " "
        << setw(2) << " |";
        
    } 

    cout << endl;

    for(i = 1; i <= n ; ++i){
        cout << "Inserte el valor " << i << " de b: ";
        cin >> b[i];
        
    }
    
    for(i = 1; i <= n ; ++i){
        cout << setw(3) << b[i] << " "
        << setw(2) << " |";
        
    } 
    
    cout << endl;

    for(i = 1; i <= n ; ++i){
        
        c[i] = a[i]*b[i];
        
    } 

    cout << endl << endl << "Su vector resultado es: " << endl;
    for(i = 1; i <= n ; ++i){
        cout << setw(3) << c[i] << " "
        << setw(2) << " |";
        
    } 

    cout << endl;
    system("pause");


}   

