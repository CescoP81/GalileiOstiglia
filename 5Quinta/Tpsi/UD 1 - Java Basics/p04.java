/*
1. Realizzare un programma Java che richiede l'inserimento di 5 valori interi,
al termine dell'inserimento visualizza la somma totale e il valore minore inserito.
*/
import java.io.*;

public class p04{
   public static void main(String[] args){
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String st = new String();
      int n=0;
      int somma=0;
      int max=0;

      for(int i=0; i<5; i++){
         try{
            System.out.print("Numero: ");
            st = br.readLine();
         }catch(IOException e){
            System.out.println("Errore");
         }
         n = Integer.parseInt(st);

         if(n > max) max = n;
         somma = somma + n;
      }
      System.out.println("Somma: " + somma);
      System.out.println("Massimo: " + max);
   }
}