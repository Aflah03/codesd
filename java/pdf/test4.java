class multi implements Runnable{
  static Thread mainThreadReference;
  public void run(){
    System.out.println(Thread.currentThread());
    System.out.println("Thread is running..");

      System.out.println("the value in mainThreadReference is : :"+ mainThreadReference.getName());
  }
  public static void main(String[] args) {
    multi m1 = new multi();
    Thread t1 = new Thread(m1);
    mainThreadReference = Thread.currentThread();

    t1.start();
    System.out.println("MAIN THREADS NAME IS :"+ Thread.currentThread().getName());


    mainThreadReference.setPriority(7);
    System.out.println(mainThreadReference);

    for(int i=0;i<10;i++){
      try{
      System.out.print(i+" ");
      Thread.sleep(1000);

      }catch(InterruptedException e){}
    }
  }
}
