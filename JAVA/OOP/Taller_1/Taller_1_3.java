import java.util.Scanner;
/*
Los usuarios de una página web, al momento de registrarse, se les pide registrar también una 
clave numérica para poder ingresar posteriormente a la página. La clave de acceso debe tener 
exactamente tres cifras. Hacer un programa que valide que la clave que teclea el usuario 
realmente tenga tres cifras, si el número tecleado no es de tres cifras marcar el error y 
volver a pedirlo hasta que tenga tres cifras. 
*/
class Main {
  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    Boolean foundPassword = false;
    
    while(!foundPassword){

      System.out.printf("Inserte su contraseña: ");
      String password = sc.nextLine();

      //Verifico que la contraseña consista en 3 caracteres
      if(password.length() != 3){
        System.out.println("ERROR: La contraseña debe ser de 3 caracteres");
      } else {
        foundPassword = true;
      }

      //Ahora verifico si la contraseña es numerica
      try{
      Integer.parseInt(password);
      }

      catch (Exception e){
      System.out.println("ERROR: La contraseña debe ser numerica");
      foundPassword = false;
      }

      if(foundPassword){
        System.out.println("Contraseña aceptada!");
      }
    }  
  }
}
