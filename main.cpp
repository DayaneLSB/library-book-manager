#include <iostream>       // Allows us to use input/output (cin and cout)
#include "Book.h"         // Includes the Book class we created in Book.h

using namespace std;      // So we don't have to write std:: before cout, cin, string etc.

int main() {
    // Creates an array called 'library' to store 5 books
    Book library[5];

    // Set up the details (title, author, ISBN) for each book in the library
    library[0].setBookDetails("Dom Casmurro", "Machado de Assis", "111");
    library[1].setBookDetails("The Little Prince", "Saint-Exupéry", "222");
    library[2].setBookDetails("Harry Potter", "J.K. Rowling", "333");
    library[3].setBookDetails("1984", "George Orwell", "444");
    library[4].setBookDetails("Captains of the Sands", "Jorge Amado", "555");

    string inputISBN;  // A variable to store the ISBN entered by the user

    // This loop keeps running until the user types "0" to exit
    while (true) {
        // Ask the user to type the ISBN of the book they want to borrow
        cout << "\nEnter ISBN to borrow a book (or '0' to exit): ";
        cin >> inputISBN;  // Save the user's input into inputISBN

        // If the user typed "0", we stop the program
        if (inputISBN == "0") {
            cout << "Exiting system. Thank you!" << endl;
            break;  // Leave the while loop and end the program
        }

        bool found = false;  // This will track if we found the book or not

        // Loop through each book in the library
        for (int i = 0; i < 5; i++) {
            // Compare the entered ISBN with the book's ISBN
            if (library[i].getISBN() == inputISBN) {
                found = true;  // Mark that we found a book with that ISBN

                // Try to borrow the book
                if (library[i].borrowBook()) {
                    cout << "Book successfully borrowed!" << endl;
                } else {
                    cout << "Sorry, this book is already borrowed." << endl;
                }

                // Show the current details of the book (including ✅ or ❌)
                library[i].displayBookDetails();
                break;  // Stop the loop since we already found the book
            }
        }

        // If the book wasn't found after checking all 5 books
        if (!found) {
            cout << "Book with ISBN " << inputISBN << " not found in the library." << endl;
        }
    }

    return 0;  // Return 0 means the program ended without errors
}
