import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class p3{
	public static void main(String[] args) {
		Addition obj = new Addition();	
	}
}

class Addition extends JFrame implements ActionListener{
	JTextField t1;
	JTextField t2;///just to increase the scope we are 
	//definging this outside
	JButton b1;

	Addition(){
		 t1 = new JTextField(10);
		 t2 = new JTextField(10);
		 b1 = new JButton("ok");
		add(t1);
		add(t2);
		add(b1);

		b1.addActionListener(this);



		setVisible(true);
		setSize(500,500);
		setLayout(new FlowLayout());
		setDefaultCloseOperation(3);
		JLabel l5 = new JLabel("Aflah Muhammed P");
		add(l5);
	}
	public void actionPerformed(ActionEvent ae){
		int num1 = Integer.parseInt(t1.getText());
		int num2 = Integer.parseInt(t2.getText());
		int value = num1 + num2;
		
	}

}