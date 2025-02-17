import java.awt.*;
import java.awt.event.MouseListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.*;

public class awt01 {
    Frame win;
    int cnt = 0;

    public awt01(){
        win = new Frame("Prova AWT UI");
        win.setSize(300,300);
        win.setVisible(true);
        

        Button btn1 = new Button("Click Me!");

        win.add(btn1);

        btn1.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e){
                cnt++;
                btn1.setLabel("Clicked me: "+Integer.toString(cnt));
            }
        });

        win.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
    }

    public static void main(String[] args){
        new awt01();
    }
}
