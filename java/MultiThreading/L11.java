class threadB extends Thread{
  int total = 0;
  public void run(){
    for(int i=0;i<100;i++){
      total+= i;
    }
  }
}
public class L11{
  public static void main(String[] args)throws InterruptedException {
   threadB b = new threadB();
   b.start();
  Thread.sleep(0,1); //0ms , 1 ns
   System.out.println(b.total);
  }
}

