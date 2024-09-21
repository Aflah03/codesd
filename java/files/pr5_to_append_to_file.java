package classes;
import java.io.*;
class pr5 {
   public static void main(String[] args)throws IOException{
    FileWriter fw = new FileWriter("pr5_file.txt",true); //now appaend will be performed 
    fw.write(100);//to write charecter , 100 is unicode
    fw.write('\n');
    fw.write("Aflah\nSoftware Solutions");
    fw.write('\n');
    char[] ch = {'a','b','c'};
    fw.write(ch);
    fw.write('\n');
    fw.flush();
    fw.close();
   }
  
}

