class First{
  synchronized   public void display(String msg){
    System.out.print("["+msg);
    try{
      Thread.sleep(500);
      
    }catch(InterruptedException e){}
    System.out.println("]");
  }
}

class Second extends Thread{
  String msg;
  First firstObj;
  Second(String msg,First firstObj){
    this.msg = msg;
    this.firstObj = firstObj;
    this.start();
  }
  public void run(){
    firstObj.display(msg);
  }
}

public class test5 {
  public static void main(String[] args) {
    First f1 = new First();
    Second s1 = new Second("Welcome",f1);
    Second s2 = new Second("NEw",f1);
    Second s3 = new Second("Programmer",f1);
  }
}
