import java.util.ArrayList;
import java.util.Scanner;

public class Libro {
    String titulo;
    String ISBN;
    int paginas;
    int anoPublicacion;
    int numeroEdicion;
    ArrayList<Capitulo> capitulos;
    CasaPublicacion casaPublicacion;
    Autor autor;

    public Libro(String titulo, String iSBN, int paginas, int anoPublicacion, int numeroEdicion, Autor autor, CasaPublicacion casaPublicacion) {
        this.titulo = titulo;
        ISBN = iSBN;
        this.paginas = paginas;
        this.anoPublicacion = anoPublicacion;
        this.numeroEdicion = numeroEdicion;
        capitulos = new ArrayList<Capitulo>();
        autor.addLibro(this);
        casaPublicacion.addLibro(this);
    }

    public void setAutor(Autor autor) {
        this.autor = autor;
    }

    public void setCasaPublicacion(CasaPublicacion casaPublicacion) {
        this.casaPublicacion = casaPublicacion;
    }

    public void addCapitulo(Capitulo cap){
        capitulos.add(cap);
    }

    public void addCapitulo(){

        Scanner sc = new Scanner(System.in);

        System.out.print("Inserte el nombre del capitulo: ");
        String nombreCap = sc.nextLine();

        
        System.out.print("Inserte el inicio del capitulo: ");
        int inCap = sc.nextInt();

        
        System.out.print("Inserte el final del capitulo: ");
        int finCap = sc.nextInt();

        
        System.out.print("Inserte el numero del capitulo: ");
        int numCap = sc.nextInt();

        Capitulo temp = new Capitulo(nombreCap, inCap, finCap, numCap);

        capitulos.add(temp);
        sc.close();
    }

    public void listarCapitulos(){

        for (Capitulo capitulo : capitulos) {
            System.out.println(capitulo.numero + ": " + capitulo.titulo);
        }
    }

    public String getFormattedInfo(){

        String formattedTitle = "Titulo: " + titulo + "\n";
        String formattedAutor = "Titulo: " + autor + "\n";
        String casa = "Casa de publicacion: " + casaPublicacion.nombre + "\n";
        String numeroCapitulos = "Casa de publicacion: " + Integer.toString(capitulos.size()) + "\n";

        String formattedInfo =  formattedTitle + formattedAutor + casa + numeroCapitulos;

        return formattedInfo;
    }

    public String toString() { 
        return "Libro [autor=" + autor + ", casaPublicacion=" + casaPublicacion + ", numeroEdicion=" + numeroEdicion
                + ", paginas=" + paginas + ", titulo=" + titulo + "]";
    }

    
    
}