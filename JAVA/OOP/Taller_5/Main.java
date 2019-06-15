import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

class Main {

  public static void main(String[] args) {

    Libreria libr = null;
    ArrayList<Autor> autores = new ArrayList<Autor>();
    ArrayList<CasaPublicacion> casas = new ArrayList<CasaPublicacion>();
    int option = 0;

    while(true){

    System.out.println("Bienvenido a la Biblioteca virtual!");
    System.out.println("A continuacion escoja la opcion que desea realizar");
    
    System.out.println("1. Crear libreria");
    System.out.println("2. Crear estanteria");
    System.out.println("3. Crear casa de publicacion");
    System.out.println("4. Crear autor");
    System.out.println("5. Crear libro");
    System.out.println("6. Crear capitulo");
    System.out.println("7. Listar libros de autor");
    System.out.println("8. Listar libros de casa editorial");
    System.out.println("9. Buscar autor");
    System.out.println("99. Salir del programa");
    System.out.println();
    System.out.print("Inserte su opcion: ");

    Scanner sc = new Scanner(System.in);

    try {
      
      option = Integer.parseInt(sc.nextLine());
    }
    catch (Exception ex) {
      continue;
    }
    
    if(option == 1){ //Crear libreria

     System.out.print("Inserte el nombre de la libreria: ");
     String nomLibreria = sc.nextLine();
     
     System.out.print("Inserte el id de la libreria: ");
     int idLibreria = Integer.parseInt(sc.nextLine());
     
     libr = new Libreria(idLibreria, nomLibreria);

     System.out.println();
     System.out.println("Libreria creada, Enter para continuar");
     sc.nextLine();

    }
 
    if (option == 2) { //Crear estanteria dentro de la libreria

      if(libr == null){
        clearScreen();  
        continue;
      }

      System.out.print("Inserte el ID de la estanteria: ");
      int idEstanteria = Integer.parseInt(sc.nextLine());

      System.out.print("Inserte el tema de la estanteria: ");
      String temaEstanteria = sc.nextLine();

      Estanteria temp = new Estanteria(idEstanteria, temaEstanteria);
      libr.addEstanteria(temp);

      System.out.println("Autor creado, Enter para continuar");
      sc.nextLine();
    }

    if (option == 3) {

      System.out.print("Inserte el nombre de la casa: ");
      String nomCasa = sc.nextLine();
      
      System.out.print("Inserte el email de la casa: ");
      String emailCasa = sc.nextLine();
      
      System.out.print("Inserte el telefono de la casa: ");
      String telCasa = sc.nextLine();
      
      System.out.print("Inserte el website de la casa: ");
      String webCasa = sc.nextLine();
    
      CasaPublicacion temp = new CasaPublicacion(nomCasa, emailCasa, telCasa, webCasa);
      casas.add(temp);

      System.out.println("Casa creada, Enter para continuar");
      sc.nextLine();
    }

    if (option == 4) {
      
      System.out.print("Inserte el nombre del autor: ");
      String nomAutor = sc.nextLine();
      
      System.out.print("Inserte el email del autor: ");
      String emailAutor = sc.nextLine();
      
      System.out.print("Inserte la pagina web del autor: ");
      String webAutor = sc.nextLine();

      Autor temp = new Autor(nomAutor, emailAutor, webAutor);
      autores.add(temp);

      System.out.println("Autor creado, Enter para continuar");
      sc.nextLine();
    }

    if (option == 99) {

      clearScreen();
      sc.close();
      System.exit(0);
    }

    clearScreen();
    }
    
  }

  public static void clearScreen(){

    try {
        if (System.getProperty("os.name").contains("Windows"))
            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        else
            Runtime.getRuntime().exec("clear");
    } catch (IOException | InterruptedException ex) {}
}
}