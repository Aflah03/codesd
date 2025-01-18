import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

/**
 * ADDandSubtract
 */
class Frame1 extends JFrame implements ActionListener {
    JLabel l1;
    JTextField t1;
    JTextField t2;
    JButton b1;
    JButton b2;

    Frame1() {
        setSize(500, 500);
        t1 = new JTextField(20);
        t2 = new JTextField(20);
        b1 = new JButton("ADD");
        b2 = new JButton("SUBTRACT");
        l1 = new JLabel("RESULT");
        b1.addActionListener(this);
        b2.addActionListener(this);

        add(t1);
        add(t2);
        add(b1);
        add(b2);
        add(l1);
        setVisible(true);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(3);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == b1) {
            System.out.println("b1");
        }
        if (e.getSource() == b2) {
            System.out.println("B2");
        }
    }
}

public class ADDandSubtract {
    public static void main(String[] args) {
        Frame1 obj = new Frame1();

    }

}
