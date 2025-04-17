#include <iostream>     // Allows us to use cout (to print) and cin (to read input)
#include <iomanip>      // Allows formatting output using setw (column width)
#include <algorithm>    // Allows sorting using sort()
#include "Book.h"       // Includes our Book class and its subclasses

using namespace std;    // So we can use cout, cin, string, etc., without "std::"

// FUNCTION: listBooks
// This helper function displays all books one by one, showing full details
void listBooks(Book* library[], int size) {
    cout << "\n📚 Listing all books:\n";
    for (int i = 0; i < size; i++) {
        cout << "\nBook #" << i + 1 << ":\n";
        library[i]->displayBookDetails();
        cout << "-----------------------------" << endl;
    }
}

int main() {
    Book* library[5];  // ARRAY: holds 5 book pointers (can be EBook or HardcopyBook)

    // --------------------- Create and setup books ---------------------
    // Each book is created and its details are set using setBookDetails()
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

    // Simulate borrowed books
    library[1]->borrowBook();  // Borrow "The Little Prince"
    library[4]->borrowBook();  // Borrow "Captains of the Sands"

    int choice;           // Stores the user's menu selection
    string inputISBN;     // Stores the ISBN entered by the user

    // DO-WHILE LOOP: shows the menu until user chooses to exit
    do {
        // Display the main menu
        cout << "\n=====================" << endl;
        cout << "     BOOK SYSTEM     " << endl;
        cout << "=====================" << endl;
        cout << "1. List all books" << endl;
        cout << "2. Borrow a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. Sort books" << endl;
        cout << "   a. Ascending" << endl;
        cout << "   b. Descending" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // SWITCH: executes the case that matches user's input
        switch (choice) {
        case 1:
            listBooks(library, 5);  // Show all books with full details
            break;

        case 2:
            // Borrow a book using ISBN
            cout << "\nEnter the ISBN of the book you want to borrow: ";
            cin >> inputISBN;
            {
                bool found = false;  // BOOL: tracks if a match is found
                for (int i = 0; i < 5; i++) {
                    if (library[i]->getISBN() == inputISBN) {
                        found = true;
                        if (library[i]->isAvailable()) {
                            library[i]->borrowBook();  // Mark as borrowed
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

        case 3:
            // Return a borrowed book using ISBN
            cout << "\nEnter the ISBN of the book you want to return: ";
            cin >> inputISBN;
            {
                bool found = false;
                for (int i = 0; i < 5; i++) {
                    if (library[i]->getISBN() == inputISBN) {
                        found = true;
                        library[i]->returnBook();  // Mark as available again
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
            // Sort books by title
            char sortChoice;  // Variable to hold 'a' or 'b'
            cout << "\nEnter 'a' for Ascending or 'b' for Descending: ";
            cin >> sortChoice;

            // IF: Sort in ascending order by title
            if (sortChoice == 'a') {
                sort(library, library + 5, [](Book* a, Book* b) {
                    return a->getTitle() < b->getTitle();  // compare titles alphabetically
                });
                cout << "\n📚 Books sorted in ascending order by title.\n";
                listBooks(library, 5);
            }
            // ELSE IF: Sort in descending order by title
            else if (sortChoice == 'b') {
                sort(library, library + 5, [](Book* a, Book* b) {
                    return a->getTitle() > b->getTitle();  // reverse alphabetical
                });
                cout << "\n📚 Books sorted in descending order by title.\n";
                listBooks(library, 5);
            }
            // ELSE: invalid input for sort
            else {
                cout << "\n⚠️ Invalid sort option. Please enter 'a' or 'b'." << endl;
            }
            break;

        case 5:
            // Exit the system
            cout << "\n👋 Exiting the system. Thank you for using our library!" << endl;
            break;

        default:
            // If user typed an unknown option
            cout << "\n⚠️ Invalid option. Please try again." << endl;
        }

    } while (choice != 5);  // LOOP runs again unless user picks option 5 (exit)

    return 0;  // End of program
}
