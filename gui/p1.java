import java.awt.FlowLayout;
import javax.swing.*;
class p1{
    public static void main(String[] args) {
        ABC obj = new ABC();
    }
}
class ABC extends JFrame{ //initally it uses cardlayout
    ABC(){
        setLayout(new FlowLayout());
        JLabel l = new JLabel("Hello world");
        JLabel l1 = new JLabel("Aflah Muhammed P");
        add(l);
        add(l1);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //or instaead of JFram.EXIT_ON_CLOSE just write 3
        setVisible(true);
        setSize(400,400);
    }
}