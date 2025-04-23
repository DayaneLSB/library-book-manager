#include <iostream>     // Allows input and output (e.g., cout)
#include <string>       // Allows use of string data type
using namespace std;

// =============================
// CLASS: Book
// =============================
class Book {
protected:
    string title;
    string author;
    string isbn;
    bool available;
    string dateAdded;

public:
    // CONSTRUCTOR: Initializes a book with values
    Book(string t, string a, string i, string av, string d) {
        title = t;
        author = a;
        isbn = i;
        dateAdded = d;
        available = (av == "Available");
    }

    // FUNCTION: Displays all details of a book
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (available ? "Available ✅" : "Borrowed ❌") << endl;
        cout << "Date Added: " << dateAdded << endl << endl;
    }
};

// =============================
// MAIN FUNCTION WITH MENU
// =============================
int main() {
    // === ARRAYS WITH PRESET BOOK ORDERINGS ===
    Book* ascending[3] = {
        new Book("Dom Casmurro", "Machado de Assis", "111", "Available", "20/01/2024"),
        new Book("Harry Potter", "J.K. Rowling", "333", "Borrowed", "15/06/2021"),
        new Book("The Little Prince", "Saint-Exupéry", "222", "Available", "25/08/2023")
    };

    Book* descending[3] = {
        new Book("The Little Prince", "Saint-Exupéry", "222", "Available", "25/08/2023"),
        new Book("Harry Potter", "J.K. Rowling", "333", "Borrowed", "15/06/2021"),
        new Book("Dom Casmurro", "Machado de Assis", "111", "Available", "20/01/2024")
    };

    Book* mixed[3] = {
        new Book("Harry Potter", "J.K. Rowling", "333", "Borrowed", "15/06/2021"),
        new Book("The Little Prince", "Saint-Exupéry", "222", "Available", "25/08/2023"),
        new Book("Dom Casmurro", "Machado de Assis", "111", "Available", "20/01/2024")
    };

    int option;

    // === MENU LOOP ===
    do {
        cout << "======= BOOK DISPLAY MENU =======" << endl;
        cout << "1. Show books in Ascending order " << endl;
        cout << "2. Show books in Descending order " << endl;
        cout << "3. Show books in Mixed order " << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option (1-4): ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "\n=== BOOKS IN ASCENDING ORDER ===" << endl;
                for (int i = 0; i < 3; i++) {
                    ascending[i]->displayBookDetails();
                }
                break;

            case 2:
                cout << "\n=== BOOKS IN DESCENDING ORDER ===" << endl;
                for (int i = 0; i < 3; i++) {
                    descending[i]->displayBookDetails();
                }
                break;

            case 3:
                cout << "\n=== BOOKS IN MIXED ORDER ===" << endl;
                for (int i = 0; i < 3; i++) {
                    mixed[i]->displayBookDetails();
                }
                break;

            case 4:
                cout << "\n👋 Exiting. Thank you for using the library system!" << endl;
                break;

            default:
                cout << "\n⚠️ Invalid option. Please choose between 1 and 4.\n" << endl;
        }

    } while (option != 4);  // Repeats until user chooses to exit

    return 0;
}
