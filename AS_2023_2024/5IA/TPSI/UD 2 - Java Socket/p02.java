/**
 * Realizza un programma che acquisisce un valore da tastiera e visualizza
 * tutti i valori tra 1 ed il valore inserito.
 * 
 * L'inserimento del valore realizzarlo con un BufferedReader
 */
import java.io.*;

public class p02{
    public static void main(String[] args) throws IOException {
        String str;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Inserisci una parola: ");
        str = br.readLine();

        System.out.print("Hai detto forse "+str+"?");
    }
}
