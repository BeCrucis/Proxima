public class Avion extends Vehiculo {

    private int capacidadVuelo;

    public Avion(String nombre, String motor, String color, int capacidadVuelo) {
        super(nombre, motor, color);
       
        this.capacidadVuelo = capacidadVuelo;
    }
     
    public void elevarse() {
        System.out.println("Me elevo con un brownie :3");
    }

    public void girar() {
        System.out.println("Me giro, como Paez y sus circulos");
    }

    public void descender() {
        System.out.println("Desciendo, como mis notas con Paez :v");
    }

    public int getCapacidadVuelo() {
        return capacidadVuelo;
    }

    public void setCapacidadVuelo(int capacidadVuelo) {
        this.capacidadVuelo = capacidadVuelo;
    }

    @Override
    public void transformarse() {
        System.out.println("Me transformo en un avionsito wooo");
    }

    @Override
    public void luchar() {
        System.out.println("Hago el kamikaze!");
    }

}