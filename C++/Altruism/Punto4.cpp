#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

int main(){

    int lista[10];
    int numero;

    for(int i = 0; i < 10; i++){
        cout << "Inserte el numero ["<<i<<"] de la lista: ";
        cin >> lista[i];
    }
    
    // Obtener el menor de los numeros

    // Inicializa los contadores
    // Este almacena donde esta el numero mas bajo en la lista
    int posicionMenor = -1;
    // Este almacena cuanto vale dicho numero
    int numeroMenor = 999;
    // Se empieza con un valor muy alto, para que sea reemplazado en la primera iteracion del for de abajo

    // Esto recorre la lista y compara todos los numeros para encontrar el mas bajo uno por uno
    for(int i = 0; i < 10; i++){

        // Si el numero actual es mayor a 3 . . .
        if(lista[i] > 3){
            // Si el numero actual es mas bajo que el encontrado hasta ahora
            if(lista[i] < numeroMenor){
                // Ahora el numero actual sera el mas bajo
                numeroMenor = lista[i];
                posicionMenor = i;
            }
        }
        
    }

    // Obtener el mayor de los numeros

    // Inicializa los contadores
    // Este almacena donde esta el numero mas alto en la lista
    int posicionMayor = -1;
    // Este almacena cuanto vale dicho numero
    int numeroMayor = -999;
    // Se empieza con un valor muy bajo, para que sea reemplazado en la primera iteracion del for de abajo

    // Esto recorre la lista y compara todos los numeros para encontrar el mas alto uno por uno
    for(int i = 0; i < 10; i++){

        // Si el numero actual es mayor a 3 . . .
        if(lista[i] > 3){
            // Si el numero actual es mas alto que el encontrado hasta ahora
             if(lista[i] > numeroMayor){
                // Ahora el numero actual sera el mas alto
                numeroMayor = lista[i];
                posicionMayor = i;
            }
        }
        
    }

    cout << "El numero mayor que es mayor a 3 es: "<<numeroMayor<<" y estaba en la posicion ["<<posicionMayor<<"]"<< endl;
    cout << "El numero menor que es mayor a 3 es: "<<numeroMenor<<" y estaba en la posicion ["<<posicionMenor<<"]"<< endl;
    system("pause");
}