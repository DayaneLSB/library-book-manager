#include <iostream>   // Allows input/output operations (e.g., cout)
#include <string>     // Allows using the string data type
using namespace std;  // Avoids needing to write "std::" before things like cout or string

// =============================
// CLASS: Book
// This class represents a book with basic information
// =============================
class Book {
protected:
    string title;       // Title of the book
    string author;      // Author of the book
    string isbn;        // ISBN code (unique identifier)
    bool available;     // Availability status: true = available, false = borrowed
    string dateAdded;   // Date the book was added to the system

public:
    // CONSTRUCTOR: initializes the book with given values
    Book(string t, string a, string i, string av, string d) {
        title = t;        // Set title
        author = a;       // Set author
        isbn = i;         // Set ISBN
        dateAdded = d;    // Set date the book was added

        // Convert availability string to boolean
        if (av == "Available") {
            available = true;
        } else {
            available = false;
        }
    }

    // FUNCTION: displayBookDetails
    // Displays all book information in the console
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
// Runs the test with correct and incorrect book data
// =============================
int main() {
    // Print section title for correct book test
    cout << "=== CORRECT BOOK INFORMATION (EVIDENCE) ===" << endl;

    // Create books with correct data
    Book book1("Dom Casmurro", "Machado de Assis", "111", "Available", "20/01/2024");
    Book book2("The Little Prince", "Saint-Exupéry", "222", "Available", "25/08/2023");
    Book book3("Harry Potter", "J.K. Rowling", "333", "Borrowed", "15/06/2021");

    // Display details of correct books
    book1.displayBookDetails();
    book2.displayBookDetails();
    book3.displayBookDetails();

    // Print section title for incorrect book test
    cout << "=== INCORRECT BOOK INFORMATION (EVIDENCE) ===" << endl;

    // Create books with incorrect or illogical data
    Book wrong1("Casmurro", "Machad", "0101", "No-available", "01/02/2024");
    Book wrong2("The Prince", "Saint", "0202", "Borrowed", "25/08/2000");
    Book wrong3("Mr Harry", "Rowling", "0303", "Available", "15/07/2020");

    // Display details of incorrect books
    wrong1.displayBookDetails();
    wrong2.displayBookDetails();
    wrong3.displayBookDetails();

    return 0;  // End of the program
}
