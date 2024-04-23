package Swing1;

import java.awt.LayoutManager;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.plaf.BorderUIResource;

public class Mainframe extends JFrame {
    private JTextArea textarea;
    private JButton btn;

    public Mainframe() {
        super("Hello, Guys");

        setLayout(getLayout());
        
        ;
        textarea = new JTextArea();
        btn = new JButton("click me!");

        add(textarea);

        add(btn);

        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
}
