import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Book implements Serializable {
    // private static final long serialVersionUID = 1L;
    String isbn;
    String title;
    String author;
    double price;
    int pages;
    String publisher;

    public Book(String isbn, String title, String author, double price, int pages, String publisher) {
        this.isbn = isbn;
        this.title = title;
        this.author = author;
        this.price = price;
        this.pages = pages;
        this.publisher = publisher;
    }

    public String getIsbn() {
        return isbn;
    }

    @Override
    public String toString() {
        return "ISBN: " + isbn + ", Title: " + title + ", Author: " + author + ", Price: $" + price + ", Pages: " + pages + ", Publisher: " + publisher;
    }
}

public class BookManager {
    private static final String FILE_PATH = "books.dat";
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;
        
        while (true) {
            System.out.println("\n--- Book Manager ---");
            System.out.println("1. Add a new book");
            System.out.println("2. Search for a book by ISBN");
            System.out.println("3. Update details of a book by ISBN");
            System.out.println("4. Delete a book by ISBN");
            System.out.println("5. Display all books");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline
            
            switch (choice) {
                case 1 -> addBook(scanner);
                case 2 -> searchBook(scanner);
                case 3 -> updateBook(scanner);
                case 4 -> deleteBook(scanner);
                case 5 -> displayAllBooks();
                case 6 -> {
                    scanner.close();
                    System.out.println("Exiting...");
                    return;
                }
                default -> System.out.println("Invalid choice. Try again.");
            }
        }
    }

    // Method to add a new book
    private static void addBook(Scanner scanner) {
        System.out.print("Enter ISBN: ");
        String isbn = scanner.nextLine();
        System.out.print("Enter Title: ");
        String title = scanner.nextLine();
        System.out.print("Enter Author: ");
        String author = scanner.nextLine();
        System.out.print("Enter Price: ");
        double price = scanner.nextDouble();
        System.out.print("Enter Pages: ");
        int pages = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        System.out.print("Enter Publisher: ");
        String publisher = scanner.nextLine();
        
        Book book = new Book(isbn, title, author, price, pages, publisher);
        List<Book> books = readBooksFromFile();
        books.add(book);
        writeBooksToFile(books);
        System.out.println("Book added successfully!");
    }

    // Method to search for a book by ISBN
    private static void searchBook(Scanner scanner) {
        System.out.print("Enter ISBN to search: ");
        String isbn = scanner.nextLine();
        List<Book> books = readBooksFromFile();
        
        for (Book book : books) {
            if (book.getIsbn().equals(isbn)) {
                System.out.println("Book found: " + book);
                return;
            }
        }
        System.out.println("Book with ISBN " + isbn + " not found.");
    }

    // Method to update a book by ISBN
    private static void updateBook(Scanner scanner) {
        System.out.print("Enter ISBN to update: ");
        String isbn = scanner.nextLine();
        List<Book> books = readBooksFromFile();
        
        for (Book book : books) {
            if (book.getIsbn().equals(isbn)) {
                System.out.print("Enter new Title: ");
                book.title = scanner.nextLine();
                System.out.print("Enter new Author: ");
                book.author = scanner.nextLine();
                System.out.print("Enter new Price: ");
                book.price = scanner.nextDouble();
                System.out.print("Enter new Pages: ");
                book.pages = scanner.nextInt();
                scanner.nextLine(); // Consume newline
                System.out.print("Enter new Publisher: ");
                book.publisher = scanner.nextLine();
                
                writeBooksToFile(books);
                System.out.println("Book details updated successfully!");
                return;
            }
        }
        System.out.println("Book with ISBN " + isbn + " not found.");
    }

    // Method to delete a book by ISBN
    private static void deleteBook(Scanner scanner) {
        System.out.print("Enter ISBN to delete: ");
        String isbn = scanner.nextLine();
        List<Book> books = readBooksFromFile();
        
        books.removeIf(book -> book.getIsbn().equals(isbn));
        writeBooksToFile(books);
        System.out.println("Book deleted successfully, if it existed.");
    }

    // Method to display all books
    private static void displayAllBooks() {
        List<Book> books = readBooksFromFile();
        if (books.isEmpty()) {
            System.out.println("No books available.");
        } else {
            System.out.println("All books:");
            for (Book book : books) {
                System.out.println(book);
            }
        }
    }

    // Helper method to read books from file
    private static List<Book> readBooksFromFile() {
        List<Book> books = new ArrayList<>();
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(FILE_PATH))) {
            books = (List<Book>) ois.readObject();
        } catch (FileNotFoundException e) {
            System.out.println("No existing file found, creating a new one.");
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        return books;
    }

    // Helper method to write books to file
