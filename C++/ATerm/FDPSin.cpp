#include <iostream>
#include <math.h>
#include <windows.h>
#include <iomanip>

using namespace std;

long long fact(int n){ // Esto es una funcion que obtiene el factorial de un numero

  if(n == 0){
    return 1;
  }
  else{
    return n * fact(n-1);
  }
}


int main(){

  int d = 1, e = 1, signo = 1;
  long double x, sx, cx;

  cout << left << setw(10) << "Angulo"
  << left << setw(15) << "Seno"
  << left << setw(15) << "Coseno"
  << left << setw(15) << "Tangente"
  << left << setw(15) << "Cotangente"
  << left << setw(15) << "Secante"
  << left << setw(15) << "Cosecante"
  << endl;

  for(x = 5; x <= 85; x = x + 1){

    long double rad = x * 3.1416 / 180;
    sx = 0;
    cx = 0;
    d = 1;
    e = 1;
    signo = 1;



    for( int i = 1 ; i <= 20 ; ++i ){
      sx = sx + signo * (pow(rad,e)/fact(d)); //Esto obtiene el seno de x
      cx = cx + signo * (pow(rad,e-1)/fact(d-1)); // Esto obtiene el coseno de x
      signo *= -1;
      d += 2;
      e += 2;
    }

    cout << left << setw(10) << x
    << left << setw(15) << sx
    << left << setw(15) << cx
    << left << setw(15) << sx/cx
    << left << setw(15) << cx/sx
    << left << setw(15) << 1/cx
    << left << setw(15) << 1/sx
    << endl;

  }

  _getwch();
  return 0;
  }
