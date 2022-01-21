import java.io.*;

public class ese1{
   public static void main(String[] args) throws IOException{
      System.out.println("Hello World...");
      System.out.println("Ciao Mondo...");

      int i;
      for(i=1; i<=10; i++){
         System.out.print(i+" ");
      }

      System.out.print("\n\n");
      for(i=1; i<=10; i++){
         if(i%2 == 0)
            System.out.print(i+" Pari\n");
         else
            System.out.print(i+" Dispari\n");
      }

      System.out.print("\n\n");
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String s;
      s = br.readLine();
      System.out.print("Stringa: "+s);
   }
}
