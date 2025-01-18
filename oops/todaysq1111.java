class ThreadAAA extends Thread{
    Object lock;
    ThreadAAA(Object lock){
        this.lock = lock;
    }
    public void run(){
        try{
            synchronized(lock){
                for (int sp = 0; sp < 10; sp++) {
                    System.out.println(Thread.currentThread().getName() + " ");

                    lock.notify();
                    if(sp< 9)
                    lock.wait();
                Thread.sleep(200);
                }
            }

            }catch(Exception e){
                e.printStackTrace();
            }
        }
}
class ThreadBBB extends Thread{
    Object lock;
    ThreadBBB(Object lock){
        this.lock = lock;
    }
    public void run(){
        try{
            synchronized(lock){
                for (int sp = 0; sp < 10; sp++) {
                    System.out.println(Thread.currentThread().getName() + " ");

                    lock.notify();
                    if(sp< 9)
                    lock.wait();
                Thread.sleep(200);
                }
            }

            }catch(Exception e){
                e.printStackTrace();
            }
        }
}

public class todaysq1111 {
    public static void main(String[] args) {
        Object obj = new Object();
        ThreadAAA t1 = new ThreadAAA(obj);
        ThreadBBB t2 = new ThreadBBB(obj);
        t1.start();
        t2.start();
        
    }
}
