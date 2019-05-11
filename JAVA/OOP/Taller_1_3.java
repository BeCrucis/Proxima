import java.util.Scanner;

/*
Los usuarios de una página web, al momento de registrarse, se les pide registrar también una 
clave numérica para poder ingresar posteriormente a la página. La clave de acceso debe tener 
exactamente tres cifras. Hacer un programa que valide que la clave que teclea el usuario 
realmente tenga tres cifras, si el número tecleado no es de tres cifras marcar el error y 
volver a pedirlo hasta que tenga tres cifras. 
*/

class Taller_1_3{
  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    int password = 0;

    System.out.println("Bienvenido al passwords inseguras de porodo!");
    System.out.println();

    while(password < 99 || password > 999){

      System.out.printf("Inserte su password de 3 cifras: ");
      password = sc.nextInt();

      if(password < 99 || password > 999){
      System.out.println("ERROR: La password debe ser de 3 cifras");

      } else {
        System.out.println("password aceptada!");

        break;
      }
    }
    sc.close();
  }
}