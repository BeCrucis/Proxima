import java.util.ArrayList;

public class Carrera {
    
    String nombre;
    Nodo escuela;
    ArrayList<Asignatura> pensum;

    public Carrera(String nombre, Nodo escuela) {
        this.nombre = nombre;
        this.escuela = escuela;
    }

    public void addToPensun(Asignatura asignatura){
        pensum.add(asignatura);
    }

    public void removeFromPensum(Asignatura asignatura){
        try {
            pensum.remove(asignatura);
        } catch (Exception e) {
            
        }
    }
    
}