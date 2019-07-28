import java.util.ArrayList;

public class Asignatura {
    
    private String nombre;
    private String codigo;
    private int creditos;
    private ArrayList<String> requisitos; //Requisitos por codigo de asignatura
    private ArrayList<Curso> cursos;

    public Asignatura(String nombre, String codigo, int creditos) {
        this.nombre = nombre;
        this.codigo = codigo;
        this.creditos = creditos;
        
        requisitos = new ArrayList<>();
        cursos = new ArrayList<>();
    }

    public Asignatura(String nombre, String codigo, int creditos, ArrayList<String> requisitos) {
        this.nombre = nombre;
        this.codigo = codigo;
        this.creditos = creditos;
        this.requisitos = requisitos;

        cursos = new ArrayList<>();
    }

    public void addCurso(Curso curso){
        cursos.add(curso);
    }

    public void removeCurso(Curso curso){
        try {
            cursos.remove(curso);
        } catch (Exception e) {
            System.out.println("Curso no valido");
        }
    }

    public String getNombre() {
        return this.nombre;
    }

    public String getCodigo() {
        return this.codigo;
    }

    public int getCreditos() {
        return this.creditos;
    }

    public ArrayList<String> getRequisitos() {
        return this.requisitos;
    }

    public ArrayList<Curso> getCursos() {
        return this.cursos;
    }

    

}