package cycle2;
interface Animal{
  void eat();
  void sleep();
}
interface Pet extends Animal{
  void play();
}

class Cat implements Pet{
  public void eat(){
    System.out.println("The cat is eating");
  } 
  public void sleep(){
    System.out.println("The cat is sleeping");
  } 
  public void play(){
    System.out.println("The cat is playing");
  } 
}

public class pr5{
  public static void main(String[] args) {
    Cat mycat = new Cat();
    mycat.eat();
  }
}
