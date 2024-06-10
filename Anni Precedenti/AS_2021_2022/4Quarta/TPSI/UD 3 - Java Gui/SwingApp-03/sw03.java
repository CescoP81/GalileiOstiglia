/*
    Esempio di programma Java con GUI basata su Swing e AWT.
    Gestione di due distinti bottoni con relativi Listener associati.
    Uso di:
    - JFrame, JPanel e JButton, JTextFiels, JLabel.
    - Layout: FlowLayout.
    - Creazione di un Listener da associare al JButton.
*/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class sw03 extends JFrame{
    private JFrame frame;
    private JLabel label;
    private JTextField textField;
    private JButton btn1;
    private JButton btn2;
    private JPanel panel;
    

    public sw03(){
        frame = new JFrame();
        panel = new JPanel();

        //panel.setLayout(new GridLayout(1,3,5,5));
        panel.setLayout(new FlowLayout(FlowLayout.LEFT));

        label = new JLabel("Numero: ");
        textField = new JTextField();
        textField.setPreferredSize(new Dimension(100,20));        

        btn1 = new JButton("Primo?");
        btn1.addActionListener(new btn1Listener());

        btn2 = new JButton("Perfetto?");
        btn2.addActionListener(new btn2Listener());

        panel.add(label);
        panel.add(textField);
        panel.add(btn1);
        panel.add(btn2);

        frame.add(panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("My Java GUI App");

        frame.setSize(500,100);
        frame.pack();      
        frame.setVisible(true);
    }

    private class btn1Listener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent ev){
            String sNumber;
            int iNumber;
            int i, cnt;
            
            sNumber = textField.getText();
            if(!sNumber.isEmpty()){
                iNumber = Integer.parseInt(sNumber);

                System.out.println("Numero: "+iNumber);
                System.out.print("Divisori: ");
                cnt = 0;
                for(i=1; i<=iNumber; i++){
                    if(iNumber%i == 0){
                        cnt++;
                        System.out.print(i+" ");
                    }
                }
                System.out.print("\n");
                if(cnt <= 2)
                    System.out.print("Primo!");
                else
                    System.out.print("Non Primo!");
                System.out.print("\n\n");
            }
        }
    }

    private class btn2Listener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent ev){
            String sNumber;
            int iNumber;
            int i, somma;

            sNumber = textField.getText();
            if(!sNumber.isEmpty()){
                iNumber = Integer.parseInt(sNumber);
                System.out.println("Numero: "+iNumber);
                System.out.print("Divisori: ");
                somma = 0;
                for(i=1; i<iNumber; i++){
                    if(iNumber%i == 0){
                        System.out.print(i+" ");
                        somma = somma + i;
                    }
                }
                System.out.print("\n");
                System.out.print("Somma Divisori: "+somma+" ");
                if(somma == iNumber)
                    System.out.print("-> Perfetto!");
                else
                    System.out.print("-> Oh no!");
                System.out.print("\n\n");
            }
        }
    }

    public static void main(String[] args){
        new sw03();
    }

}
