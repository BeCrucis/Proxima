import java.util.ArrayList;

public class Libreria {
    int id;
    String nombre;
    ArrayList<Estanteria> estanterias;
    ArrayList<Libro> libros = new ArrayList<Libro>();

    public Libreria(int id, String nombre) {
        this.id = id;
        this.nombre = nombre;
        this.estanterias = new ArrayList<Estanteria>();
        this.libros = new ArrayList<Libro>();
    }

    public void addEstanteria(Estanteria estanteria){
         
        estanterias.add(estanteria);
    }
    
}