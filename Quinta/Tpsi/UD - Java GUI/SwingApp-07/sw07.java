import java.awt.*;
import javax.swing.*;
import java.awt.event.*;


public class sw07 extends JFrame{
   JFrame f;
   JPanel p1, p2, p3;
   JButton btn;
   public sw07(){
      f = new JFrame();
      f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      f.setTitle("Swing App 07");
      f.setSize(600,300);
      f.setLayout(new GridLayout(3,1));
      //setLayout(new BoxLayout(f, BoxLayout.Y_AXIS));

      p1 = new JPanel();
      p1.setBackground(new Color(100,200,69));
      p1.setLayout(new FlowLayout(FlowLayout.RIGHT, 10, 10));
      for(int i=1; i<=5; i++)
         p1.add(new JButton("Bottone "+i));

      p2 = new JPanel();
      p2.setBackground(Color.GREEN);
      p2.setLayout(new FlowLayout(FlowLayout.LEFT, 10, 10));
      p2.setAlignmentX(Component.LEFT_ALIGNMENT);
      p2.add(new JButton("Bottone 2"));

      p3 = new JPanel();
      p3.setBackground(Color.MAGENTA);
      p3.setLayout(new FlowLayout(FlowLayout.LEFT, 20, 20));
      p3.add(new JButton("Bottone 3"));

      f.add(p1);
      f.add(p2);
      f.add(p3);
      f.setResizable(false);
      //f.pack();
      f.setVisible(true);
   }
   public static void main(String[] args){
      new sw07();
   }
}