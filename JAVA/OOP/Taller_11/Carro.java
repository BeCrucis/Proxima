public class Carro extends Vehiculo {

    private String modelo;
    private int llantas;

    public Carro(String nombre, String motor, String color, String modelo, int llantas) {
        super(nombre, motor, color);
        
        this.modelo = modelo;
        this.llantas = llantas;
    }
    
    public String getModelo() {
        return modelo;
    }

    public int getLlantas() {
        return llantas;
    }

    public void transformarse() {
        System.out.println("Me transformo en carro wee");
    }

    public void luchar() {
        System.out.println("Atropello al villano!");
    }
}