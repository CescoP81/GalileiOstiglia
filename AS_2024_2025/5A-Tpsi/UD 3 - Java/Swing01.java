import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Swing01 extends JFrame{
    private JFrame frame;       // finestra generale
    private JPanel panel;       // Il container principale per accogliere i nodi Swing-> JButton.
    private JButton btn;        // singolo bottone da inserire nella UI.
    private int cnt_clicks;     // contatore delle volte che è stato premuto il bottone.
    
    private JButton btn2;
    private int cnt_clicks2;

    public Swing01(){
        frame = new JFrame();
        panel = new JPanel();
        btn = new JButton("Clikkami");
        btn2 = new JButton("Clikkami 2");

        cnt_clicks = 0;  // azzero il contatore
        // creo un Listener che 'ascolta' se accade qualche evento per esempio il click del mouse.
        btnListener myBtnListener = new btnListener();  
        btn.addActionListener(myBtnListener);   // aggiungo il Listener al bottone.

        cnt_clicks2 = 0;
        btnListener2 myBtnListener2 = new btnListener2();
        btn2.addActionListener(myBtnListener2);

        // aggiungo i vari elementi al pannello
        panel.add(btn);
        panel.add(btn2);
        // aggiungo il pannello al frame.
        frame.add(panel);

        // definisce cosa succede quando primo la X in alto a dx della finestra UI 'frame'
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // definisce il titolo della UI, viene scritto nella barra blu in alto.
        frame.setTitle("My Java GUI App");
        // Definisce le dimensioni in pixel della UI (dimensioni iniziali e ridimensionabile)
        frame.setSize(640,480);
        // Imposta la visibilità della finestra come 'true';
        frame.setVisible(true);
    }

    private class btnListener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent ev){
            cnt_clicks++;  // ogni volta incremento il contatore di 1
            btn.setText("Clicked "+cnt_clicks+" times.");   // cambio la stringa che compare sul bottone nella UI.
        }
    }

    private class btnListener2 implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent ev){

            cnt_clicks2++;  // ogni volta incremento il contatore di 1
            btn2.setText("Clicked "+cnt_clicks2+" times.");   // cambio la stringa che compare sul bottone nella UI.
        }
    }

    public static void main(String[] args){
        new Swing01();
    }
}
