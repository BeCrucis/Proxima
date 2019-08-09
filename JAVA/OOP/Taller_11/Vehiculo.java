public class Vehiculo implements Heroe, Transformer{

    private String nombre;
    private String motor;
    private String color;

    public Vehiculo(String nombre, String motor, String color) {
        this.nombre = nombre;
        this.motor = motor;
        this.color = color;
    }

    @Override
    public void poderes() {
        System.out.println("El poder de contaminar el ambiente!");
    }

    @Override
    public void villanos(String nombreVillano) {
        System.out.println(nombreVillano + " Es villano de " + getNombre());
    }

    public void transportar() {
        System.out.println("Transporto, transporto");
    }

    public void acelerar() {
        System.out.println("Brrrum brrurm, acelero!");
    }

    public String getNombre() {
        return nombre;
    }

    public String getMotor() {
        return motor;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public void transformarse() {
        System.out.println("Me transformo en un vehiculo no identificado");
    }

    @Override
    public void luchar() {
        System.out.println("Peleo como los Prime, hasta el final!");
    }
    
}