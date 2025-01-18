import java.io.*;
import java.util.*;

class Sender1{
	public void send(String msg){
		System.out.println("Sending " + msg);
		try{
			Thread.sleep(1000);

		}catch(Exception e){};
		System.out.println("Sent " + msg);
	}
}

class Threadhelper extends Thread{
	private String message;
	Sender1 sender;
	Threadhelper(String message,Sender1 sender){
		this.message = message;
		this.sender = sender;
	}

	public void run(){
		synchronized(sender){
			sender.send(message);
		}
	}
}


class example1{
	public static void main(String[] args){
		Sender1 s = new Sender1();
		Threadhelper t1 = new Threadhelper("Hi",s);
		Threadhelper t2 = new Threadhelper("Bye",s);

		t1.start();
		t2.start();
	}
}