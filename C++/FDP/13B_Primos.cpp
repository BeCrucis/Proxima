#include <iostream> //8919109wpg
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;

long long fact(int n){ // Esto es una funcion que obtiene el factorial de un numero

  if(n == 0){
    return 1;
  }
  else{
    return n * fact(n-1);
  }
}

bool PRIMOS(int x){
    
    int di = 0;

    for(int i = 1; i <= x; ++i){

        if(x % i == 0){
            di += 1;
        }
    }

    if(di == 2){
        return true;
    }

    else{
        return false;
    }
}

long double SUMA(int x){

    double s = 0;
    int signo = 1;

    for(int i = 0; i <= 20; i = i + 2){

        s = s + signo * ((pow(x,i)/fact(i))); 
        signo *= -1;
    }

    return s;
}

int main(){

    int n;

    cout << "Inserte la cantidad de valores que va a insertar: ";
    cin >> n; 

    int x[n+1];

    for(int i = 1; i <= n; ++i){
        cout << "Inserte la variable [" << i << "]: ";
        cin >> x[i];
    }

    for( int i = 1; i <= n; ++i){
        if(PRIMOS(x[i]) == true){
            cout << SUMA(x[i]) << endl;
            
        }
    }

    return 0;
}