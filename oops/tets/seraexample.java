
import java.io.*;

public class seraexample {
    
   public static void main(String[] args) throws IOException{
    Save s1 = new Save();
    s1.i = 4;
    File f = new File("obj.txt");
    ObjectOutputStream  oos1= new ObjectOutputStream(new FileOutputStream(f)); 
    oos1.writeObject(s1);
    oos1.close();

    ObjectInputStream ois1= new ObjectInputStream(new FileInputStream(f));
    try {
        
    Save s2 = (Save)ois1.readObject();
    System.out.println(s2.i);
    } catch (Exception e) {
    }
    ois1.close();
   } 
  
}

class Save implements Serializable{
    int i;
}
