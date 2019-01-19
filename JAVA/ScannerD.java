import java.util.Scanner;

public class ScannerD{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        
        String name = sc.nextLine();

        char gender = sc.next().charAt(0); 

        System.out.println("Nombre: " + name);
        System.out.println("Sexo: " + gender);

        System.out.println("Press Any Key To Continue...");
        sc.nextLine();

        sc.close();

        
    } 
}