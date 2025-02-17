public class Ese05 {
    public static void main(String[] args){
        Robot r1 = new Robot();
        Robot r2 = new Robot();

        r1.setValueA(5);
        r1.setValueB(8);

        r2.setValueA(2);
        r2.setValueB(15);

        System.out.println("Somma Robot 1: "+r1.getSomma());
        System.out.println("Somma Robot 2: "+r2.getSomma());
    }    
}
