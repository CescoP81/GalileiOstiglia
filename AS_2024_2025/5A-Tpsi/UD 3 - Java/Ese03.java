import java.util.*;
import java.io.*;
/**
 * Programma che richiede numeri finche non viene inserito un numero primo,
 * al termine dell'inserimento comunica quanti tentativi sono stati eseguiti.
 */
public class Ese03{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strIn;
        int num;
        int i, cnt;
        int trovato = 0;

        cnt = 0;
        do{
            cnt++;
            System.out.print("Inserisci un numero: ");
            strIn = br.readLine();
            num = Integer.parseInt(strIn);
            /* 
            trovato = 1;
            for(i=2; i<=num/2; i++){
                if(num%i == 0)
                    trovato = 0;
            }*/
            trovato = isPrimo(num);
            if(trovato == 0)
                System.out.println("Non primo, ritenta...");
                
        }while(trovato == 0);
        System.out.print(num+" è primo. Hai provato "+cnt+" tentativi!");
    }
    /**
     * Determina se un numero è primo oppure no
     * @param _num Numero da verificare
     * @return Booleano 1 è primo, 0 non è primo.
     */
    private static int isPrimo(int _num){
        int trovato = 1;
        int i;
        for(i=2; i<=_num/2; i++){
            if(_num%i == 0)
                trovato = 0;
        }
        return(trovato);
    }
}