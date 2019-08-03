import java.util.ArrayList;

public class Estudiante extends Persona {

    String tipoEstudiante;
    String codigoEstudiante;
    boolean isActivo;

    ArrayList<Carrera> programas;
    ArrayList<Curso> cursosActivos;
    ArrayList<Curso> cursosRealizados;

    public Estudiante(String nombre, String documentoId, String codigoEstudiante, String tipoEstudiante) {
        super(nombre, documentoId);

        this.codigoEstudiante = codigoEstudiante;
        this.tipoEstudiante = tipoEstudiante;
        isActivo = true;

        programas = new ArrayList<>();
        cursosActivos = new ArrayList<>();
        cursosRealizados = new ArrayList<>();
    }

    public String getCodigoEstudiante() {
      return codigoEstudiante;
    }

    public void activarEstudiante() {
        isActivo = true;
    }

    public void retirarEstudiante() {
        isActivo = false;
    }

    public String getTipoEstudiante() {
        return tipoEstudiante;
    }

    public void addCurso(Curso curso) {
        cursosActivos.add(curso);
    }

    public void completarCurso(Curso curso, double notaFinal) {

        String codigoCurso = curso.getCodigoCurso();
        int indiceCurso = -2;

        //try {

            for (Curso cursoLista : cursosActivos) {
                if (cursoLista.getCodigoCurso().equals(codigoCurso)) {
                    indiceCurso = cursosActivos.indexOf(cursoLista);
                    break;
                }
            }
            Curso cursoSeleccionado = cursosActivos.get(indiceCurso);
            cursosRealizados.add(cursoSeleccionado);
            cursosActivos.remove(cursoSeleccionado);

            cursoSeleccionado.setNotaFinal(this, notaFinal);
        //} catch (Exception e) {

        //    System.out.println("Curso no encontrado");
        //}
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

    public double getPromedioPonderado(){
        
        double promedioPonderado = 0.0;
        int creditosTotales = 0;

        for (Curso cursoRealizado : cursosRealizados) {

            int creditosAsignatura = cursoRealizado.getAsignatura().getCreditos();
            creditosTotales += creditosAsignatura;
            promedioPonderado += cursoRealizado.getNotaFinal(this) * creditosAsignatura;
            
        }

        promedioPonderado = promedioPonderado / creditosTotales;
        return promedioPonderado;
    }

    public double getPromedioArimetico(){

        double promedioArimetico = 0.0;
        int cantidadCursos = cursosRealizados.size();

        for (Curso cursoRealizado : cursosRealizados) {
            promedioArimetico += cursoRealizado.getNotaFinal(this);
        }

        promedioArimetico = promedioArimetico / cantidadCursos;
        return promedioArimetico;
    }

    @Override
    public String toString() {

        String programas = "";

        for (Carrera programa : getProgramas()) {
            programas = programa.getNombre() + " " + programas;
        }

        String formattedInfo = String.format("Estudiante : %s, Tipo: %s, ID: %d, Programas: %s",
                getNombre(), getTipoEstudiante(), getID(), programas);
        return formattedInfo;
    }

}
