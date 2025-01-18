class  ThreadA extends Thread{
	private Object lock;
	ThreadA(Object lock){
		this.lock = lock;

	}
	public void run(){
		try{
			for(int i=0;i<9;i++){
			synchronized(lock){
			

				System.out.print(Thread.currentThread().getName() + " ");


				lock.notify();

				if(i<8)
				lock.wait();
			}
			Thread.sleep(500);
			}
		}catch (Exception e){

			 Thread.currentThread().interrupt();
		}
	}
}

class ThreadB extends Thread{
	Object lock;
	ThreadB(Object lock){
		this.lock = lock;
	}
	public void run(){
		try{
		synchronized(lock){
			for(int i=0;i<9;i++){
		

				System.out.print(Thread.currentThread().getName() + " ");
				System.out.println();	


				lock.notify();
				if(i<8)
				lock.wait();
			}
			Thread.sleep(500);

		}
		}catch(Exception e){

			 Thread.currentThread().interrupt();
		}
	}

}
public class todaysq{
	public static void main(String[] args){
		Object obj = new Object();

		ThreadA a = new ThreadA(obj);
		ThreadB b = new ThreadB(obj);

		a.start();
		b.start();

		// try{
		// 	a.join();
		// 	b.join();
		// }catch(InterruptedException e){}
	}
}