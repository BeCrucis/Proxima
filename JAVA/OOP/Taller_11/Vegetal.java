public class Vegetal {

    private String nombre;
    private String clasificacion;

    public Vegetal(String nombre, String clasificacion) {
        this.nombre = nombre;
        this.clasificacion = clasificacion;
    }
    
    public void fotosintesis() {
        System.out.println("Sol solecito, calientame un poquito");
    }
    
    public String getNombre() {
        return nombre;
    }

    public String getClasificacion() {
        return clasificacion;
    }

}