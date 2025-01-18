class AflahException extends Exception{
     public AflahException(String message){

    super(message);
  }
}
public class test8 {
  static void validate(int age)throws AflahException{
    if(age < 18) {throw new AflahException("Not valid");
    }
    else System.out.println("You can vote");
  }
  public static void main(String[] args) {
    try{

    validate(9);
    }catch(AflahException e){
      System.out.println("you custom exception has been caught");
    }
    System.out.println("rest of the code");
  }
}
