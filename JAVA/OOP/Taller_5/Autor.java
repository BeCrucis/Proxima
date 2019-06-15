import java.util.ArrayList;

public class Autor {
    String nombre;
    String email;
    String website;
    ArrayList<Libro> libros; //Agregacion de libros

    public Autor(String nombre, String email, String website) {
        this.nombre = nombre;
        this.email = email;
        this.website = website;
        libros = new ArrayList<Libro>();
    }

    public void addLibro(Libro libro){
        libros.add(libro);
        libro.setAutor(this);
    }

    public void ImprimirLibros(){

        for (Libro libro : libros) {
            System.out.println();
            System.out.println(libro.titulo);
            System.out.println(libro.casaPublicacion.nombre);
            System.out.println(libro.capitulos.size());

        }

    }

    public String toString() {
        return nombre;
    }
}