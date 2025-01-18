import java.io.*;
import java.util.*;

class Sender{
	public void send(String msg){
		{
			System.out.println("Sending " + msg);
		}
		try{
			Thread.sleep(1000);
		}catch(InterruptedException e){
			System.out.println("Thread interrupted");

		}
			System.out.println("Sent"+ msg);
	}
}


class ThreadedSend extends Thread{
	Sender sender;
	private	String meassage;

	ThreadedSend(String m,Sender obj){
		sender = obj;
		meassage = m;
	}
	public void run(){
		synchronized(sender){
			sender.send(meassage);
		}
	}
}

class example{
	public static void main(String[] args){
		Sender s = new Sender();
		ThreadedSend t1 = new ThreadedSend("HI",s);
		ThreadedSend t2 = new ThreadedSend("Bye",s);

		t1.start();
		t2.start();

		try{
			t1.join();
			t2.join();
		}catch(Exception e){}
	}
}