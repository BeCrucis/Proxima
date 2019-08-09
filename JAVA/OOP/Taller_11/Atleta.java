public class Atleta extends Persona{

    private int fuerza;
    private int agilidad;

    public Atleta(String nombre, String apellido, int id, int fuerza, int agilidad) {
        super(nombre, apellido, id);
        
        this.fuerza = fuerza;
        this.agilidad = agilidad;
    }

    public int getFuerza() {
        return fuerza;
    }

    public void setFuerza(int fuerza) {
        this.fuerza = fuerza;
    }

    public int getAgilidad() {
        return agilidad;
    }

    public void setAgilidad(int agilidad) {
        this.agilidad = agilidad;
    }

    public void entrenamiento() {
        setFuerza(getFuerza() + 1);
        setAgilidad(getAgilidad() + 1);
        System.out.println("He entrenado, soy mas fuerte!");
    }
    
    public void dispositivos() {
        System.out.println("Tengo una pistolota en mi portapistolotas");
        System.out.println("Tengo mucho amor");
        System.out.println("Tengo un ihpone X10 plus");
        System.out.println("Tengo una biblia para protejerme de los furros");
    }

    public void artesMarciales() {
        System.out.println("Jay-yay mando punio");
    }
}