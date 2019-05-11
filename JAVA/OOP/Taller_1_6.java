import java.util.Scanner;

/*
Lo mismo pero para la sucesión de Fibonacci.Por ejemplo: Serie Fibonacci de 7 = 1, 1, 2, 3, 5, 8, 13 
(Es decir la sucesión tiene 7 números). Contar los números enteros positivos introducidos por teclado. 
El algoritmo debe terminar cuando selea un número negativo o cero.
 */

public class Taller_1_6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.printf("Inserte cuantos numeros de fibonacci desea: ");
        int fibbCounter = sc.nextInt();

        sc.close();

        if (fibbCounter <= 0) {
            return;
        }

        long X1 = 0;
        long X2 = 1;
        long temp;

        for (int i = 0; i < fibbCounter; i++) {

            System.out.println(X2);

            temp = X2; //Almaceno el X3 antiguo (X2 en este instante)
            X2 = X2 + X1; //Aplico la sucecion X3 = X2 + X1
            X1 = temp; //Asigno el antiguo valor de X3 a la variable de manera que X1 = X2
        }   
       
    }
}