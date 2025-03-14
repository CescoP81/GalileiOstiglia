import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Swing02 extends JFrame{
    JFrame frame;
    JPanel panel;

    JLabel l1;  // indicazione primo campo.
    JLabel l2;  // indicazione secondo campo.
    JLabel l3;  // stringa del risultato calcolato.

    JTextField txt1; // casella di testo per il primo valore.
    JTextField txt2; // casella di testo per il secondo valore.

    JButton btn1;

    public Swing02(){
        frame = new JFrame();
        panel = new JPanel();

        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));

        l1 = new JLabel("Primo valore:");
        l2 = new JLabel("Secondo valore:");
        l3 = new JLabel("Risultato: ??");
        

        txt1 = new JTextField(15);
        txt2 = new JTextField(15);
        //txt2.setSize(20,200);
        //txt2.setMaximumSize(new Dimension(60, 320));

        btn1 = new JButton("Calcolo");

        // aggiungo i componenti al pannello
        panel.add(l1);
        panel.add(txt1);
        panel.add(l2);
        panel.add(txt2);
        panel.add(btn1);
        panel.add(l3);

        frame.add(panel);

        btnListener calcolo = new btnListener();
        btn1.addActionListener(calcolo);

        // definisce cosa succede quando primo la X in alto a dx della finestra UI 'frame'
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // definisce il titolo della UI, viene scritto nella barra blu in alto.
        frame.setTitle("Calcolo somma di due valori");
        // Definisce le dimensioni in pixel della UI (dimensioni iniziali e ridimensionabile)
        frame.setSize(640,200);
        // Imposta la visibilità della finestra come 'true';
        frame.setVisible(true);
    }

    private class btnListener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent ev){
            int v1, v2;
            int risultato;
            // recupero i valori dalle textFiled che sono delle stringhe, devo passarli in interi.
            v1 = Integer.parseInt(txt1.getText());
            v2 = Integer.parseInt(txt2.getText());
            risultato = v1+v2;

            l3.setText("Risultato: " + risultato);
        }
    }

    public static void main(String[] args){
        new Swing02();
    }
}
