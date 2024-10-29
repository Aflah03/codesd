class myThread1 extends Thread{
  public void run(){
    System.out.println("Child thread priority is : "+ Thread.currentThread().getPriority());
  }
}
class test1{
  public static void main(String[] args) {
    myThread1 t1 = new myThread1();
    t1.setPriority(8);
    t1.start();

    System.out.println("Main thread priority is : "+ Thread.currentThread().getPriority());
  }
}
