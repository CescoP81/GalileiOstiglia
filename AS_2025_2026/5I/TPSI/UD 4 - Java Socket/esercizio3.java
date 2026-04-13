class myRobot{
    private int x;
    public myRobot(){
        x = 0;
    }
    public int leggiIntero(){
        sc.nextInt();
        return(x);
    }
}

public class esercizio3 {
    public static void main(String[] args){
        myRobot mr = new myRobot();
        int tmp;

        tmp = mr.leggiIntero();
        System.out.println(tmp);
    }  
}
