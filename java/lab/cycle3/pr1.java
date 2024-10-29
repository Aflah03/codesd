import java.io.*; class pr1{
  public static void main(String[] args)throws IOException {
    
    FileWriter f = new FileWriter("ABC.txt");
    f.write("d");
    f.write("\nSO this is going to be cool ");
    f.write("\n the last line yeah ");
    f.flush();
    f.close();

    FileReader fr = new FileReader("ABC.txt");
    int x = fr.read();
    while(x!= -1){
      System.out.print((char)x);
      x = fr.read();
    }
    fr.close();
  }
}

