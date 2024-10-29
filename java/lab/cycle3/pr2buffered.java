import java.io.*;
class pr2buffered {
  public static void main(String[] args)throws IOException {
    // FileWriter fw = new FileWriter("textpr2.txt");
    FileReader fr = new FileReader("textpr2.txt");
    BufferedReader br = new BufferedReader(fr);
    
    int line_number=1;
    String line = br.readLine();
    while(line!= null){
    System.out.print(line_number++ + " ");
      System.out.println(line);
      line = br.readLine();
    }
    br.close();
  } 
}
