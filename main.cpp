#include <iostream>     // Enables use of cout and cin
#include <string>       // Allows using the string data type
#include "Book.h"       // Includes Book, HardcopyBook, and EBook classes

using namespace std;

// FUNCTION: listBooks
// Description: Loops through the book array and prints each book's details
void listBooks(Book* library[], int size) {
    cout << "\n📚 List of Books:\n";
    for (int i = 0; i < size; i++) {
        cout << "\nBook #" << i + 1 << ":\n";
        library[i]->displayBookDetails();  // Displays each book's info
        cout << "-----------------------------" << endl;
    }
}

int main() {
    Book* library[5];  // Array to store 5 predefined book pointers
    int bookCount = 5; // Fixed number of initial books

    // === Predefined Books ===
    HardcopyBook* book1 = new HardcopyBook();
    book1->setBookDetails("Dom Casmurro", "Machado de Assis", "111");
    book1->setHardcopyDetails(3, "A12");

    HardcopyBook* book2 = new HardcopyBook();
    book2->setBookDetails("The Little Prince", "Saint-Exup\u00e9ry", "222");
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

    // Store the books into the array
    library[0] = book1;
    library[1] = book2;
    library[2] = book3;
    library[3] = book4;
    library[4] = book5;

    // Borrow two books to simulate borrowing state
    book2->borrowBook();  // "The Little Prince"
    book5->borrowBook();  // "Captains of the Sands"

    int choice;
    string inputISBN;

    // === MAIN MENU ===
    do {
        cout << "\n=====================" << endl;
        cout << "     BOOK SYSTEM     " << endl;
        cout << "=====================" << endl;
        cout << "1. List all books" << endl;
        cout << "2. Borrow a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            listBooks(library, bookCount);  // Display the list of books
            break;

        case 2:
            cout << "\nEnter the ISBN of the book to borrow: ";
            cin >> inputISBN;
            {
                bool found = false;
                for (int i = 0; i < bookCount; i++) {
                    if (library[i]->getISBN() == inputISBN) {
                        found = true;
                        if (library[i]->isAvailable()) {
                            library[i]->borrowBook();
                            cout << "✅ Book successfully borrowed!" << endl;
                        } else {
                            cout << "❌ Book is already borrowed." << endl;
                        }
                        break;
                    }
                }
                if (!found) {
                    cout << "❌ Book with ISBN " << inputISBN << " not found." << endl;
                }
            }
            break;

        case 3:
            cout << "\nEnter the ISBN of the book to return: ";
            cin >> inputISBN;
            {
                bool found = false;
                for (int i = 0; i < bookCount; i++) {
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

        case 4:
            cout << "\n👋 Exiting the system. Thank you for using the library!" << endl;
            break;

        default:
            cout << "\n⚠️ Invalid option. Please try again." << endl;
        }

    } while (choice != 4);  // Loop until user selects Exit

    // Clean up allocated memory
    for (int i = 0; i < bookCount; i++) {
        delete library[i];
    }

    return 0;
}
