import java.io.*;
class pr2{
  public static void main(String[] args) throws IOException {
    File f  = new File("textpr2.txt");
    FileReader fr = new FileReader(f);
    int x = fr.read();
    int line_number=1;
    System.out.print(line_number++ + ". ");
    while(x!= -1){
      System.out.print((char)x);
      if((char)x=='\n')
          System.out.print(line_number++ + ". ");
      x = fr.read();
    }
    fr.close();
  }
}
