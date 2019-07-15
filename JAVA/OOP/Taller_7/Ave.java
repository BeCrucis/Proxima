public class Ave extends Animal{

    public Ave(String tamanio, int ojos, int edad, String raza, String nombre) {
        super(tamanio, ojos, edad, raza, nombre);
        
    }
    
    public void comer(){
        System.out.println("Las aves pueden ser carnivoras, herbivoras, omnivoras o insectivoras");
    }

    public void mover(){
        System.out.println("La mayoria de aves vuelan");
    }

    public void comunicarse(){
        System.out.println("GUCUUUUUUUUUUUUUUUUU o KYAAAA");
    }

}