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
public class Competicion {
     private String nombre;
    private  String tipoDeDeporte;
    ArrayList<Participante>participantes;
    ArrayList<Records>record;
  


    public Competicion(String nombre, String tipoDeDeporte ) {
        this.nombre = nombre;
        this.tipoDeDeporte = tipoDeDeporte;
        this.participantes = new ArrayList<>();
        this.record = new ArrayList<>();
      
    }

    public ArrayList<Records> getRecord() {
        return record;
    }

    public void setRecord(ArrayList<Records> record) {
        this.record = record;
    }

  

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getTipoDeDeporte() {
        return tipoDeDeporte;
    }

    public void setTipoDeDeporte(String tipoDeDeporte) {
        this.tipoDeDeporte = tipoDeDeporte;
    }

    public ArrayList<Participante> getParticipantes() {
        return participantes;
    }

    public void setParticipantes(ArrayList<Participante> participantes) {
        this.participantes = participantes;
    }
            
           
}
