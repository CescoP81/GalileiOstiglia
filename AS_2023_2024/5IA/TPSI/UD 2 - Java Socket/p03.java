import java.io.*;

public class p03 {
    public static void main(String[] args) throws IOException{
        String str;
        BufferedReader br = new BufferedReader(new clsInputStreamReader(System.in));
        System.out.print("Inserisci una parola: ");
        str = br.readLine();

        int numero = 0;
        try{
            numero = Integer.parseInt(str);
            System.out.print("Il numero inserito è: "+numero);
        }catch(NumberFormatException nfe){
            System.out.print("Attenzione non riesco a convertirlo in intero!");
        }
    }
}
