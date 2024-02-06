// sezione di caricamento "import" delle varie librerie Java.
import java.util.*;

// definizione della classe pubblica generale
// - DEVE avere lo stesso nome del file che stiamo scrivendo
// - DEVE contenere il metodo MAIN()
public class p01{
    public static void main(String[] args){
        System.out.println("Hello World");
        System.out.println("Hello World");

        for(int i=1; i<=10; i++){
            System.out.println(i);
        }
        
        for(int i=1; i<=10; i++){
            System.out.println("Indice: "+i+" e il doppio: "+(i*2));
        }
    }
}
/*
 * Per compilare il file java il comando è:
 * c:\>javac nomefile.java
 * se non ci sono errori di compilazione viene prodotto il file 'nomefile.class'
 * per eseguire il programma java il comando è:
 * c:\>java nomefile [senza l'estensione .class]
 */

 /*
  * COMANDI FONDAMENTALI DELLA SHELL
  * DIR -> Visualizza la lista file/cartelle presente nel ramo del filesystem in cui viene lanciato.
  * CD nomecartella -> Cambia la cartella corrente con quella indicata come parametro.
  * CLS -> Clear Screen pulisce il terminale.
  */