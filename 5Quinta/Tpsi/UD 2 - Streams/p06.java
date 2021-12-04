/*
Leggere da tastiera (5 stringhe) o da file (finche ce ne sono) stringhe come singole parole.
Al termine dell'inserimento stampare solo le stringhe che iniziano con una vocale.
Per ogni stringa determinare la lunghezza effettiva.
*/
import java.io.*;
public class p06 {
   public static void main(String[] args){
      InputStreamReader in = new InputStreamReader(System.in);
      BufferedReader br = new BufferedReader(in);
      String[] parole = new String[5];
      int i;

      try{
         // inserimento di 5 parole da tastiera in un vettore di Stringhe.
         for(i=0; i<5; i++){
            System.out.print("Parola: ");
            parole[i] = br.readLine();
         }

         // solo parole con iniziale vocale
         System.out.print("Iniziale vocale: ");
         for(i=0; i<5; i++){
            char c;
            c = parole[i].charAt(0);
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
               System.out.print(parole[i] + " ");
         }

         // lunghezza di ogni stringa
         System.out.print("\nParole-Lunghezza:\n");
         for(i=0; i<5; i++){
         System.out.print(parole[i]+": "+parole[i].length() + "\n");
         }

      }catch(IOException ex){
         System.out.print("Error");
      }
   }
}
