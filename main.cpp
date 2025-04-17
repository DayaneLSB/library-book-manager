#include <iostream>     // Allows us to use cout and cin
#include "Book.h"       // Includes our Book and its subclasses (HardcopyBook, EBook)

using namespace std;    // So we can write cout, string, etc., without "std::"

// Main function: this is where the program starts running
int main() {
    // Create an array of 5 Book pointers (can store both Hardcopy and EBook objects)
    Book* library[5];

    // --------- Create books and set their details ---------
    HardcopyBook* book1 = new HardcopyBook();
    book1->setBookDetails("Dom Casmurro", "Machado de Assis", "111");
    book1->setHardcopyDetails(3, "A12");

    HardcopyBook* book2 = new HardcopyBook();
    book2->setBookDetails("The Little Prince", "Saint-Exupéry", "222");
    book2->setHardcopyDetails(2, "B07");

    EBook* book3 = new EBook();
    book3->setBookDetails("Harry Potter", "J.K. Rowling", "333");
    book3->setEBookDetails("harrypotter.com", "2026-12-31");

    EBook* book4 = new EBook();
    book4->setBookDetails("1984", "George Orwell", "444");
    book4->setEBookDetails("1984books.net", "2025-08-15");

    HardcopyBook* book5 = new HardcopyBook();
    book5->setBookDetails("Captains of the Sands", "Jorge Amado", "555");
    book5->setHardcopyDetails(5, "C22");

    // Store books in the array
    library[0] = book1;
    library[1] = book2;
    library[2] = book3;
    library[3] = book4;
    library[4] = book5;

    // Simulate some books already borrowed
    library[1]->borrowBook();  // The Little Prince
    library[4]->borrowBook();  // Captains of the Sands

    // -------------- Show books immediately at program start --------------
    cout << "\n📚 Welcome to the Book Library System!" << endl;
    cout << "\nHere are the books currently in our library:\n";

    for (int i = 0; i < 5; i++) {
        cout << "\nBook #" << i + 1 << endl;
        library[i]->displayBookDetails();  // Show book info
    }

    // -------------- Start the interactive menu --------------
    int choice;
    string inputISBN;

    do {
        // Show user options after listing the books
        cout << "\n=====================\n";
        cout << "       ACTIONS       \n";
        cout << "=====================\n";
        cout << "1. Borrow a book\n";
        cout << "2. Return a book\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter the ISBN of the book you want to borrow: ";
            cin >> inputISBN;

            {
                bool found = false;
                for (int i = 0; i < 5; i++) {
                    if (library[i]->getISBN() == inputISBN) {
                        found = true;
                        if (library[i]->isAvailable()) {
                            library[i]->borrowBook();
                            cout << "✅ Book successfully borrowed!" << endl;
                        } else {
                            cout << "❌ Sorry, this book is already borrowed." << endl;
                        }
                        break;
                    }
                }
                if (!found) {
                    cout << "❌ Book with ISBN " << inputISBN << " not found." << endl;
                }
            }
            break;

        case 2:
            cout << "\nEnter the ISBN of the book you want to return: ";
            cin >> inputISBN;

            {
                bool found = false;
                for (int i = 0; i < 5; i++) {
                    if (library[i]->getISBN() == inputISBN) {
                        found = true;
                        library[i]->returnBook();
                        cout << "✅ Book successfully returned!" << endl;
                        break;
                    }
                }
                if (!found) {
                    cout << "❌ Book with ISBN " << inputISBN << " not found." << endl;
                }
            }
            break;

        case 3:
            cout << "\n👋 Exiting the system. Thank you for using our library!" << endl;
            break;

        default:
            cout << "\n⚠️ Invalid option. Please try again." << endl;
        }

    } while (choice != 3);  // Repeat until the user chooses to exit

    return 0;
}
