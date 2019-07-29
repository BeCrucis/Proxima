import java.util.ArrayList;

public class Curso {

    private String codigoCurso;
    public int horaInicio;
    public int horaFin;
    private ArrayList<Estudiante> estudiantes;
    public int capacidad;
    private Asignatura asignatura;
    private Empleado profesor;
    private ArrayList<Double> notasFinales;

    public Curso(String codigoCurso, Asignatura asignatura, int capacidad) {
        this.codigoCurso = codigoCurso;
        this.asignatura = asignatura;
        this.profesor = null;
        this.capacidad = capacidad;

        horaInicio = 0;
        horaFin = 0;

        estudiantes = new ArrayList<>();
        notasFinales = new ArrayList<>();
        asignatura.addCurso(this);
    }

    public Curso(String codigoCurso, Asignatura asignatura, Empleado profesor, int capacidad) {
        this.codigoCurso = codigoCurso;
        this.asignatura = asignatura;
        this.profesor = profesor;
        this.capacidad = capacidad;

        horaInicio = 0;
        horaFin = 0;

        estudiantes = new ArrayList<>();
        notasFinales = new ArrayList<>();
        asignatura.addCurso(this);
    }

    public String getCodigoCurso() {
      return codigoCurso;
    }

    public int getHoraInicio() {
        return horaInicio;
    }

    public void setHoraInicio(int horaInicio) {
        this.horaInicio = horaInicio;
    }

    public int getHoraFin() {
        return horaFin;
    }

    public void setHoraFin(int horaFin) {
        this.horaFin = horaFin;
    }

    public Asignatura getAsignatura() {
        return asignatura;
    }

    public Empleado getProfesor() {
        return profesor;
    }

    public void setProfesor(Empleado profesor) {
        this.profesor = profesor;
    }

    public ArrayList<Double> getNotasFinales() {
        return notasFinales;
    }

    public void setNotaFinal(Estudiante estudiante, double notaFinal) {

        String codigoEstudiante = estudiante.getCodigoEstudiante();
        int indiceNota = -1;

        //try {

            for (Estudiante estudianteLista : estudiantes) {
                if (estudianteLista.getCodigoEstudiante().equals(codigoEstudiante)) {
                    indiceNota = estudiantes.indexOf(estudianteLista);
                    break;
                }
            }

            notasFinales.set(indiceNota, notaFinal);

        //} catch (Exception e) {
        //    System.out.println("Estudiante invalido");
        //}
    }

    public double getNotaFinal(Estudiante estudiante) {

        String codigoEstudiante = estudiante.getCodigoEstudiante();
        int indiceNota = -1;

        //try {
            
            for (Estudiante estudianteLista : estudiantes) {
                if (estudianteLista.getCodigoEstudiante().equals(codigoEstudiante)) {
                    indiceNota = estudiantes.indexOf(estudianteLista);
                    break;
                }
            }
            return notasFinales.get(indiceNota);
        //}

        //catch (Exception e) {
        //    System.out.println("Estudiante invalido");
        //    return 0;
        //}
    }

    public void addEstudiante(Estudiante estudiante) {

        if (estudiantes.size() == capacidad) {
            System.out.println("Curso lleno!");
        } else {
            estudiantes.add(estudiante);
            estudiante.addCurso(this);
            notasFinales.add(0.0);
        }
    }

    @Override
    public String toString() {

        String formattedInfo;

        if (profesor == null) {
            formattedInfo = String.format(
                    "Asignatura: %s , Codigo: %s, Profesor: Sin asignar, Horario: %d - %d",
                    asignatura.getNombre(), codigoCurso, horaInicio, horaFin);
        } else {
            formattedInfo = String.format(
                    "Asignatura: %s , Codigo: %s, Profesor: %s, Horario: %d - %d",
                    asignatura.getNombre(), codigoCurso, profesor.getNombre(), horaInicio, horaFin);
        }
        return formattedInfo;
    }

}
