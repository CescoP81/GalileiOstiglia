import java.util.*;
import java.io.*;

public class Ese01 {
    public static void main(String args[]) throws IOException{
        System.out.println("Hello World...");

        // Costrutto IF-ELSE uguale al C
        int a = 123;
        if(a<150){
            System.out.println("Valore minore di 150");
        }
        else{
            System.out.println("Valore superiore a 150");
        }

        // ITERATIVE while, do-while, for uguali al C
        int i;
        i=0;
        while(i<5){
            System.out.println(i);
            i++;
        }

        for(i=0; i<7; i++){
            System.out.print(i+" ");
        }
        System.out.println();

        // Input da tastiera
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;
        System.out.print("Inserisci un numero: ");
        str = br.readLine();
        System.out.println(str);
        // devo convertire quanto letto da Buffered in numero per poterlo utilizzare nel ciclo come limite.
        int limite = Integer.parseInt(str);
        for(i=0; i<limite; i++){
            System.out.print(i+ " ");
        }
    }
}
