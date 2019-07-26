import java.util.ArrayList;

public class Estudiante extends Persona {

    ArrayList<Carrera> programas;
    ArrayList<Curso> cursosActivos;
    ArrayList<Curso> cursosRealizados;

    public Estudiante(String nombre, String documentoId) {
        super(nombre, documentoId);
        // TODO Auto-generated constructor stub
    }

    public void agregarCurso(Curso curso) {
        cursosActivos.add(curso);
    }

    public void completarCurso(Curso curso, double notaFinal) {

        try {
            int indiceCurso = cursosActivos.indexOf(curso);
            Curso cursoSeleccionado = cursosActivos.get(indiceCurso);
            cursosRealizados.add(cursoSeleccionado);
            cursosActivos.remove(cursoSeleccionado);

            cursoSeleccionado.setNotaFinal(notaFinal);
        } catch (Exception e) {

            System.out.println("Curso no encontrado");
        }
    }

    public ArrayList<Carrera> getProgramas() {
        return programas;
    }

    public void addPrograma(Carrera programa) {
        programas.add(programa);
    }

    public ArrayList<Curso> getCursosActivos() {
        return cursosActivos;
    }

    public ArrayList<Curso> getCursosRealizados() {
        return cursosRealizados;
    }  

}