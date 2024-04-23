import javax.swing.*;
import java.awt.*;

public class Textpanel extends JPanel {
    private JTextArea textArea;
    public Textpanel()
    {
        textArea = new JTextArea();
        setLayout(new BorderLayout());
        add( new JScrollPane(textArea), BorderLayout.CENTER);


    }
    public void appendtext(String text)
    {
        textArea.append(text);
    }


}
