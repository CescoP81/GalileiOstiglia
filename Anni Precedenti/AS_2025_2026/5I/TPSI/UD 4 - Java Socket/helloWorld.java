/*
    Reference su cui trovare informazioni
    - www.w3schools.com
    - https://docs.oracle.com/en/java/
    - javatpoint.com
    - https://www.html.it/java/

    - Compilazione da terminale (Prompt): javac nomefile.java
    - esecuzione da terminale: java nomefile [senza .class]
*/
//package AS_2025_2026.5I.TPSI.UD 4 - Java;
import java.util.*;

public class helloWorld {
    public static void main(String[] args){
        System.out.print("Hello World");

        int a = 25;

        if(a <= 20){
            System.out.println("Sono minore o uguale di 25");
        }
        else{
            System.out.println("Sono maggiore di 25");
        }

        for(int i=0; i<= 25; i++){
            System.out.print(i+" ");
        }
    }    
}