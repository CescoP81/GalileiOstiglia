public class Ese04 {
    public static void main(String[] args){
        Robot r1 = new Robot();
        Robot r2 = new Robot();

        r1.setValues(5, 7);
        r2.setValues(3, 10);

        System.out.println("Somma valori r1("+r1.getValueA()+","+r1.getValueB()+"): "+r1.getSommaValues());
        System.out.println("Somma valori r2: "+r2.getSommaValues());
    }
}
/* Dicara
20.02 tpsi
20.03 tpsi
10.04 tpsi
*/
