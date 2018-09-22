#include <iostream> //8919109wpg
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;

int main(){
  int m = 5, q = 10, d = 10, c = 30;
  int mv = 1000, qv = 500, dv = 200, cv = 100, tv;
  int in, inc, vf;
  bool f = false;
  tv = mv * m + qv * q + dv * d + cv * c;


  cout << "Inserte el cambio requerido: ";
  cin >> in;

  if(tv < in){
    vf = in - tv;
    cout << "No hay suficiente cambio en la maquina, faltan " << vf << " pesos" << endl << endl;
  f = true;

  }

  inc = in;
  int mc = 0, qc = 0, dc = 0, cc = 0;

  while(inc >= 1000 && m > 0){
    mc += 1;
    m -= 1;
    inc -= 1000;
  }
  while(inc >= 500 && q > 0){
    qc += 1;
    q -= 1;
    inc -= 500;
  }
  while(inc >= 200 && d > 0){
    dc += 1;
    d -= 1;
    inc -= 200;
  }
  while(inc >= 100 && c > 0){
    cc += 1;
    c -= 1;
    inc -= 100;
  }

  cout << "Su cambio es de: "
  << mc << " Monedas de 1000" << endl
  << qc << " Monedas de 500" << endl
  << dc << " Monedas de 200" << endl
  << cc << " Monedas de 100" << endl;

  if(f == true){
    cout << "Y faltan " << vf << " Pesos"<< endl;
  }

  return 0;
}
