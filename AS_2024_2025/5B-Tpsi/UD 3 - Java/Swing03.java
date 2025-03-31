import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Swing03 extends JFrame{
    JFrame frame;
    JPanel panel;
    JPanel tmpPanel;

    JTextField txt1;
    JTextField txt2;

    JLabel lbl;

    JButton btn;

    public Swing03(){
        frame = new JFrame();
        frame.setTitle("Multi panel layout");
        
        panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));

        // creo il pannello per la prima riga e aggiungo i relativi componenti.
        // quindi aggiungo il pannello temporaneo
        tmpPanel = new JPanel();
        lbl = new JLabel("Label 1: ");
        txt1 = new JTextField(20);
        tmpPanel.add(lbl);
        tmpPanel.add(txt1);
        panel.add(tmpPanel);

        // creo il pannello per la prima riga e aggiungo i relativi componenti.
        // quindi aggiungo il pannello temporaneo
        tmpPanel = new JPanel();
        lbl = new JLabel("Label 2: ");
        txt2 = new JTextField(20);
        tmpPanel.add(lbl);
        tmpPanel.add(txt2);
        panel.add(tmpPanel);

        btn = new JButton("Click me");
        panel.add(btn);

        frame.add(panel);

        // definisce cosa succede quando primo la X in alto a dx della finestra UI 'frame'
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Definisce le dimensioni in pixel della UI (dimensioni iniziali e ridimensionabile)
        frame.setSize(640,200);
        // Imposta la visibilità della finestra come 'true';
        frame.setVisible(true);
    }
    
    public static void main(String[] args){
        new Swing03();
    }
}
