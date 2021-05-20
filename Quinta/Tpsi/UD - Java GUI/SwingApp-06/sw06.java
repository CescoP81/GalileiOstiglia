import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class sw06 extends JFrame{
   JFrame f;
   JPanel p0;
   JPanel p1;
   JPanel p2;
   JButton btn;
   JTextField tf;
   JLabel sStringa, sRisultati;

   public sw06(){
      f = new JFrame();
      p0 = new JPanel();
      p0.setLayout(new GridLayout(3,1));

      p1 = new JPanel();
      p1.setLayout(new FlowLayout(FlowLayout.LEFT));
      sStringa = new JLabel("Stringa: ");
      tf = new JTextField();
      tf.setPreferredSize(new Dimension(100,20));
      btn = new JButton("Verifica");
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
      p0.add(p1);
      p0.add(p2);
      p0.setAlignmentY(Component.TOP_ALIGNMENT);
     
      f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      f.add(p0);
      f.setSize(400,300);
      f.setTitle("Swing App 06");
      //f.pack();
      f.setVisible(true);

   }

   private class btnListener implements ActionListener{
      @Override
      public void actionPerformed(ActionEvent ae){
         String str;
         str = "<html>";
         str += sRisultati.getText();
         str += "<br>";
         for(int i=1; i<=5; i++){
            str += i + " ";
         }
         str += "<br>";
         str += "</html>";
         sRisultati.setText(str);
         f.pack();
      }
  }

   public static void main(String[] args){
      new sw06();
   }
}