import java.util.ArrayList;
import java.util.Collections;

public class EjNodo {
    public static void main(String[] args) {
        
        Nodo a = new Nodo("1");
        Nodo b = new Nodo(a, "2");
        Nodo b2 = new Nodo(a, "2Alterno");
        Nodo c = new Nodo(b, "3");
        Nodo d = new Nodo(c, "4");
        Nodo e = new Nodo(d, "5");
        Nodo f = new Nodo(e, "6");

        ArrayList<Nodo> padres = new ArrayList<>(Nodo.getParents(c));

        for (Nodo var : padres) {
            System.out.println(var.getNombre());
        }

        Collections.reverse(padres);

        for (Nodo var : padres) {
            System.out.println(var.getNombre());
        }

        System.out.println();
        System.out.println(c.toString());

        System.out.println(a.getRecursiveHijos().toString());
    }
}