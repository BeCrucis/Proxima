public class Mutante extends Persona {

    private String poder;

    public Mutante(String nombre, String apellido, int id, String poder) {
        super(nombre, apellido, id);
        this.poder = poder;
    }
    
    public void poderMutante() {
        System.out.println(poder);
    }

    public void artesMarciales() {
        System.out.println("Hay ya y mando patada");
    }

    @Override
    public void poderes() {
        poderMutante();
    }
}