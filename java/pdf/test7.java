public class test7 {
  public static void main(String[] args) {
    int[] myNumbers= {1,2,3};
    try{

    System.out.println(myNumbers[10]);
    }catch(ArrayIndexOutOfBoundsException e){}
    //exception should go from most specific to leas specific
    finally{
      System.out.println("wwosh done");
    }





        try{

    System.out.println(10/0);
    }catch(ArrayIndexOutOfBoundsException e){}
    //exception should go from most specific to leas specific
    catch(Exception e){
      System.out.println("Some exception occured");
    }
    finally{
      System.out.println("wwosh done");
    }

  }
}
