import java.util.ArrayList;

public class CasaPublicacion {
    String nombre;
    String email;
    String telefono;
    String website;
    ArrayList<Libro> libros;

    public CasaPublicacion(String nombre, String email, String telefono, String website) {
        this.nombre = nombre;
        this.email = email;
        this.telefono = telefono;
        this.website = website;
    }
    
    public void addLibro(Libro libro){
        libros.add(libro);
        libro.setCasaPublicacion(this);
    }

    public String toString() {
        return nombre;
    }
}