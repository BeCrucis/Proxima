public class SwampThing extends Vegetal implements Heroe{

    public SwampThing(String nombre, String clasificacion) {
        super(nombre, clasificacion);
        
    }

    @Override
    public void poderes() {
        System.out.println("Puedo controlar plantas");
    }

    @Override
    public void villanos(String nombreVillano) {
        System.out.println(nombreVillano + " Es villano de " + getNombre());
    }

    public void regeneracion() {
        System.out.println("Me regeneroooooo");
    }
    
    public void controlDePlantas() {
        System.out.println("Plantas venid a mi");
    }
    
}