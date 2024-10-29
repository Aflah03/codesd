import java.io.*;
class pr3{
  public static void main(String[] args)throws IOException {
  File f = new File("testpr3.txt");

  int charCount=0;
  int lineCount =0;
  int wordCount=0;

  BufferedReader bf = new BufferedReader(new FileReader(f));
  String line = bf.readLine();
  while(line != null){
    lineCount++;
    charCount += line.length();
    // String[] words = line.split("\\s+");
    String[] words = line.split(" ");
    wordCount+= words.length;
    line = bf.readLine();
  }

  
        System.out.println("Number of characters: " + charCount);
        System.out.println("Number of lines: " + lineCount);
        System.out.println("Number of words: " + wordCount);
        bf.close();
  }
}
