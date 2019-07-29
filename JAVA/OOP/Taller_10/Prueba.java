import java.util.ArrayList;

public class Prueba {
    public static void main(String[] args) {
        
        ArrayList<Object> ej = new ArrayList<>();
        
        Docente cosa = new Docente("Jos", "1222", "Doc", 1000000, 2, new Nodo("Jajaj"));

        ej.add(cosa);
        cosa.hacerCosa();
    }
}