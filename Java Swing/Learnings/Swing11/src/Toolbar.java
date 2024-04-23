import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Toolbar extends JPanel {
    private JButton helloButton, goodbyeButton;
    public Toolbar()
    {
        helloButton = new JButton("Hello");
        goodbyeButton = new JButton("Goodbye");
        setLayout(new FlowLayout(FlowLayout.LEFT));

        add(helloButton);
        add(goodbyeButton);
        helloButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Hello world\n");
            }
        });
    }

}
