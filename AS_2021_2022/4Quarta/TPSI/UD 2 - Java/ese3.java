/* 
Realizzare un programma Java che acquisisce un numero (sottoforma di stringa)
e dopo averlo convertito in intero, esegue un ciclo da 1 al numero inserito.
*/
import java.io.*;

public class ese3 {
   public static void main(String[] args){
      String str="";
      int num;
      int i;

      // input da tastiera di un numero
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      try{
         str = br.readLine();          // input da tastiera
         num = Integer.parseInt(str);  // converto da String a Int
      
         for(i=1; i<=num; i++){        // utilizzo il numero in un ciclo
            System.out.print(i+" ");   // stampo la 'i' per vedere i diversi valori
         }
      }catch(IOException e){
         System.out.print("Errore in lettura...");
      }
   }   
}
