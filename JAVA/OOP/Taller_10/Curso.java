import java.util.ArrayList;

public class Curso {
    
    String codigoCurso;
    int horaInicio;
    int horaFin;
    ArrayList<Estudiante> estudiantes;
    int capacidad;
    Asignatura asignatura;
    Empleado profesor;
    double notaFinal;

    public Curso(Asignatura asignatura, Empleado profesor, int capacidad) {
        this.asignatura = asignatura;
        this.profesor = profesor;
        this.capacidad = capacidad;
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

    public double getNotaFinal() {
        return notaFinal;
    }

    public void setNotaFinal(double notaFinal) {
        this.notaFinal = notaFinal;
    }

    public void addEstudiante(Estudiante estudiante){
        
        if (estudiantes.size() == capacidad) {
            System.out.println("Curso lleno!");     
        } else { estudiantes.add(estudiante); }
    }

}