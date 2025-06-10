class Robot{
    private
        int a, b;
        
    public Robot(){
        a = 0;
        b = 0;
    }
    public void setValueA(int _val){
        a = _val;
    }
    public void setValueB(int _val){
        b = _val;
    }
    public int getSomma(){
        return(a+b);
    }
}