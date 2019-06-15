import java.util.ArrayList;

public class Libreria {
    int id;
    String nombre;
    ArrayList<Estanteria> estanterias;

    public Libreria(int id, String nombre) {
        this.id = id;
        this.nombre = nombre;
    }

    public void addEstanteria(Estanteria estanteria){
         
        estanterias.add(estanteria);
    }
    
}