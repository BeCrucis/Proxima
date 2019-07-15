public class Anfibio extends Animal{

    public Anfibio(String tamanio, int ojos, int edad, String raza, String nombre) {
        super(tamanio, ojos, edad, raza, nombre);
    }

    public void comer(){
        System.out.println("Los anfibios comen insectos");
    }

    public void mover(){
        System.out.println("Se desplazan de diversas formas: caminan, nadan, serpentean o saltan");
    }

    public void comunicarse(){
        System.out.println("Hacen BSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS o RIBIT");
    }
    
}