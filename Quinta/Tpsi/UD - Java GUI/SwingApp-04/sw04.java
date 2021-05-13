/*
    Esempio di programma Java con GUI basata su Swing e AWT.
    Gestione di due distinti bottoni con relativi Listener associati.
    Uso di:
    - JFrame, JPanel e JButton, JSlider, JLabel.
    - Layout: FlowLayout.
    - Creazione di un Listener da associare al JButton.
*/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class sw04 extends JFrame{
    private JFrame frame;
    private JLabel label;
    private JSlider slider;
    private JButton btn1;

    private JPanel panel;
    
    public sw04(){
        frame = new JFrame();
        panel = new JPanel();

        //panel.setLayout(new GridLayout(1,3,5,5));
        panel.setLayout(new FlowLayout(FlowLayout.LEFT));

        label = new JLabel("Numero: ");
        
        slider = new JSlider(JSlider.HORIZONTAL, 0, 100, 50);
        slider.setMajorTickSpacing(25); // ogni quanto viene visualizzato un mark
        slider.setPaintTicks(true);     // i marker ogni tick spacing.
        slider.setPaintLabels(true);    // le labels ad ogni mark        

        btn1 = new JButton("Get Value");
        btn1.addActionListener(new btn1Listener());

        panel.add(label);
        panel.add(slider);
        panel.add(btn1);
        
        frame.add(panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("My Java GUI App");

        frame.setSize(500,100);
        frame.pack();      
        frame.setVisible(true);
    }

    private class btn1Listener implements ActionListener{
        // recupera il valore dallo slider e lo stampa nella Consolle.
        @Override
        public void actionPerformed(ActionEvent ev){
            int valoreSlider;
            valoreSlider = slider.getValue();
            
            System.out.println("Slider Value: "+valoreSlider);            
        }
    }

    public static void main(String[] args){
        new sw04();
    }

}