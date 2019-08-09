public class Groot extends Vegetal implements Heroe {

    private String planeta;

    public Groot(String nombre, String clasificacion, String planeta) {
        super(nombre, clasificacion);
        this.planeta = planeta;
    }

    @Override
    public void poderes() {
        System.out.println("Yo soy Groot, yo darte un palaso *voz de bebe");
    }

    @Override
    public void villanos(String nombreVillano) {
        System.out.println(nombreVillano + " Es villano de " + getNombre());
    }

    public String getPlaneta() {
        return planeta;
    }

    public void curacion() {
        System.out.println("Yo curar, soyo ser Groot");
    }

    public void setPlaneta(String planeta) {
        this.planeta = planeta;
    }

}