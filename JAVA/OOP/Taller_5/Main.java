import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

class Main {

  public static void main(String[] args) {

    Libreria libreria;

    ArrayList<CasaPublicacion> casas = new ArrayList<CasaPublicacion>();
    ArrayList<Autor> autores = new ArrayList<Autor>();

    libreria = new Libreria(1, "Turbay");

    Estanteria estanteDemo = new Estanteria(1, "Fantasia");
    libreria.addEstanteria(estanteDemo);

    CasaPublicacion bdv = new CasaPublicacion("Barco de vapor", "A", "123", "www.a.com");
    casas.add(bdv);

    Autor yuri = new Autor("Yuri M", "Yurmel1701@gmail.com", "www.yuri.com");
    autores.add(yuri);

    int option = 0;

    while(true){

      System.out.println("Bienvenido a la Biblioteca virtual!");
      System.out.println("A continuacion escoja la opcion que desea realizar");
      
      System.out.println("1. Modificar libreria");
      System.out.println("2. Crear estanteria");
      System.out.println("3. Crear casa de publicacion");
      System.out.println("4. Crear autor");
      System.out.println("5. Crear libro");
      System.out.println("6. Agregar capitulo a libro");
      System.out.println("7. Buscar autor y listar libros");
      System.out.println("8. Listar libros de casa editorial");
      System.out.println("9. Eliminar libros de estanterias");
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
      
      libreria = new Libreria(idLibreria, nomLibreria);

      System.out.println();
      System.out.println("Libreria creada, Enter para continuar");
      sc.nextLine();

      }
  
      if (option == 2) { //Crear estanteria dentro de la libreria

        if(libreria == null){
          clearScreen();  
          continue;
        }

        System.out.print("Inserte el ID de la estanteria: ");
        int idEstanteria = Integer.parseInt(sc.nextLine());

        System.out.print("Inserte el tema de la estanteria: ");
        String temaEstanteria = sc.nextLine();

        Estanteria temp = new Estanteria(idEstanteria, temaEstanteria);
        libreria.addEstanteria(temp);

        System.out.println("Estanteria creada, Enter para continuar");
        sc.nextLine();
      }

      if (option == 3) { //Crear casa de publicacion

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

      if (option == 4) { //Crear autor
        
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

      if (option == 5) { //Crear libro

        if(autores.isEmpty() || casas.isEmpty()){
          System.out.println("No existen autores o casas de publicaciones disponibles, respetad los derechos de autor!");
          System.out.println("Enter para continuar . . .");
          sc.nextLine();
          continue;
        }

        System.out.print("Inserte el titulo del libro: ");
        String titulo = sc.nextLine();
        
        System.out.print("Inserte el ISBN del libro: ");
        String iSBN = sc.nextLine();

        System.out.print("Inserte las paginas del libro: ");
        int paginas = Integer.parseInt(sc.nextLine());
        
        System.out.print("Inserte ano de publicacion: ");
        int anoPublicacion = Integer.parseInt(sc.nextLine());
        
        System.out.print("Inserte el numero de edicion: ");
        int numeroEdicion = Integer.parseInt(sc.nextLine());
        
        System.out.println("Seleccione el autor del libro: ");
        Autor autor = selectFromArrayList(autores);

        System.out.println("Seleccione la casa de publicacion del libro: ");
        CasaPublicacion casaPublicacion = selectFromArrayList(casas);

        System.out.println("Seleccione la ID de estanteria donde colocar el libro: ");
        Estanteria estanteria = selectFromArrayList(libreria.estanterias);

        Libro tmp = new Libro(titulo, iSBN, paginas, anoPublicacion, numeroEdicion, autor, casaPublicacion, estanteria);
        libreria.libros.add(tmp);

        System.out.println("Libro " + tmp.toString() + " creado y asignado");
        System.out.println("Libro asignado a la estanteria " + estanteria.toString());
        
        System.out.println("Enter para continuar . . .");
        sc.nextLine();    
      }

      if (option == 6) {
      
        System.out.println("Seleccione el libro al cual agregar un capitulo: ");
        Libro libroSeleccionado = selectFromArrayList(libreria.libros);

        libroSeleccionado.addCapitulo();
        
      }

      if (option == 7) {

        if (autores.isEmpty()) {
          System.out.println("No existen autores disponibles");
          System.out.println("Enter para continuar . . .");
          sc.nextLine();
          continue;
        }
        
        System.out.println("Seleccione el autor al cual listar libros: ");
        Autor autorSeleccionado = selectFromArrayList(autores);
        
        autorSeleccionado.ImprimirLibros();

        System.out.println();
        System.out.println("Enter para continuar . . .");
        sc.nextLine();
      }

      if (option == 8) {

        if (casas.isEmpty()) {
          System.out.println("No existen casas de publicacion disponibles");
          System.out.println("Enter para continuar . . .");
          sc.nextLine();
          continue;
        }
        
        System.out.println("Seleccione la casa editorial a la cual listar libros: ");
        CasaPublicacion casaSeleccionada = selectFromArrayList(casas);

        casaSeleccionada.ImprimirLibros();

        System.out.println();
        System.out.println("Enter para continuar . . .");
        sc.nextLine();
      }

      if (option == 9) {
        
        System.out.println("Seleccione la estanteria a modificar: ");
        Estanteria estanteriaSeleccionada = selectFromArrayList(libreria.estanterias);

        estanteriaSeleccionada.deleteLibro();
        
        System.out.println();
        System.out.println("Enter para continuar . . .");
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

  public static <Obj> Obj selectFromArrayList(ArrayList<Obj> list){

    if (list.isEmpty()) {
      System.out.println("Lista vacia, saliendo . . .");
      return null;
    }

    Scanner tmpsc = new Scanner(System.in);

    for (Obj var : list) {
      System.out.println((list.indexOf(var)+1) +". "+ var.toString());
    }

    System.out.println();
    System.out.print("Inserte su opcion: ");
    int opt = Integer.parseInt(tmpsc.nextLine());
    
    return list.get(opt-1);
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