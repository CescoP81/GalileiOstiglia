import java.io.*;

public class p01{
   public static void main(String[] args){
      InputStreamReader in = new InputStreamReader(System.in);
      BufferedReader br = new BufferedReader(in);
      String st = new String();

      try{
         st = br.readLine();
         System.out.print("Stringa: "+st);
      } catch(IOException ex){
         System.out.println("Error!");
      };
   }
}