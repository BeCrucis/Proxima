import java.util.Scanner;

/*
Escribir un programa que permita el ingreso de un número natural n y que calcule n! exhibiendo el resultado. 
Por ejemplo: 5! = 5 x 4 x 3 x 2 = 120 
*/

class Taller_1_5{
  public static void main(String[] args) {
    
    Scanner sc = new Scanner(System.in);

    System.out.println("Bienvenido al factoriador de porodo!");
    System.out.println();

    System.out.printf("Inserte n: ");
    int n = sc.nextInt();

    double fact = 1;
    for(int i = 2; i <= n; i++){
       fact = fact * i;
    }

    System.out.println("El factorial de " + n + " es: " + fact);

    sc.close();
  }
}

