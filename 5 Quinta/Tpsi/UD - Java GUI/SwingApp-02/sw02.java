/*
    Esempio di programma Java con GUI basata su Swing e AWT.
    Uso di:
    - JFrame, JPanel e JButton, JTextFiels, JLabel.
    - Layout: FlowLayout.
    - Creazione di un Listener da associare al JButton.
*/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class sw02 extends JFrame{
    private JFrame frame;
    private JLabel label;
    private JTextField textField;
    private JButton btn;
    private JPanel panel;
    

    public sw02(){
        frame = new JFrame();
        panel = new JPanel();

        //panel.setLayout(new GridLayout(1,3,5,5));
        panel.setLayout(new FlowLayout(FlowLayout.LEFT));

        label = new JLabel("Numero: ");
        textField = new JTextField();
        //textField.setText("Insert Number Here...");
        textField.setPreferredSize(new Dimension(200,20));        

        //btn = new JButton("Verifica se è un Primo?");
        btn = new JButton(new ImageIcon("loupe.png"));
        btnListener btnListener = new btnListener();
        btn.addActionListener(btnListener);

        panel.add(label);
        panel.add(textField);
        panel.add(btn);

        frame.add(panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("My Java GUI App");

        //frame.setSize(600,100);
        frame.pack();      
        frame.setVisible(true);
    }

    private class btnListener implements ActionListener{
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

    public static void main(String[] args){
        new sw02();
    }

}
