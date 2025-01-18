import java.io.*;
import java.util.Scanner;
import java.util.*;

class Book implements Serializable{
    // private static final long serialVersinUID = 1L;
    String title;
    String isbn;
    int pages;

    public Book(String title,String isbn,int pages){
        this.title = title;
        this.isbn = isbn;
        this.pages = pages;
    }
    public String getIsbn(){
        return isbn;
    }
    @Override
    public String toString(){
        return "ISBN: " + isbn + ", Title: " + title + "pages" +pages;
    }
}

public class testfile{
    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       int choice;
       
       while(true){

        choice =sc.nextInt()
        switch(choice){
            case 1:
                addBook(sc);
                break;
            case 2:
                searchBook(sc);
                break;
            case 3:
                updateBook(sc);
                break;
            case 4:
                deleteBook(sc);
                break;
            case 5:
               sc.close();
               System.out.println("Exiting....");
                return;
            
        }
       }
    }
    private static void addBook(Scanner sc){
      System.out.print("Enter ISBN: ");
        String isbn = sc.nextLine();
        System.out.print("Enter Title: ");
        String title = sc.nextLine();
        System.out.println("Enter pages: ");
        int pages = sc.nextInt();

        Book newBook  = new Book(title,isbn,pages);
        List<Book> books = readBooksFromFile();
        books.add(newBook);
        writeBooksToFile(books);
        System.out.println("Book added successfully!");
    }
    private static List<Book> readBooksFromFile(){
        List<Book> books = new ArrayList<>();
        try 
            (ObjectInputStream ois = new ObjectInputStream(new FileinputStream("BOOKS.dat")) ){

            books = 
            }
        } catch (Exception e) {
        }
        return books;
    }
}


private static void WriteBooksTOFile(List<Book> books){
    try{
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("FILE.data"))
        oos.writeObject(books);
    }catch(IOException e){
        e.printStackTrace();
    }
