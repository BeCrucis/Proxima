public interface Heroe {


    public default boolean luchaJusticia() {
        System.out.println("Siempre luchar por la justicia");
        return true;
    }

    public abstract void poderes();

    public abstract void villanos(String nombreVillano);

}