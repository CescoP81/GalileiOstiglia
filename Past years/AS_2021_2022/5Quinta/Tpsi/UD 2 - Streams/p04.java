/*
Realizzare un programma Java che richiede l'inserimento di 5 valori interi,
al termine dell'inserimento visualizza la somma totale e il valore minore inserito.
*/
import java.io.*;

public class p04 {
   public static void main(String[] args){
      int i;
      int num;
      int min;
      int somma;
      String str;
      InputStreamReader in = new InputStreamReader(System.in);
      BufferedReader br = new BufferedReader(in);

      try{
         somma = 0;
         min = 0;
         for(i=1; i<=5; i++){
            System.out.print("Valore: ");
            str = br.readLine();
            num = Integer.parseInt(str);
            somma = somma + num;
            if(i == 1)
               min = num;
            else{
               if(num < min)
                  min = num;
            }
         }
         System.out.print("\n\nSomma totale: " + somma + "\n");
         System.out.print("Valore minore: " + min);
      }catch(IOException ex){
         System.out.print("Error!");
      }      
   }  
}
