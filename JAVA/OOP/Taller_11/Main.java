public class Main {

    public static void main(String[] args) {
        Mutante peto = new Mutante("Juanz", "Diaz", 1, "Abrazar");
        System.out.println("Juanz va a pelear!");
        peto.villanos("Marco Tulio");
        System.out.println("Juanz hace artes marciales!");
        peto.artesMarciales();
        System.out.println("El poder de Juanz es . . .");
        peto.poderMutante();
        System.out.println("Juanz lucha por la justicia!");
        peto.luchaJusticia();

        System.out.println();
        Atleta ed = new Atleta("Edw", "Ard", 218070, 200, 1000000);
        System.out.println("Los poderes de edward son . . .");
        ed.poderes();
        ed.entrenamiento();
        System.out.print("Mi fuerza nueva es . . . " + ed.getFuerza());
        System.out.println("Edward hace artes marciales!");
        ed.artesMarciales();
        System.out.println("Para luchar Ed tiene . . .");
        ed.dispositivos();

        System.out.println();
        Carro yuri = new Carro("Yuri", "EmpanadasDelCeis", "Rojo", "001", 1);
        System.out.println("Yuri va a transportar . . . ");
        yuri.transportar();
        yuri.acelerar();
        yuri.transformarse();
        System.out.println("Yuri va a luchar . . . ");
        yuri.villanos("Paez");
        yuri.luchar();

        System.out.println();
        Avion dani = new Avion("Da", "Ni", "Blanco", 10080);
        System.out.println("Dani volara y hara maromas . . . ");
        dani.elevarse();
        dani.girar();
        dani.descender();
        System.out.println("Dani ha encontrado un villano . . . ");
        dani.transformarse();
        dani.luchar();

        System.out.println();
        Groot sebas = new Groot("Sebas", "Tortuga", "Aaaaaah");
        System.out.println("Los poderes de Sebas el Groot son . . . ");
        sebas.poderes();
        System.out.println("Han herido a un amigo de Sebas . . . ");
        sebas.curacion();

        SwampThing jose = new SwampThing("Josa", "Negro");
        System.out.println("Jose es un SwampThing de clasificacion ");
        jose.getClasificacion();
        System.out.println("Jose va a pelear!");
        jose.villanos("ElParcialDeFisica");
        jose.controlDePlantas();
        System.out.println("Jose esta herido!");
        jose.regeneracion();

    }    
}