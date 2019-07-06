public class NaveTransportePasajero extends NavePasajero {

    NaveTransportePasajero(String matricula, String hangar) {
        super(matricula, hangar);
        super.precioDiaHangar = 2;
        modeloNave = "Nave de transporte de pasajeros TransLinea";
    }

}