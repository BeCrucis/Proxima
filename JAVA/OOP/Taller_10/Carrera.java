import java.util.ArrayList;

public class Carrera {

    private String nombre;
    private Nodo escuela;
    private ArrayList<Asignatura> pensum;
    private ArrayList<Estudiante> estudiantes;

    public Carrera(String nombre, Nodo escuela) {
        this.nombre = nombre;
        this.escuela = escuela;

        pensum = new ArrayList<>();
        estudiantes = new ArrayList<>();
    }

    public ArrayList<Asignatura> getPensum() {
      return pensum;
    }
    
    public String getNombre() {
      return nombre;
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

    public void addEstudiante(Estudiante estudiante) {

        estudiante.addPrograma(this);
        this.estudiantes.add(estudiante);
    }

    public String toString() {
        String formattedInfo =
                String.format("Carrera: %s , Escuela: %s , Cantidad de asignaturas: %d ", nombre,
                        escuela.getNombre(), pensum.size());
        return formattedInfo;
    }

}
