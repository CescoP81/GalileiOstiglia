/*
   NB: Creare un file di testo nominato 'parole.txt' contenente alcune 
   parole, una per ogni riga del file.
*/
import java.io.*;

public class p02 {
   public static void main(String[] args){
      String st = new String();
      try{
         FileReader fr = new FileReader("parola.txt");
         BufferedReader br = new BufferedReader(fr);
         try{
            st = br.readLine();
            while(st != null){
               System.out.println(st);
               st = br.readLine();
            }
         }catch(IOException e){
            System.out.print("Errore in lettura.");
         }
      } catch(IOException e){
         System.out.print("Errore, file errato o mancante.");
      }
   }
}
