import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class ab extends JFrame{
	public ab(){
		setLayout(new FlowLayout());
		setVisible(true);
		setSize(500,500);
		JLabel l1 = new JLabel("Aflah Muhammed P");
		add(l1);
		setDefaultCloseOperation(3);
	}
}
public class p2{
	public static void main(String[] args) {
		ab obj = new ab();

	}
}