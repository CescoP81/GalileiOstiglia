/*
 * Basandoti sull'esempio 01 per quanto riguarda la struttura del programma e le operazioni
 * di input/output realizza un programma che richiede due valori all'utente dopo di che
 * verifica e comunica se sono oppure no dei numeri primi e se sono numeri Amicali.
 * Ricordo che due numeri si dicono Amicali se la somma dei divisori di un numero (escluso se stesso)
 * è uguale all'altro numero.
 * Es: n1 e n2
 * somma divisori di n1 = n2 
 * E
 * somma divisori di n2 = n1
 * 
 * Due numeri amicali sono 220 e 284.
 */
import java.util.*;
import java.io.*;

public class Ese02 {
    public static void main(String args[]) throws IOException{
        String str;
        int n1, n2;
        int sommaDiv1, sommaDiv2;
        int div;
        BufferedReader br;
        
        br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Inserisci n1: ");
        str = br.readLine();
        n1 = Integer.parseInt(str);

        System.out.print("Inserisci n2: ");
        str = br.readLine();
        n2 = Integer.parseInt(str);

        sommaDiv1 = 0;
        System.out.print("Divisori di N1: ");
        for(div = 1; div <= n1; div++){
            if(n1%div == 0){
                System.out.print(div+" ");
                sommaDiv1 += div;
            }
        }
        sommaDiv1 -= n1;
        System.out.println();
        System.out.println("Somma divisori: "+sommaDiv1+"\n");

        sommaDiv2 = 0;
        System.out.print("Divisori di N2: ");
        for(div = 1; div <= n2; div++){
            if(n2%div == 0){
                System.out.print(div+" ");
                sommaDiv2 += div;
            }
        }
        sommaDiv2 -= n2;
        System.out.println();
        System.out.println("Somma divisori: "+sommaDiv2+"\n");

        if((sommaDiv1 == n2) && (sommaDiv2==n1)) 
            System.out.print("I due numeri sono amicali.");
        else
            System.out.print("I due numeri NON sono amicali.");
    }
}
