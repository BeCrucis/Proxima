import java.awt.List;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author TAIBHSE
 */
public class ASCIIToPrint
{

    /**
     * given a file containing text, this 
     * method returns an array list of each line of the file
     * @param file
     * @return
     * @throws FileNotFoundException 
     */
    public static List readFile(String file) throws FileNotFoundException
    {
        Scanner s = new Scanner(new File(file));
        List list = new List();
        while (s.hasNextLine())
        {
            list.add(s.nextLine());
        }
        s.close();
        
        return list;
    }
    
    public static void intro()
    {
        System.out.println("");
System.out.println(" ##################################################################################################");
System.out.println(" ##################################################################################################");
System.out.println(" ###                                       __,__                                                ###");
System.out.println(" ###                              .--.  .-\"     \"-.  .--.                                       ###");
System.out.println(" ###                             / .. \\/  .-. .-.  \\/ .. \\                                      ###");
System.out.println(" ###                            | |  \'|  /   Y   \\  |\'  | |                                     ###");
System.out.println(" ###                            | \\   \\  \\ 0 | 0 /  /   / |                                     ###");
System.out.println(" ###                             \\ \'- ,\\.-\"`` ``\"-./, -\' /                                      ###");
System.out.println(" ###                              `\'-\' /_   ^ ^   _\\ \'-\'`                                       ###");
System.out.println(" ###                              .--\'|  \\._ _ _./  |\'--.                                       ###");
System.out.println(" ###                            /`    \\   \\.-.  /   /    `\\                                     ###");
System.out.println(" ###                           /       \'._/  |-\' _.\'       \\                                    ###");
System.out.println(" ###                          /          ;  /--~\'   |       \\                                   ###");
System.out.println(" ###                         /        .\'\\|.-\\--.     \\       \\                                  ###");
System.out.println(" ###                        /   .\'-. /.-.;\\  |\\|\'~\'-.|\\       \\                                 ###");
System.out.println(" ###                        \\       `-./`|_\\_/ `     `\\\'.      \\                                ###");
System.out.println(" ###                         \'.      ;     ___)        \'.`;    /  /\'\'\'\'\'\'\\                      ###");
System.out.println(" ###                           \'-.,_ ;     ___)          \\/   /  /  ___   \\                     ###");
System.out.println(" ###                            \\   ``\'------\'\\       \\   `  /  /  /   \\   \\                    ###");
System.out.println(" ###                             \'.    \\       \'.      |   ;/__/  /     \\   \\                   ###");
System.out.println(" ###                           ___>     \'.       \\_ _ _/   ,     /       \\__/                   ###");
System.out.println(" ###                         .\'   \'.   .''''''''/    |--\'`~~~~\'\'                                ###");
System.out.println(" ###                   _____// / .---\'        _/ / / /__  _____  _____  _____                   ###");
System.out.println(" ###                  | ___((_(_/  (_)       |(_(_(_|___|/  __ \\|_   _||_   _|                  ###");
System.out.println(" ###                  | |_/ / _ __  _  _ __  | |_ \\ `--. | /  \\/  | |    | |                    ###");
System.out.println(" ###                  |  __/ |  __|| ||  _ \\ | __| `--. \\| |      | |    | |                    ###");
System.out.println(" ###                  | |    | |   | || | | || |_ /\\__/ /| \\__/\\ _| |_  _| |_                   ###");
System.out.println(" ###                  \\_|    |_|   |_||_| |_| \\__|\\____/  \\____/ \\___/  \\___/                   ###");
System.out.println(" ###                                                                                            ###");
System.out.println(" ###                                    CREATED BY TAIBHSE                                      ###");
System.out.println(" ###                                                                                            ###");
System.out.println(" ###          -------------------------------------------------------------------------         ###");
System.out.println(" ###          |                             INSTRUCTIONS                              |         ###");
System.out.println(" ###          |-----------------------------------------------------------------------|         ###");
System.out.println(" ###          |      1) Provide input file to convert to print statements,            |         ###");
System.out.println(" ###          |                e.g. C:\\someFolder\\file.txt                            |         ###");
System.out.println(" ###          |		                                                              |         ###");
System.out.println(" ###          |      2) Type name of language to create print statements for,         |         ###");
System.out.println(" ###          |                e.g. Java, python, batch                               |         ###");
System.out.println(" ###          |                                                                       |         ###");
System.out.println(" ###          |      3) Provide output location to save file to,                      |         ###");
System.out.println(" ###          |            e.g. C:\\folder\\giveFileName.txt                            |         ###");
System.out.println(" ###          -------------------------------------------------------------------------         ###");
System.out.println(" ###                                                                                            ###");
System.out.println(" ##################################################################################################");
System.out.println(" ##################################################################################################");
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException
    {  
        intro();
        
        Scanner in = new Scanner(System.in);
        
        System.out.print("INPUT FILE: ");
        
        List ascii = readFile(in.nextLine());
        
        System.out.println("##################################################################################################");
        System.out.println("AVAILABLE OPTIONS ARE: java, python, batch");
        System.out.print("LANGUAGE: ");
        
        String selection = in.nextLine();
        
        System.out.println("##################################################################################################");
        System.out.print("OUTPUT FILE: ");
        
        PrintWriter out = new PrintWriter(in.nextLine());
        
        System.out.println("##################################################################################################");
        
        
        String[] java = {"System.out.println(\"", "\");"}; //first item is start of print, second item is end of print
        String[] batch = {"echo ", "echo. "};  //first array item is for normal print, second is to print blank lines
        String[] python = {"print (\"", "\");"}; //first item is start of print, second item is end of print
       
        
        
        
        //loop to replace special characters and add print statements
        for(int i = 0; i < ascii.getItemCount(); i++)
        {
          if(selection.toLowerCase().equals("java"))
          {
            //add beginning and ending print elements and escape all special characters  
            ascii.replaceItem(java[0] + ascii.getItem(i).replace("\\", "\\\\").replace("\"", "\\\"").replace("\'", "\\\'") + java[1], i);
          
          }else if(selection.toLowerCase().equals("batch"))
          {
              //test if line is empty
              if(ascii.getItem(i).trim().equals(""))
              {
                  //if line is empty replace with echo.
                  //which is used to print blank lines in batch
                   ascii.replaceItem(batch[1], i );
              }else
              {    //if line is not empty then append echo to start and escape all 
                   //special characters
                   ascii.replaceItem(batch[0] + ascii.getItem(i).replace("%", "%%").replace("^", "^^").replace("&", "^&").replace("<", "^<").replace(">", "^>").replace("|", "^|").replace("'", "^'").replace("`", "^`").replace(",", "^,").replace(";", "^;").replace("=", "^=").replace("(", "^(").replace(")", "^)"), i);
              }
          }else if(selection.toLowerCase().equals("python"))
          {
                   ascii.replaceItem(python[0] + ascii.getItem(i).replace("\\", "\\\\").replace("\"", "\\\"").replace("\'", "\\\'") + python[1], i);
          
          }
          
          }
        
        
        //print all lines to output file
        for(int i = 0; i < ascii.getItemCount(); i++)
        {
         // System.out.println(ascii.getItem(i));
          out.println(ascii.getItem(i));
        }
        //close print writer
        out.close();
        in.close();
    
    }
}
