#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

int main(){

  ofstream outfile("Test.txt");

  outfile << "Buen dia!" << endl;

  outfile.close();

cout << remove("Test.txt") << endl;



  return 0;
}
