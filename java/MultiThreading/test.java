class myThread extends Thread{
  public void run(){
    System.out.println("this line is executed by "+ Thread.currentThread().getName());
  }
}

class test{
  public static void main(String[] args) {
    myThread t1 = new myThread();
    t1.setName("child thread");
    t1.start();

    Thread.currentThread().setName("Main Thread");
    System.out.println("this line is executed by "+ Thread.currentThread().getName());
  }
}
