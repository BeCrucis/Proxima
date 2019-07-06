class NaveCarreras extends NavePasajero{

    NaveCarreras(String matricula, String hangar) {
        super(matricula, hangar);
        
        super.precioDiaHangar = 1.5;
        modeloNave = "Nave de carreras Kestrel";
    }

    
}