import java.io.*;
import java.net.*;
import java.util.*;

public class p03{
    public static void main(String[] args){
        ArrayList<String> righe = new ArrayList<String>();

        try{
            //URL server = new URL("http://scuola.localhost/getResponse.php");
            URL server = new URL("http://www.francescopradella.it/scuola/getResponse.php");
            try{
                URLConnection con = server.openConnection();
                BufferedReader br = new BufferedReader(new InputStreamReader(con.getInputStream()));
                String st;
                
                // st = br.readLine();
                while((st = br.readLine())!= null){
                    righe.add(st);
                    //st = br.readLine();
                }
                br.close();

                for(int i=0; i<righe.size(); i++){
                    System.out.println(righe.get(i));
                }
                righe = null;
            } catch(IOException e){
                System.out.print("Error in buffering...");
            }
        } catch(MalformedURLException mue){
            System.out.print("Error in connection...");
        }
    }
}