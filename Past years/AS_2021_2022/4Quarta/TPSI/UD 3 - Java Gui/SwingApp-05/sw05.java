/**
 * Programma per la gestione di una GUI a più pannelli, uno iniziale e due dedicati a rettangolo e cerchio.
 * L'output dei dati viene fatto in Console.
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class sw05 extends JFrame{
    JFrame frame;

    // componenti per la parte generale.
    JPanel mainPanel;
    JButton circusBtn;
    JButton squareBtn;
    JButton backBtn;        // se sono nel pannello rettangolo
    JButton backBtn2;       // se sono nel pannello cerchio

    JPanel squarePanel;                 // pannello e componenti per il rettangolo.
    JLabel squareBase;
    JLabel squareAltezza;
    JTextField tfSquareInputBase;
    JTextField tfSquareInputAltezza;
    JButton squareBtnCalcola;

    JPanel circusPanel;                 // pannello e componenti per il cerchio.
    JLabel circusRadius;
    JTextField tfCircusInputRadius;
    JButton circusBtnCalcola;
    

    public sw05(){
        frame = new JFrame();

        backBtn = new JButton("Go Back");
        backBtn.addActionListener(new backBtnListener());
        backBtn2 = new JButton("Go Back");
        backBtn2.addActionListener(new backBtn2Listener());
        
        mainPanel = new JPanel();
        circusBtn = new JButton("Cerchio");
        squareBtn = new JButton("Rettangolo/Quadrato");
        squareBtn.addActionListener(new squareBtnListener());
        circusBtn.addActionListener(new circusBtnListener());
        mainPanel.add(squareBtn);
        mainPanel.add(circusBtn);

        // Definizione di tutti i componenti necessari all'interfaccia del quadrato
        squarePanel = new JPanel();
        squareBase = new JLabel("Base: ");
        squareAltezza = new JLabel("Altezza: ");
        tfSquareInputBase = new JTextField();
        tfSquareInputBase.setPreferredSize(new Dimension(150,20));
        tfSquareInputAltezza = new JTextField();
        squareBtnCalcola = new JButton("Calcola Area e Perimetro");
        squareBtnCalcola.addActionListener(new squareBtnCalcolaListener());
        squarePanel.setLayout(new GridLayout(3,2));
        squarePanel.add(squareBase);
        squarePanel.add(tfSquareInputBase);
        squarePanel.add(squareAltezza);
        squarePanel.add(tfSquareInputAltezza);
        squarePanel.add(squareBtnCalcola);
        squarePanel.add(backBtn);

        // Definizione di tutti i componenti necessari all'interfaccia del cerchio
        circusPanel = new JPanel();
        circusRadius = new JLabel("Raggio: ");
        tfCircusInputRadius = new JTextField();
        tfCircusInputRadius.setPreferredSize(new Dimension(150,20));
        circusBtnCalcola = new JButton("Calcola Area e Circonferenza");
        circusBtnCalcola.addActionListener(new circusBtnCalcolaListener());
        circusPanel.setLayout(new GridLayout(2,2));
        circusPanel.add(circusRadius);
        circusPanel.add(tfCircusInputRadius);
        circusPanel.add(circusBtnCalcola);
        circusPanel.add(backBtn2);

        
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("Multi View App");
        frame.add(mainPanel);

        frame.setSize(400,400);
        frame.pack();
        frame.setVisible(true);
    }

    private class circusBtnListener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent ae){
            System.out.println("Vado al pannello cerchio...");
            tfCircusInputRadius.setText("");
            frame.remove(mainPanel);
            frame.add(circusPanel);
            frame.repaint();
            frame.pack();
            frame.setVisible(true);
        }
    }
    private class squareBtnListener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent ae){
            System.out.println("Vado al pannello rettangolo...");
            tfSquareInputAltezza.setText("");
            tfSquareInputBase.setText("");
            frame.remove(mainPanel);
            frame.add(squarePanel);
            frame.repaint();
            frame.pack();
            frame.setVisible(true);
        }
    }
    private class backBtnListener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent ae){
            System.out.println("Torno al main Panel...");
            
            frame.remove(squarePanel);
            frame.add(mainPanel);
            frame.repaint();
            frame.pack();
            frame.setVisible(true);
        }
    }
    private class backBtn2Listener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent ae){
            System.out.println("Torno al main Panel...");
            
            frame.remove(circusPanel);
            frame.add(mainPanel);
            frame.repaint();
            frame.pack();
            frame.setVisible(true);
        }
    }

    private class squareBtnCalcolaListener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent ae){
            String sBase = tfSquareInputBase.getText();
            String sAltezza = tfSquareInputAltezza.getText();

            int iBase = Integer.parseInt(sBase);
            int iAltezza = Integer.parseInt(sAltezza);

            int perimetro = (iBase+iAltezza) * 2;
            int area = iBase * iAltezza;

            System.out.println("Area: "+area);
            System.out.println("Perimetro: "+perimetro);
            System.out.print("\n\n");
        }
    }
    private class circusBtnCalcolaListener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent ae){
            String sRadius = tfCircusInputRadius.getText();

            int iRadius = Integer.parseInt(sRadius);

            double circonferenza = 2.0 * 3.14 * iRadius;
            double area = 3.14 * (iRadius*iRadius);

            System.out.println("Area: "+area);
            System.out.println("Circonferenza: "+circonferenza);
            System.out.print("\n\n");
        }
    }
    



    public static void main(String[] args){
        new sw05();
    }
}