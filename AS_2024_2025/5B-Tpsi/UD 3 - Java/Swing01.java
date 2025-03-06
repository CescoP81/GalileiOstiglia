import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Swing01 extends JFrame{
    private JFrame frame;
    private JPanel panel;
    private JButton btn1;
    private int cnt_clicks;
    
    public Swing01(){
        frame = new JFrame();
        panel = new JPanel();
        btn1 = new JButton("Click Me!");
        cnt_clicks = 0;

        // creo un Listener che 'ascolta' se accade qualche evento per esempio il click del mouse.
        btn1Listener myBtn1Listener = new btn1Listener();  
        btn1.addActionListener(myBtn1Listener);   // aggiungo il Listener al bottone.


        // aggiungo il bottone al pannello.
        panel.add(btn1);
        // aggiungo il pannello al frame.
        frame.add(panel);

        // definisce cosa succede quando primo la X in alto a dx della finestra UI 'frame'
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // definisce il titolo della GUI, viene scritto nella barra blu in alto.
        frame.setTitle("My Java GUI App");
        // Definisce le dimensioni in pixel della UI (dimensioni iniziali e ridimensionabile)
        frame.setSize(640,480);
        // Imposta la visibilità della finestra come 'true';
        frame.setVisible(true);
    }

    private class btn1Listener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent ev){
            cnt_clicks++;  // ogni volta incremento il contatore di 1
            btn1.setText("Clicked "+cnt_clicks+" times.");   // cambio la stringa che compare sul bottone nella UI.
        }
    }

    public static void main(String[] args){
        new Swing01();
    }
}
