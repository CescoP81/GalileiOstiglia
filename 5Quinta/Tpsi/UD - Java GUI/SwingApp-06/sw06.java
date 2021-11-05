import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class sw06 extends JFrame{
   JFrame f;   // finestra principale
   JPanel p0;  // Prevede il layout a righe consecutive.
   JPanel p1;  // Comprende i componenti della prima riga.
   JPanel p2;  // Comprende la label da modificare con l'output del programma.
   JButton btn;
   JTextField tf;
   JLabel sStringa, sRisultati;

   public sw06(){
      f = new JFrame();
      p0 = new JPanel();
      p0.setLayout(new GridLayout(2,1));

      p1 = new JPanel();
      p1.setLayout(new FlowLayout(FlowLayout.LEFT));
      sStringa = new JLabel("Numero: ");
      tf = new JTextField();
      tf.setPreferredSize(new Dimension(100,20));
      btn = new JButton("Verifica Primo");
      btn.addActionListener(new btnListener());
      p1.add(sStringa);
      p1.add(tf);
      p1.add(btn);

      p2 = new JPanel();
      p2.setLayout(new FlowLayout(FlowLayout.LEFT));
      //setLayout(new BoxLayout(p2, BoxLayout.Y_AXIS));
      sRisultati = new JLabel("Risultati:");
      p2.add(sRisultati);

      

      setLayout(new BoxLayout(p0,BoxLayout.Y_AXIS));
      p0.add(p1); // aggiungo il pannello della prima riga.
      p0.add(p2); // aggiungere il pannello della seconda riga.
      p0.setAlignmentY(Component.TOP_ALIGNMENT);
     
      f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      f.add(p0);
      f.setSize(400,300);
      f.setTitle("Swing App 06");
      f.pack();
      f.setVisible(true);
   }

   private class btnListener implements ActionListener{
      @Override
      public void actionPerformed(ActionEvent ae){
         String str;
         String sNum = tf.getText(); // recupero il numero nella textfield come stringa.
         int num = Integer.parseInt(sNum); // converto la stringa in intero.
         int cnt;

         str = "<html>";
         str += "Risultati:";
         str += "<br>";
         str += "<br>Verifica se il numero " + sNum + " sia primo:<br>";
         cnt = 0;
         for(int i=1; i<=num; i++){
            if(num%i == 0){
               str += i + " ";
               cnt ++;
            }
         }
         str += "<br>";
         if(cnt <= 2)
            str += "Numero Primo.";
         else
            str += "Numero non Primo.";
         str += "</html>";
         sRisultati.setText(str);
         f.pack();
      }
  }

   public static void main(String[] args){
      new sw06();
   }
}