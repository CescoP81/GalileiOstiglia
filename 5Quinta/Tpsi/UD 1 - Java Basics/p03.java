import java.io.*;

public class p03 {
   public static void main(String[] args) throws IOException {
      String st;
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      System.out.print("Inserisci una stringa: ");
      st = br.readLine();
      System.out.print("\nInserita: "+st+"\n\n");

      System.out.print("Inserisci un numero: ");
      st = br.readLine();
      try{
         int n = Integer.parseInt(st);
         for(int i=1; i<=n; i++)
            System.out.print(i+" ");
      } catch(NumberFormatException nfe){
         System.out.print("\n!! Non sembra essere un numero !!");
      }
   }   
}
