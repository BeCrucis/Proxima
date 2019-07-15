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
        System.out.println("Hacen sonidos o hablan");
    }
    
}