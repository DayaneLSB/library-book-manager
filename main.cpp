#include <iostream>     // Allows us to use cout (to print) and cin (to read input)
#include "Book.h"       // Includes our Book class and its child classes (HardcopyBook, EBook)

using namespace std;    // So we can write cout, string, etc. without using std:: before

int main() {
    // ARRAY: A container that holds multiple items.
    // Here we are creating an array of 5 pointers to Book objects.
    // Each item can point to either a HardcopyBook or EBook because they both inherit from Book.
    Book* library[5];

    // ----------------- Creating books and setting details -----------------

    // Create a hardcopy book
    HardcopyBook* book1 = new HardcopyBook();  // "new" creates the object in memory (dynamic allocation)
    book1->setBookDetails("Dom Casmurro", "Machado de Assis", "111");  // Set title, author, ISBN
    book1->setHardcopyDetails(3, "A12");  // Set number of copies and shelf location

    // Another hardcopy book
    HardcopyBook* book2 = new HardcopyBook();
    book2->setBookDetails("The Little Prince", "Saint-Exupéry", "222");
    book2->setHardcopyDetails(2, "B07");

    // Create an eBook
    EBook* book3 = new EBook();
    book3->setBookDetails("Harry Potter", "J.K. Rowling", "333");
    book3->setEBookDetails("harrypotter.com", "2026-12-31");  // Set download link and license expiry

    // Another eBook
    EBook* book4 = new EBook();
    book4->setBookDetails("1984", "George Orwell", "444");
    book4->setEBookDetails("1984books.net", "2025-08-15");

    // Another hardcopy book
    HardcopyBook* book5 = new HardcopyBook();
    book5->setBookDetails("Captains of the Sands", "Jorge Amado", "555");
    book5->setHardcopyDetails(5, "C22");

    // Store all books in the array (as Book pointers)
    library[0] = book1;
    library[1] = book2;
    library[2] = book3;
    library[3] = book4;
    library[4] = book5;

    // ----------------- Simulate borrowed books -----------------
    // Let's pretend that some books were already borrowed
    library[1]->borrowBook();  // "The Little Prince"
    library[4]->borrowBook();  // "Captains of the Sands"

    // ----------------- Start interactive menu -----------------

    int choice;           // To store the user's choice from the menu
    string inputISBN;     // To store ISBN entered by the user

    // DO-WHILE LOOP: Repeats the menu until user chooses to exit
    do {
        // Show menu options
        cout << "\n=====================\n";
        cout << "     BOOK SYSTEM     \n";
        cout << "=====================\n";
        cout << "1. List all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // SWITCH: chooses what to do based on the number the user typed
        switch (choice) {
        case 1:
            // List all books
            cout << "\n--- Book List ---\n";
            for (int i = 0; i < 5; i++) {
                cout << "\nBook #" << i + 1 << endl;
                library[i]->displayBookDetails();  // Calls the function to show book info
            }
            break;

        case 2:
            // Borrow a book
            cout << "\nEnter the ISBN of the book you want to borrow: ";
            cin >> inputISBN;

            {
                bool found = false;  // To check if we found the book
                for (int i = 0; i < 5; i++) {
                    if (library[i]->getISBN() == inputISBN) {
                        found = true;
                        if (library[i]->isAvailable()) {
                            library[i]->borrowBook();  // Change status to borrowed
                            cout << "Book successfully borrowed!" << endl;
                        } else {
                            cout << "Sorry, this book is already borrowed." << endl;
                        }
                        break;  // Stop searching
                    }
                }
                if (!found) {
                    cout << "Book with ISBN " << inputISBN << " not found." << endl;
                }
            }
            break;

        case 3:
            // Return a book
            cout << "\nEnter the ISBN of the book you want to return: ";
            cin >> inputISBN;

            {
                bool found = false;
                for (int i = 0; i < 5; i++) {
                    if (library[i]->getISBN() == inputISBN) {
                        found = true;
                        library[i]->returnBook();  // Mark the book as available again
                        cout << "Book successfully returned!" << endl;
                        break;
                    }
                }
                if (!found) {
                    cout << "Book with ISBN " << inputISBN << " not found." << endl;
                }
            }
            break;

        case 4:
            // Exit the program
            cout << "Exiting the system. Thank you for using the library!" << endl;
            break;

        default:
            // If user types something invalid
            cout << "Invalid option. Please try again." << endl;
        }

    } while (choice != 4);  // The loop stops only when the user chooses "4" to exit

    return 0;  // End of the program
}
