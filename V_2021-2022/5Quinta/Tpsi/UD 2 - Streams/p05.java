/*
Realizzare un programma Java che richiede l'imput di 5 valori interi per inizializzare un vettore.
Al termine esegue:
- visualizzazione del vettore.
- calcolo della media dei valori del vettore.
- ordinamento in modo crescente del vettore.
- stampa del vettore.
*/
import java.io.*;

public class p05 {
   public static void main(String[] args){
      int i,j;
      int somma;
      int vet[] = new int[5];
      String str;
      InputStreamReader in = new InputStreamReader(System.in);
      BufferedReader br = new BufferedReader(in);

      try{
         // inserimento del vettore.
         for(i=0; i<5; i++){
            System.out.print("Valore: ");
            str = br.readLine();
            vet[i] = Integer.parseInt(str);
         }

         // stampa del vettore.
         System.out.print("\n\nVettore inserito: ");
         for(i=0; i<5; i++)
            System.out.print(vet[i] + " ");

         // media del vettore.
         System.out.print("\nMedia del vettore: ");
         somma = 0;
         for(i=0; i<5; i++)
            somma = somma + vet[i];
         System.out.print(somma/5);

         //ordinamento modo crescente.
         int box;
         for(i=0; i<5; i++){
            for(j=i; j<5; j++){
               if(vet[i] > vet[j]){
                  box = vet[i];
                  vet[i] = vet[j];
                  vet[j] = box;
               }
            }
         }
         System.out.print("\nVettore ordinato crescente: ");
         for(i=0; i<5; i++)
            System.out.print(vet[i] + " ");
            
      }catch(IOException ex){
         System.out.print("Error!");
      }
   }
}
