#include <iostream>       // Allows us to use cout and cin
#include "Book.h"         // Includes our Book class and its subclasses (HardcopyBook, EBook)

using namespace std;      // So we don’t need to write std:: before cout, string, etc.

int main() {
    // We create an array of pointers to Book.
    // These pointers can point to either HardcopyBook or EBook because both inherit from Book.
    Book* library[5];

    // --------- Create a physical book (HardcopyBook) ----------
    HardcopyBook* book1 = new HardcopyBook();  // Dynamically create a HardcopyBook object
    book1->setBookDetails("Dom Casmurro", "Machado de Assis", "111");  // Set title, author, ISBN
    book1->setHardcopyDetails(3, "A12");  // Set number of copies and shelf location

    // --------- Another physical book ----------
    HardcopyBook* book2 = new HardcopyBook();
    book2->setBookDetails("The Little Prince", "Saint-Exupéry", "222");
    book2->setHardcopyDetails(2, "B07");

    // --------- Create an EBook ----------
    EBook* book3 = new EBook();
    book3->setBookDetails("Harry Potter", "J.K. Rowling", "333");
    book3->setEBookDetails("harrypotter.com", "2026-12-31");  // Set download link and license end date

    // --------- Another EBook ----------
    EBook* book4 = new EBook();
    book4->setBookDetails("1984", "George Orwell", "444");
    book4->setEBookDetails("1984books.net", "2025-08-15");

    // --------- Another HardcopyBook ----------
    HardcopyBook* book5 = new HardcopyBook();
    book5->setBookDetails("Captains of the Sands", "Jorge Amado", "555");
    book5->setHardcopyDetails(5, "C22");

    // Add all the books to the library array (as base-class pointers)
    library[0] = book1;
    library[1] = book2;
    library[2] = book3;
    library[3] = book4;
    library[4] = book5;

    // Borrow two books to simulate them being already borrowed
    library[1]->borrowBook();  // Borrow "The Little Prince"
    library[4]->borrowBook();  // Borrow "Captains of the Sands"

    string inputISBN;  // A variable to store the ISBN typed by the user

    // Start the interactive borrowing system
    while (true) {
        // Ask the user to enter the ISBN
        cout << "\nEnter ISBN to borrow a book (or '0' to exit): ";
        cin >> inputISBN;

        // If the user types 0, the system ends
        if (inputISBN == "0") {
            cout << "Exiting system. Thank you!" << endl;
            break;
        }

        bool found = false;  // Track whether we found the book

        // Search for the book by ISBN
        for (int i = 0; i < 5; i++) {
            if (library[i]->getISBN() == inputISBN) {  // If we found the book
                found = true;

                // First, display the book’s current details (with ✅ or ❌)
                library[i]->displayBookDetails();

                // Then, try to borrow it if available
                if (library[i]->isAvailable()) {
                    library[i]->borrowBook();  // Mark it as borrowed
                    cout << "Book successfully borrowed!" << endl;
                } else {
                    cout << "Sorry, this book is already borrowed." << endl;
                }

                break;  // No need to keep searching
            }
        }

        // If no book matched the ISBN, show a message
        if (!found) {
            cout << "Book with ISBN " << inputISBN << " not found in the library." << endl;
        }
    }

    return 0;  // End of program
}
