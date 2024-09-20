import java.io.*;
// of java.io.File
class pr1{
  public static void main(String[] args) {
    File f = new File("abc.txt");
    System.out.println(f.exists());
  f.createNewFile();
    System.out.println(f.exists());
  }
  
}
