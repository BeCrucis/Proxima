#include <iostream>
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

void mostrar(int c[], int lc){
  for(int i = 0; i < lc; ++i){

    cout << setw(3) << c[i];
  }
  cout << endl;
}

void sort(int c[], int l, int m, int h){

  int t[100], lc, p, hc;

  lc = l;
  p = l;
  hc = m + 1;

  while(lc <= m && hc <= h){

    if(c[lc] < c[hc]){

      t[p] = c[lc];

      ++lc;
      ++p;
    }

    else {

      t[p] = c[hc];

      ++hc;
      ++p;
    }
  }

  while(lc <= m){

    t[p] = c[lc];
    lc++;
    p++;
  }

  while(hc <= h){

    t[p] = c[hc];
    hc++;
    p++;
  }

  mostrar(t, p);
}

void merge(int c[], int l, int h){

  if(l < h){
    int mid = (l + h)/2;
    cout << "Mid es: " << mid << endl;

    merge(c, l, mid);

    merge(c, mid + 1, h);

    sort(c, l, mid, h);
  }

  return;

}


int main(){

  int lx;

  cout << "Inserte la cantidad de elementos: ";
  cin >> lx;
  cout << endl;

  int x[lx];
  int l = 0, h = lx - 1;
  for(int i = 0; i < lx; ++i){
    cout << "Inserte el numero [" << i + 1 <<"]: ";
    cin >> x[i];
  }

  merge(x, l, h);


}
