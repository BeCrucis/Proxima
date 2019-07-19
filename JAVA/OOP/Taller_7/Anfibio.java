public class Anfibio extends Animal{

    public Anfibio(String tamanio, int ojos, int edad, String raza, String nombre) {
        super(tamanio, ojos, edad, raza, nombre);
    }

    public void comer(){
        System.out.println("Los anfibios comen insectos y vegetales");
    }

    public void mover(){
        System.out.println("Se desplazan en al campo semiterrestre");
    }

    public void comunicarse(){
        System.out.println("Hacen sonidos a traves de sus sacos vocales");
    }

    public void completeInfo(){
        imprimirInfo();
        System.out.println("Viven en la tierra y en el agua \nTienen la piel humeda \nNacen de huevos \nSon vertebrados ");
    }
    
}