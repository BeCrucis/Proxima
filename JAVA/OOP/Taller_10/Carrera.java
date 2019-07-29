import java.util.ArrayList;

public class Carrera {
<<<<<<< HEAD
=======
    
    String nombre;
    Nodo facultad;
    ArrayList<Asignatura> pensum;
>>>>>>> refs/remotes/origin/master

    private String nombre;
    private Nodo escuela;
    private ArrayList<Asignatura> pensum;
    private ArrayList<Estudiante> estudiantes;

    public Carrera(String nombre, Nodo escuela) {
        this.nombre = nombre;
        this.facultad = facultad;

        pensum = new ArrayList<>();
        estudiantes = new ArrayList<>();
    }

    public void addToPensun(Asignatura asignatura) {
        pensum.add(asignatura);
    }

    public void removeFromPensum(Asignatura asignatura) {
        try {
            pensum.remove(asignatura);
        } catch (Exception e) {

        }
    }
<<<<<<< HEAD

    public void addEstudiante(Estudiante estudiante) {

        estudiante.addPrograma(this);
        this.estudiantes.add(estudiante);
    }

    public String toString() {
        String formattedInfo =
                String.format("Carrera: %s , Escuela: %s , Cantidad de asignaturas: %d ", nombre,
                        escuela, pensum.size());
        return formattedInfo;
    }

=======
    
>>>>>>> refs/remotes/origin/master
}
