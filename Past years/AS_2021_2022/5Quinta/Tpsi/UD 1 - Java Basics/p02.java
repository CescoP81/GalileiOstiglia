//package 5Quinta.Tpsi.UD 1 - Java Basics;

class Robot{
   /**
    * Costruttore di base per l'oggetto Robot.
    */
   public Robot(){};

   /**
    * Medoto void che richiamato stampa il messaggio di saluto.
    */
   public void sayHello(){
      System.out.println("Hello, I'm a Robot");
   }

   /**
    * Metodo che stampa n volte il saluto del Robot.
    * @param n Numero di volte che Robot saluta.
    */
   public void repeatSayHello(int n){
      int i;
      for(i=1; i<=n; i++)
         System.out.println("Hello, I'm a Robot");
   }
}

public class p02 {
   public static void main(String[] args){
      Robot myRobot;
      myRobot = new Robot();
      
      myRobot.sayHello();
      System.out.print("\n\n");
      myRobot.repeatSayHello(5);
   }
}
