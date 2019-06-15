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
        this.libros = new ArrayList<Libro>();
    }

    public void addLibro(Libro libro){
        libros.add(libro);
        libro.setAutor(this);
    }

    public void ImprimirLibros(){

        for (Libro libro : libros) {
            System.out.println();
            System.out.println(libro.getFormattedInfo());
        }

    }

    public String toString() {
        return nombre;
    }
}