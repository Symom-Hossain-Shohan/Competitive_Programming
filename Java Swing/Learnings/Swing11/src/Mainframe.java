import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Mainframe extends JFrame {

    //ading a text area and a button int the layout
    //setLayout e BorderLayout use kora hoise
    private Textpanel textpanel;
    private JButton btn;
    private Toolbar toolbar;
    public Mainframe()
    {
        //super constructor eita, vitorer string ta pannel er title
        super("Hello, Peter");
        //Panel ta visible kora hoise
        //width ar length set kora hoise and close korle jate program terminate hoy oita kora hoise
        setVisible(true);
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Panel  er moddhe layout add kora hoise
        setLayout(new BorderLayout());
        textpanel = new Textpanel();
        btn = new JButton("Click me!");
        add(textpanel,BorderLayout.CENTER);
        add(btn, BorderLayout.SOUTH);

        //ekhon button er moddhe action listener add kore button e kisu functionality add korbo
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                 textpanel.appendtext("Kire mama, ki khobor!\n");
            }
        });


        //adding toolbar
        toolbar = new Toolbar();
        add(toolbar, BorderLayout.NORTH);

    }
}
