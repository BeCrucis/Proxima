#include <iostream>
#include <windows.h>

using namespace std;

int main(){
  int A = 450;
  int B = 493;
  int C = 523;
  int D = 587;
  int E = 659;
  int F = 698;

  int TI = 450;

  Beep(A, 1);
  Beep(F, 1);
  Beep(B, TI);
  Beep(C, TI);
  Beep(D, TI);
  Beep(C, TI - 100);
  Beep(B, TI - 100);
  Beep(E, TI - 100);
  Beep(D, TI - 100);
  Beep(C, TI + 100);
  Beep(B, TI);
  Beep(C, TI);
  Beep(D, TI);
  Beep(1, TI + 100);
  Beep(E, TI + 100);
  Beep(D, TI + 200);
  Beep(1, TI);
  Beep(C, TI + 100);
  Beep(D, TI + 150);



}
