import java.io.*;
// of java.io.File
import java.io.IOException;

class pr1{
  public static void main(String[] args)throws IOException {
    // File f = new File("abc.txt");
    // System.out.println(f.exists());
  // f.createNewFile();
  //   System.out.println(f.exists());
  
    File f = new File("subdirectory","newtext.txt");
  System.out.println(f.exists());
  f.createNewFile();
  System.out.println(f.exists());

  FileWriter fw = new FileWriter(f);

  fw.write(100);
  fw.write("\nGuys this is my second thing we will be doing");
  fw.flush();
  fw.close();

  FileReader fr = new FileReader(f);
  int x = fr.read();
  while(x!=-1){
    System.out.print((char)x);
    x = fr.read();
  }

  fr.close();
   }
}
