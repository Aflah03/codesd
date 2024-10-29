import java.io.*;
class pr3{
  public static void main(String[] args)throws Exception {
  //not interested to check any exceptions , thats why throws     
    int count=0;
    File f = new File("/media/aflah/Data/z_linux/codes/java/");
    // File f = new File("files");
    String[] s = f.list();
    for(String s1: s){
      count++;
      System.out.println(s1);
    }
    System.out.println("total"+ " "+count+" files nad directories\n" );

    System.out.println("Files in it are:  \n");
    count=0;
    for(String s1:s){
      File f1 = new File(f,s1);
      if(f1.isDirectory()){
        count++;
        System.out.println(s1);
      }
    }
    System.out.println("toatal "+ count+" derectroires");
  }
}
