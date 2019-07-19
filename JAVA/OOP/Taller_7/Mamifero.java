public class Mamifero extends Animal{

    boolean pelo;
    boolean tomaLeche;
    public Mamifero(String tamanio, int ojos, int edad, String raza, String nombre, boolean pelo, boolean tomaLeche) {
        super(tamanio, ojos, edad, raza, nombre);
        this.pelo = pelo;
        this.tomaLeche = tomaLeche;
    }

    public void comer(){
        System.out.println("Pueden ser carnivoros, herviboros u omnivoros");
    }

    public void mover(){
        System.out.println("La mayoria andan, otros nadan y otros vuelan");
    }

    public void comunicarse(){
        System.out.println("Producen los sonidos en el cuello, con sus cuerdas vocales");
    }

    public void completeInfo(){
        imprimirInfo();
        System.out.println("Cuerpo cubierto de pelo \nNacen del vientre de la madre \nCuando son pequenos maman leche \nSon vertebrados ");
    }
    
}