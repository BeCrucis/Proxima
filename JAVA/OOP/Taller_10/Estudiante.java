import java.util.ArrayList;

public class Estudiante extends Persona {

    String tipoEstudiante;
    boolean isActivo;

    ArrayList<Carrera> programas;
    ArrayList<Curso> cursosActivos;
    ArrayList<Curso> cursosRealizados;

    public Estudiante(String nombre, String documentoId, String tipoEstudiante) {
        super(nombre, documentoId);
        
        this.tipoEstudiante = tipoEstudiante;
        isActivo = true;

        programas = new ArrayList<>();
        cursosActivos = new ArrayList<>();
        cursosRealizados = new ArrayList<>();
    }

    public void activarEstudiante(){
        isActivo = true;
    }

    public void retirarEstudiante(){
        isActivo = false;
    }

    public String getTipoEstudiante() {
      return tipoEstudiante;
    }

    public void addCurso(Curso curso) {
        cursosActivos.add(curso);
    }

    public void completarCurso(Curso curso, double notaFinal) {

        try {
            int indiceCurso = cursosActivos.indexOf(curso);
            Curso cursoSeleccionado = cursosActivos.get(indiceCurso);
            cursosRealizados.add(cursoSeleccionado);
            cursosActivos.remove(cursoSeleccionado);

            cursoSeleccionado.setNotaFinal(this, notaFinal);
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

    @Override
    public String toString() {
        String formattedInfo = String.format("Estudante : %s, Tipo: %s, ID: %d, Programas: %s", getNombre(), getTipoEstudiante(), getID(), getProgramas().toString());
return formattedInfo;
    }

}