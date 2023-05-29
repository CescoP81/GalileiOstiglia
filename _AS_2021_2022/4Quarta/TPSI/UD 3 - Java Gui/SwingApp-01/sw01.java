/*
    Tutorial e guida su www.javapoint.it

    Esempio di programma Java con GUI basata su Swing e AWT.
    Uso di:
    - JFrame, JPanel e JButton.
    - Layout: FlowLayout.
    - Creazione di un Listener da associare al JButton.
*/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class sw01 extends JFrame{
    private JFrame frame;       // La finestra principale -> Contenitore di base
    private JPanel panel;       // Il container principale per accogliere i nodi Swing-> JButton.
    private JButton btn;        // Componente Swing JButton -> Bottone cliccabile.
    private int cnt_clicks;

    public sw01(){
        frame = new JFrame();
        panel = new JPanel();

        panel.setLayout(new FlowLayout());

        cnt_clicks = 0;
        btn = new JButton("Clicked 0 times");
        btnListener myBtnListener = new btnListener();
        btn.addActionListener(myBtnListener);

        panel.add(btn);

        frame.add(panel, BorderLayout.CENTER);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("My Java GUI App");

        frame.setSize(300,300);
        frame.setVisible(true);
    }

    private class btnListener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent ev){
            cnt_clicks++;
            btn.setText("Clicked "+cnt_clicks+" times.");
        }
    }

    public static void main(String[] args){
        new sw01();
    }

}