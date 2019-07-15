public class Mamifero extends Animal{

    boolean pelo;
    boolean tomaLeche;
    public Mamifero(String tamanio, int ojos, int edad, String raza, boolean pelo, boolean tomaLeche) {
        super(tamanio, ojos, edad, raza);
        this.pelo = pelo;
        this.tomaLeche = tomaLeche;
    }

    public void comer (){
        System.out.println("Pueden ser herviboros, carnivoros u omnivoros");
    }
}