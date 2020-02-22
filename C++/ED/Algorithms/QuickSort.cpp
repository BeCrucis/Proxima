#include <iostream>

using namespace std;

void quickSort(int V[], int inicio, int fin){

    int pivote, izq, der, temp;
    pivote = V[inicio];
    izq = inicio+1;
    der = fin;

    if(inicio >= fin) return;

    while (izq <= der){

        while(izq <= fin && V[izq] < pivote) izq++;
        while(der > inicio && V[der] >= pivote) der--;

        if(izq < der){
            temp = V[izq];
            V[izq] = V[der];
            V[der] = temp;
            izq++;
            der--;
        }
    }

    if(der > inicio){
        temp = V[inicio];
        V[inicio] = V[der];
        V[der] = temp;
    }

    quickSort(V, inicio, der-1);
    quickSort(V, der+1, fin);
}

int main(){

    int V[100], n, i;
    cout << "Inserte numero de elementos del vector: ";
    cin >> n;

    for(i = 0; i < n; i++){
        cout << "Inserte V["<<i<<"]: ";
        cin >> V[i];
    }

    quickSort(V, 0, n-1);

    cout << "El vector ordenado es: " << endl;

    for(i = 0; i < n; i++) cout << V[i] << " ";
    cout << endl;

    system("pause");
}