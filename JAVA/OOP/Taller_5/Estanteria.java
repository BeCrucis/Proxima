import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Estanteria {
    int id;
    String tema;
    ArrayList<Libro> libros;

    public Estanteria(int id, String tema) {
        this.id = id;
        this.tema = tema;
    }

    public void addLibro(Libro libro) {

        libros.add(libro);
    }

    public void deleteLibro() throws IOException {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Seleccione el libro a eliminar: ");

        for (int i = 0; i < libros.size(); i++) {
            System.out.println((i+1) +"."+ libros.get(i).toString());
        }

        System.out.print("Inserte su opción: ");
        int opt = Integer.parseInt(sc.nextLine()) - 1;
        
        try {
            libros.remove(opt);
        }
        catch (Exception err) {
            System.out.println("Error al eliminar, Enter para continuar . . .");
            System.in.read();
        }

        finally{
            sc.close();
        }
       
    }
}