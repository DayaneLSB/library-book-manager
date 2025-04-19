#include <iostream>
#include <algorithm>    // For std::sort
#include "Book.h"       // Include your Book class
using namespace std;

// Function to compare books by title (ascending)
bool compareByTitleAsc(Book* a, Book* b) {
    return a->getTitle() < b->getTitle();
}

// Function to compare books by title (descending)
bool compareByTitleDesc(Book* a, Book* b) {
    return a->getTitle() > b->getTitle();
}

int main() {
    cout << "=== CORRECT BOOK INFORMATION (EVIDENCE) ===" << endl;

    // Correctly instantiated books
    Book* correct1 = new Book("Dom Casmurro", "Machado de Assis", "111", "Available", "20/01/2024");
    Book* correct2 = new Book("The Little Prince", "Saint-Exupéry", "222", "Available", "25/08/2023");
    Book* correct3 = new Book("Harry Potter", "J.K. Rowling", "333", "Borrowed", "15/06/2021");

    correct1->displayBookDetails();
    correct2->displayBookDetails();
    correct3->displayBookDetails();

    cout << "\n=== INCORRECT BOOK INFORMATION (EVIDENCE) ===" << endl;

    // Incorrectly instantiated books (still syntactically valid, but logically wrong)
    Book* wrong1 = new Book("Casmurro", "Machad", "0101", "No-available", "01/02/2024");
    Book* wrong2 = new Book("The Prince", "Saint", "0202", "Borrowed", "25/08/2000");
    Book* wrong3 = new Book("Mr Harry", "Rowling", "0303", "Available", "15/07/2020");

    wrong1->displayBookDetails();
    wrong2->displayBookDetails();
    wrong3->displayBookDetails();

    // =========================
    // ARRAYS FOR SORT TESTING
    // =========================

    // Ascending order array
    Book* booksAsc[3] = { correct1, correct2, correct3 };

    // Descending order array
    Book* booksDesc[3] = { correct3, correct2, correct1 };

    // Mixed order array
    Book* booksMixed[3] = { correct2, correct3, correct1 };

    // Sort and display
    cout << "\n=== SORTED BOOKS - ASCENDING ===" << endl;
    sort(booksAsc, booksAsc + 3, compareByTitleAsc);
    for (int i = 0; i < 3; i++) {
        booksAsc[i]->displayBookDetails();
    }

    cout << "\n=== SORTED BOOKS - DESCENDING ===" << endl;
    sort(booksDesc, booksDesc + 3, compareByTitleDesc);
    for (int i = 0; i < 3; i++) {
        booksDesc[i]->displayBookDetails();
    }

    cout << "\n=== SORTED BOOKS - MIXED TO ASCENDING ===" << endl;
    sort(booksMixed, booksMixed + 3, compareByTitleAsc);
    for (int i = 0; i < 3; i++) {
        booksMixed[i]->displayBookDetails();
    }

    return 0;
}
