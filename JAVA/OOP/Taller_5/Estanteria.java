import java.util.ArrayList;
import java.util.Scanner;

public class Estanteria {
    int id;
    String tema;
    ArrayList<Libro> libros;

    public Estanteria(int id, String tema) {
        this.id = id;
        this.tema = tema;
        this.libros = new ArrayList<Libro>();
    }

    public void addLibro(Libro libro) {

        libros.add(libro);
    }

    public void deleteLibro(){

        if (libros.isEmpty()) {
            System.out.println("Estanteria vacia, saliendo . . .");
            return;
          }
      
          Scanner sc = new Scanner(System.in);
      
          for (Libro var : libros) {
            System.out.println((libros.indexOf(var)+1) +". "+ var.toString());
          }
      
          System.out.println();
          System.out.print("Inserte su opcion: ");
          int opt = Integer.parseInt(sc.nextLine());
        
        try {
            libros.remove(opt-1);
        }
        catch (Exception err) {
            System.out.println("Error al eliminar, Enter para continuar . . .");
            sc.nextLine();
        }
       
    }

    public String toString() {

        String formattedData = String.format("ID: %d con tema %s", id, tema);
        return formattedData;
    }
}