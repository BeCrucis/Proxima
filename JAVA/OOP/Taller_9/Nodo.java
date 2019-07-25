import java.util.*;

public class Nodo {

    private Nodo padre;
    private ArrayList<Nodo> hijos;
    private ArrayList<Empleado> empleados;
    private String nombre;

    public Nodo(String nombre) {

        this.padre = null;
        this.nombre = nombre;
        hijos = new ArrayList<>();
        empleados = new ArrayList<>();

    }

    public Nodo(Nodo padre, String nombre) {

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

    public void addHijo(Nodo hijo) {
        hijos.add(hijo);
    }

    public void removeHijo(Nodo hijo) {
        hijos.remove(hijo);
    }

    public ArrayList<Nodo> getHijos() {
        return hijos;
    }

    public ArrayList<Nodo> getRecursiveHijos() {

        ArrayList<Nodo> hijos = getHijos();
        ArrayList<Nodo> temp = new ArrayList<>();

        for (Nodo hijo : hijos) {
            temp.addAll(hijo.getRecursiveHijos());
        }

        hijos.addAll(temp);

        return hijos;
    }

    public void addEmpleado(Empleado empleado) {
        empleados.add(empleado);
    }

    public void removeEmpleado(Empleado empleado) {
        empleados.remove(empleado);
    }

    public ArrayList<Empleado> getEmpleados() {
        return empleados;
    }

    public String getNombre() {
        return nombre;
    }

    static public ArrayList<Nodo> getParents(Nodo nodo) {

        ArrayList<Nodo> nodosPadre = new ArrayList<>();
        nodosPadre.add(nodo);

        if (nodo.getPadre() != null) {

            ArrayList<Nodo> nodosAbuelo = getParents(nodo.getPadre());
            nodosPadre.addAll(nodosAbuelo);

            return nodosPadre;

        } else {

            return nodosPadre;
        }
    }

    @Override
    public String toString() {

        String nodePath = "";

        ArrayList<Nodo> padres = new ArrayList<>(getParents(this));
        Collections.reverse(padres);

        for (Nodo nodo : padres) {

            if (nodo.getPadre() != this.getPadre()) {
                nodePath = nodePath + nodo.getNombre() + " > ";

            } else {
                nodePath = nodePath + nodo.getNombre();

            }
        }

        return nodePath;
    }

}
