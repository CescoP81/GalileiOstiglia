import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class app02 extends JFrame {
   JFrame f;
   JLabel l;
   JButton btn;
   int cnt_clicks;

   public app02(){
      f = new JFrame();
      l = new JLabel("Applicazione di prova");
      btn = new JButton("Cliccami");
      cnt_clicks = 0;
      f.add(l);
      btn.addActionListener(new btnListener());
      f.add(btn);
      f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      f.setLayout(new FlowLayout());
      f.setSize(300,300);
      f.setTitle("Prima Application");
      f.setVisible(true);
   }

   private class btnListener implements ActionListener{
      @Override
      public void actionPerformed(ActionEvent ev){
          cnt_clicks++;
          btn.setText("Cliccato "+cnt_clicks+" volte.");
      }
  }

   public static void main(String[] args){
      new app02();
   }
}
