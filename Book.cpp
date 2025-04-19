#ifndef BOOK_H
#define BOOK_H

#include <iostream>   // Enables input/output operations (e.g., cout, cin)
#include <string>     // Allows the use of the 'string' data type
using namespace std;  // Avoids having to write 'std::' before standard elements

// =============================
// CLASS: Book (Base Class)
// This is the main class used to define general book objects
// =============================
class Book {
protected:
    // Attributes that are common to all books
    string title;         // Book title
    string author;        // Book author
    string isbn;          // Unique ISBN code
    bool available;       // Book availability (true = available, false = borrowed)
    string dateAdded;     // ✅ NEW: Stores the date the book was added to the system

public:
    // ✅ NEW FUNCTION: Parameterized constructor
    // Allows creating a book object with all values directly
    Book(string t, string a, string i, string av, string d) {
        title = t;         // Assign title
        author = a;        // Assign author
        isbn = i;          // Assign ISBN
        dateAdded = d;     // Assign the date the book was added

        // Convert availability string to boolean value
        // If the value is "Available", mark as true; otherwise, false
        if (av == "Available") {
            available = true;
        } else {
            available = false;
        }
    }

    // FUNCTION: setBookDetails
    // Manually sets book details after creation
    void setBookDetails(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        available = true;  // Books are set as available by default
    }

    // FUNCTION: isAvailable
    // Returns true if the book is available
    bool isAvailable() {
        return available;
    }

    // FUNCTION: getISBN
    // Returns the book's ISBN
    string getISBN() {
        return isbn;
    }

    // FUNCTION: borrowBook
    // If the book is available, change its status to borrowed (false)
    bool borrowBook() {
        if (available) {
            available = false;  // Mark as borrowed
            return true;        // Success
        } else {
            return false;       // Already borrowed
        }
    }

    // FUNCTION: returnBook
    // Changes the status back to available
    void returnBook() {
        available = true;
    }

    // ✅ UPDATED FUNCTION: displayBookDetails
    // Displays book information, including the new dateAdded field
    virtual void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        if (available) {
            cout << "Availability: Available ✅" << endl;
        } else {
            cout << "Availability: Borrowed ❌" << endl;
        }
        cout << "Date Added: " << dateAdded << endl;  // Display new field
    }
};

// =============================
// CLASS: HardcopyBook (Derived from Book)
// Represents a physical book with extra details
// =============================
class HardcopyBook : public Book {
private:
    int copies;            // Number of physical copies
    string shelfNumber;    // Shelf location in the library

public:
    // FUNCTION: setHardcopyDetails
    // Sets specific details for a hardcopy book
    void setHardcopyDetails(int c, string shelf) {
        copies = c;
        shelfNumber = shelf;
    }

    // FUNCTION: displayBookDetails (Overridden)
    // Displays base details + hardcopy-specific info
    void displayBookDetails() override {
        Book::displayBookDetails();  // Call base class display
        cout << "Copies: " << copies << endl;
        cout << "Shelf Number: " << shelfNumber << endl;
    }
};

// =============================
// CLASS: EBook (Derived from Book)
// Represents a digital book with extra details
// =============================
class EBook : public Book {
private:
    string downloadLink;     // Link to download the eBook
    string endLicenseDate;   // License expiration date

public:
    // FUNCTION: setEBookDetails
    // Sets specific details for an eBook
    void setEBookDetails(string link, string endDate) {
        downloadLink = link;
        endLicenseDate = endDate;
    }

    // FUNCTION: displayBookDetails (Overridden)
    // Displays base details + eBook-specific info
    void displayBookDetails() override {
        Book::displayBookDetails();  // Call base class display
        cout << "Download Link: " << downloadLink << endl;
        cout << "License Ends On: " << endLicenseDate << endl;
    }
};

#endif  // End of include guard
