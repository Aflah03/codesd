class myThread4 extends Thread{
  public void run(){
    for(int i=0;i<10;i++){
      System.out.println("Aflah thread");
      try{
        Thread.sleep(200);
      }catch(InterruptedException e){}
    }
  }
}

class Jointest{
  public static void main(String[] args)throws InterruptedException {
    myThread4 t =  new myThread4();
    t.start();
    t.join(500); //main thread waits until thread t finishes excecution
              
    for(int i=0;i<10;i++){
      System.out.println("Main thread");
    }
  }
}
