#ifndef BOOK_H   // This prevents the file from being included more than once by mistake
#define BOOK_H

#include <iostream>   // Allows us to use cout (print to screen) and cin (get user input)
#include <string>     // Allows us to use the "string" data type (for text)
using namespace std;  // So we can write cout and string without writing "std::" before

// =============================
// CLASS: Book (Base class)
// A class is like a blueprint. We use it to create objects (in this case, books).
// =============================
class Book {
protected:
    // These are attributes (variables) that every book has
    string title;       // The book's title
    string author;      // The book's author
    string isbn;        // A unique code to identify the book
    bool available;     // True if the book is available, false if borrowed

public:
    // FUNCTION: setBookDetails
    // A function is a block of code that performs a task.
    // This function sets the basic information about the book.
    void setBookDetails(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        available = true;  // When a book is created, it's available by default
    }

    // FUNCTION: isAvailable
    // This function returns true if the book is available
    bool isAvailable() {
        return available;
    }

    // FUNCTION: getISBN
    // This function returns the ISBN number of the book
    string getISBN() {
        return isbn;
    }

    // FUNCTION: borrowBook
    // This function is used to borrow a book (change status to "borrowed")
    bool borrowBook() {
        if (available) {
            available = false;  // Mark as borrowed
            return true;        // Borrowing succeeded
        } else {
            return false;       // Book was already borrowed
        }
    }

    // FUNCTION: returnBook
    // This function marks the book as available again
    void returnBook() {
        available = true;
    }

    // FUNCTION: displayBookDetails
    // This function prints all the information about the book
    // It can be "overridden" by child classes (like EBook or HardcopyBook)
    virtual void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        if (available) {
            cout << "Availability: Available ✅" << endl;
        } else {
            cout << "Availability: Borrowed ❌" << endl;
        }
    }
};

// =============================
// CLASS: HardcopyBook (Child of Book)
// This class adds extra details for physical books (like shelf number)
// =============================
class HardcopyBook : public Book {
private:
    int copies;           // Number of physical copies in the library
    string shelfNumber;   // Where the book is placed on the shelf

public:
    // FUNCTION: setHardcopyDetails
    // Sets specific details for physical books
    void setHardcopyDetails(int c, string shelf) {
        copies = c;
        shelfNumber = shelf;
    }

    // FUNCTION: displayBookDetails
    // This overrides the base function to show more information
    void displayBookDetails() override {
        Book::displayBookDetails();  // Call the function from the parent class
        cout << "Copies: " << copies << endl;
        cout << "Shelf Number: " << shelfNumber << endl;
    }
};

// =============================
// CLASS: EBook (Child of Book)
// This class adds extra details for digital books (like download link)
// =============================
class EBook : public Book {
private:
    string downloadLink;     // Where the book can be downloaded from
    string endLicenseDate;   // When the download license expires

public:
    // FUNCTION: setEBookDetails
    // Sets specific details for eBooks
    void setEBookDetails(string link, string endDate) {
        downloadLink = link;
        endLicenseDate = endDate;
    }

    // FUNCTION: displayBookDetails
    // This overrides the base function to show more information
    void displayBookDetails() override {
        Book::displayBookDetails();  // Call the function from the parent class
        cout << "Download Link: " << downloadLink << endl;
        cout << "License Ends On: " << endLicenseDate << endl;
    }
};

#endif  // End of file protection
