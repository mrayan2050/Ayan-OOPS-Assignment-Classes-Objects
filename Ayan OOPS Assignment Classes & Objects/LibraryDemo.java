class Book {

    private String title;
    private String authors[];
    private int pages;
    private double price;
    private String publisher;
    private String isbn;
    private int copies;

    Book(String title, String authors[], int pages,
         double price, String publisher,
         String isbn, int copies) {

        this.title = title;
        this.authors = authors;
        this.pages = pages;
        this.price = price;
        this.publisher = publisher;
        this.isbn = isbn;
        this.copies = copies;
    }

    String getTitle() {
        return title;
    }

    double getPrice() {
        return price;
    }

    int getCopies() {
        return copies;
    }

    void display() {

        System.out.println("Title: " + title);

        System.out.print("Authors: ");
        for (int i = 0; i < authors.length; i++) {
            System.out.print(authors[i] + " ");
        }

        System.out.println("\nPages: " + pages);
        System.out.println("Price: " + price);
        System.out.println("Publisher: " + publisher);
        System.out.println("ISBN: " + isbn);
        System.out.println("Copies Available: " + copies);
        System.out.println();
    }
}

class Library {

    Book books[] = new Book[20];
    int count = 0;

    void add(Book b) {
        books[count] = b;
        count++;
    }

    void remove(String title) {

        for (int i = 0; i < count; i++) {

            if (books[i].getTitle().equals(title)) {

                for (int j = i; j < count - 1; j++) {
                    books[j] = books[j + 1];
                }

                count--;
                System.out.println("Book Removed");
                return;
            }
        }
    }

    double totalPrice() {

        double total = 0;

        for (int i = 0; i < count; i++) {
            total += books[i].getPrice() * books[i].getCopies();
        }

        return total;
    }

    void displayBooks() {

        for (int i = 0; i < count; i++) {
            books[i].display();
        }
    }
}

public class LibraryDemo {

    public static void main(String[] args) {

        Library lib = new Library();

        lib.add(new Book(
                "Java Programming",
                new String[]{"James Gosling"},
                500,
                450.0,
                "Sun Publisher",
                "ISBN101",
                3));

        lib.add(new Book(
                "Data Structures",
                new String[]{"Mark Allen", "John Smith"},
                350,
                550.0,
                "Tech Publisher",
                "ISBN102",
                2));

        lib.add(new Book(
                "Operating System",
                new String[]{"Galvin"},
                600,
                700.0,
                "McGraw Hill",
                "ISBN103",
                4));

        System.out.println("Library Books Details:\n");

        lib.displayBooks();

        System.out.println("Total Price of All Books = " + lib.totalPrice());

        System.out.println("\nCopies Available:");

        for (int i = 0; i < lib.count; i++) {

            System.out.println(
                    lib.books[i].getTitle()
                    + " : "
                    + lib.books[i].getCopies()
                    + " copies");
        }
    }
}