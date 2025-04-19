#include <iostream>     // Allows input and output (e.g., cout)
#include <string>       // Allows use of string data type
using namespace std;

// =============================
// CLASS: Book
// Represents a book with basic attributes and functionality
// =============================
class Book {
protected:
    string title;        // Book title
    string author;       // Book author
    string isbn;         // Unique book code (ISBN)
    bool available;      // True if available, false if borrowed
    string dateAdded;    // Date the book was added to the system

public:
    // CONSTRUCTOR: Initializes the book with all values
    Book(string t, string a, string i, string av, string d) {
        title = t;
        author = a;
        isbn = i;
        dateAdded = d;

        // Converts availability string to boolean
        if (av == "Available") {
            available = true;
        } else {
            available = false;
        }
    }

    // FUNCTION: displayBookDetails
    // Displays all the book details on the screen
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (available ? "Available ✅" : "Borrowed ❌") << endl;
        cout << "Date Added: " << dateAdded << endl << endl;
    }
};

// =============================
// MAIN FUNCTION
// =============================
int main() {
    // ==========================================
    // ARRAY 1: BOOKS IN ASCENDING ORDER (A to Z)
    // ==========================================
    Book* ascending[3] = {
        new Book("Dom Casmurro", "Machado de Assis", "111", "Available", "20/01/2024"),
        new Book("Harry Potter", "J.K. Rowling", "333", "Borrowed", "15/06/2021"),
        new Book("The Little Prince", "Saint-Exupéry", "222", "Available", "25/08/2023")
    };

    // ==========================================
    // ARRAY 2: BOOKS IN DESCENDING ORDER (Z to A)
    // ==========================================
    Book* descending[3] = {
        new Book("The Little Prince", "Saint-Exupéry", "222", "Available", "25/08/2023"),
        new Book("Harry Potter", "J.K. Rowling", "333", "Borrowed", "15/06/2021"),
        new Book("Dom Casmurro", "Machado de Assis", "111", "Available", "20/01/2024")
    };

    // ==========================================
    // ARRAY 3: BOOKS IN MIXED ORDER (as requested)
    // Harry, The Little, Dom
    // ==========================================
    Book* mixed[3] = {
        new Book("Harry Potter", "J.K. Rowling", "333", "Borrowed", "15/06/2021"),
        new Book("The Little Prince", "Saint-Exupéry", "222", "Available", "25/08/2023"),
        new Book("Dom Casmurro", "Machado de Assis", "111", "Available", "20/01/2024")
    };

    // Display books in ASCENDING order (as added)
    cout << "=== BOOKS IN ASCENDING ORDER ===" << endl;
    for (int i = 0; i < 3; i++) {
        ascending[i]->displayBookDetails();
    }

    // Display books in DESCENDING order (as added)
    cout << "=== BOOKS IN DESCENDING ORDER ===" << endl;
    for (int i = 0; i < 3; i++) {
        descending[i]->displayBookDetails();
    }

    // Display books in MIXED order (as added: Harry, The Little, Dom)
    cout << "=== BOOKS IN MIXED ORDER ===" << endl;
    for (int i = 0; i < 3; i++) {
        mixed[i]->displayBookDetails();
    }

    return 0;  // End of the program
}

