import java.io.*;
// of java.io.File
import java.io.IOException;

class pr1{
  public static void main(String[] args)throws Exception {
    // File f = new File("abc.txt");
    // System.out.println(f.exists());
  // f.createNewFile();
  //   System.out.println(f.exists());
  
    File f = new File("subdirectory","newtext.txt");
  System.out.println(f.exists());
  f.createNewFile();
  System.out.println(f.exists());
   }
}
