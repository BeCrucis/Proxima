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
public class Participante {
    private String nombre;
    private double puntaje;

    
    

    public Participante(String nombre,double puntaje) {
        this.nombre = nombre;
      
        this.puntaje= puntaje;
    }

    public double getPuntaje() {
        return puntaje;
    }

    public void setPuntaje(double puntaje) {
        this.puntaje = puntaje;
    }


   
    
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

   
    
    
}
