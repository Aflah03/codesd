import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

 class p4{
	public static void main(String[] args) {
		RadioDemo rd = new RadioDemo();		
	}
}

class RadioDemo extends JFrame{
	JTextField t1;
	JButton b;
	JRadioButton r1,r2;
	JLabel l;
	JCheckBox c1,c2;
	RadioDemo(){
		t1 = new JTextField(15);
		b= new JButton("OK");
		r1 = new JRadioButton("Male");
		r2 = new JRadioButton("Female");
		ButtonGroup bg = new ButtonGroup();
		bg.add(r1);
		bg.add(r2);
		l = new JLabel("Greeting");
		c1= new JCheckBox("Reading");
		c2 = new JCheckBox("Writing");



		add(t1);
		add(r1);
		add(r2);
		add(c1);
		add(c2);
		add(b);
		add(l);


		setVisible(true);
		setSize(500,500);
		setLayout(new FlowLayout());
		setDefaultCloseOperation(3);

		b.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e){
				String name = t1.getText();

				if(r1.isSelected()){
					name = "Mr. "+ name;
				}
				else{
					name = "Mrs." + name;
				}

				if(c1.isSelected()){
					name+=" Reader";
				}

				if(c2.isSelected()){
					name+=" Writer";
				}
				l.setText(name);
			}
		});
	}
}