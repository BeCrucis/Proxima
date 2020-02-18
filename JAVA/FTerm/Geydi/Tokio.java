/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.ArrayList;

/**
 *
 * @author CENTIC
 */
public class Tokio {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Competicion c1 = new Competicion("TENNIS", "INDIVIDUAL");
        System.out.println("DEPORTE:" + c1.getNombre() + " " + " TIPO" + " " + c1.getTipoDeDeporte());

        Participante p1 = new Participante("Jualian", 97.8);
        Participante p2 = new Participante("Manuel", 60.6);
        Participante p3 = new Participante("Guillermo", 80.4);
        Participante p4 = new Participante("ADRIANA", 75.6);
        Participante p5 = new Participante("LUCIA", 90.2);
        Participante p6 = new Participante("MANUELA", 50.4);
        Participante p7 = new Participante("JUANA", 60.2);

        ArrayList<Participante> misParticipantes = new ArrayList<>();
        misParticipantes.add(p1);
        misParticipantes.add(p2);
        misParticipantes.add(p3);

        c1.setParticipantes(misParticipantes);

        System.out.println("Cantidad de partipantes en" + " " + c1.getNombre() + ":" + misParticipantes.size());
        for (int i = 0; i < misParticipantes.size(); i++) {
            System.out.println("participante:" + c1.getParticipantes().get(i).getNombre() + " Puntaje : "
                    + c1.getParticipantes().get(i).getPuntaje());
        }

        double max = 0;
        for (int i = 0; i < misParticipantes.size(); i++) {
            if (misParticipantes.get(i).getPuntaje() > max) {
                max = misParticipantes.get(i).getPuntaje();
            }

        }
        System.out.println("EL CAMPEON DE : " + c1.getNombre() + "  ES:" + max);

        Competicion c2 = new Competicion("ATLETISMO", "INDIVIDUAL");
        System.out.println("DEPORTE:" + c2.getNombre() + " " + " TIPO" + " " + c2.getTipoDeDeporte());

        ArrayList<Participante> miParticipante = new ArrayList<>();
        miParticipante.add(p4);
        miParticipante.add(p5);
        miParticipante.add(p6);
        miParticipante.add(p7);

        c2.setParticipantes(miParticipante);

        System.out.println("Cantidad de partipantes en" + " " + c2.getNombre() + ":" + miParticipante.size());
        for (int i = 0; i < miParticipante.size(); i++) {
            System.out.println(c2.getParticipantes().get(i).getNombre() + " Puntaje : "
                    + c2.getParticipantes().get(i).getPuntaje());
        }

        double maxi = 0;
        Participante campeon = new Participante("Temporal",1);

        for (int i = 0; i < miParticipante.size(); i++) {
            Participante temp = miParticipante.get(i);
            if (temp.getPuntaje() > maxi) {
                maxi = temp.getPuntaje();
                campeon = temp;
            }

        }
        System.out.println("EL CAMPEON DE : " + c2.getNombre() + "  ES:" + campeon.getNombre());
    }

}
