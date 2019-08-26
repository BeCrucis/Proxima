import java.util.*;

public class Viaje implements RegistroViaje {

    RutaViaje ruta;

    public Viaje(){

    }

    private Viaje(RutaViaje ruta){
        this.ruta = ruta;
    }

    @Override
    public Viaje crearViaje(RutaViaje ruta) throws InvalidRouteException {

        Scanner sc = new Scanner(System.in);

        System.out.println("Es la ruta valida? 1:SI ELSE:NO : ");
        String validity = sc.nextLine();

        if(validity.equals("1")){
            return new Viaje(ruta);
        } else {
            throw new InvalidRouteException();
        }
    }
    
}