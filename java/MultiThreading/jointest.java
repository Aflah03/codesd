class myThread3 extends Thread{
  public void run(){
    for(int i=0;i<10;i++){

    System.out.println("child method");
    main.join();

    }
  }
}

class jointest{
  public static void main(String[] args) {
    myThread3 t1 = new myThread3();
    t1.start();
    Thread t = Thread.currentThread();

    for(int i=0;i<10;i++){

    System.out.println("Main method");
    }
  }
}
