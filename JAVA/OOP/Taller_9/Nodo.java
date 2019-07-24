import java.util.ArrayList;

public class Nodo {
    
    private Nodo padre;
    private ArrayList<Nodo> hijos;
    private ArrayList<Empleado> empleados;
    private String nombre;

    public Nodo(String nombre){

        this.padre = null;
        this.nombre = nombre;
        hijos = new ArrayList<>();
        empleados = new ArrayList<>();

    }

    public Nodo(Nodo padre, String nombre){

        this.padre = padre;
        this.nombre = nombre;
        hijos = new ArrayList<>();
        empleados = new ArrayList<>();
        padre.addHijo(this);
        
    }

    public void setPadre(Nodo padre) {
        this.padre = padre;
        padre.addHijo(this);
    }

    public Nodo getPadre() {
        return padre;
    }

    public void addHijo(Nodo hijo){
        hijos.add(hijo);
    }

    public void removeHijo(Nodo hijo){
        hijos.remove(hijo);
    }

    public ArrayList<Nodo> getHijos(){
        return hijos;
    }

    public void addEmpleado(Empleado empleado){
        empleados.add(empleado);
    }

    public void removeEmpleado(Empleado empleado){
        empleados.remove(empleado);
    }

    public ArrayList<Empleado> getEmpleados(){
        return empleados;
    }

    public String getNombre() {
        return nombre;
    }

}