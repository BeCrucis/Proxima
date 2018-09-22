#include <iostream>

using namespace std;

int main(){

int x1,x2,xt,xs;

cout << "Inserte su primer valor: ";
cin >> x1;

cout << "Inserte su segundo valor: ";
cin >> x2;

xt = x1 / x2;

xs = x1 % x2;

cout << "El total es de " << xt << "\n";
cout << "y el sobrante es de " << xs << "\n";

return 0;

}
