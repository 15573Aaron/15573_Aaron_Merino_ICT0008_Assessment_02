// Book.h

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <sstream> // For standardizing the date format (optional)

class Book {
private:
    std::string Title;
    std::string Author;
    std::string Isbn;
    bool Availability;
    std::string DateAdded;

public:
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : Title(title), Author(author), Isbn(isbn), Availability(true) {
        time_t now = time(0);
        char buf[80];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
        DateAdded = buf;
    }

    // Virtual destructor required for proper memory cleanup with inheritance
    virtual ~Book() = default; 

    // Virtual method for Polymorphism (must be implemented by derived classes)
    virtual void displayBookDetails() const {
        std::cout << "\n--- Book Details ---\n";
        std::cout << std::left << std::setw(15) << "Title:" << Title << std::endl;
        std::cout << std::left << std::setw(15) << "Author:" << Author << std::endl;
        std::cout << std::left << std::setw(15) << "ISBN:" << Isbn << std::endl;
        std::cout << std::left << std::setw(15) << "Availability:" << (Availability ? "Yes" : "No") << std::endl;
        std::cout << std::left << std::setw(15) << "Date Added:" << DateAdded << std::endl;
    }

    void borrowBook() {
        if (Availability) {
            Availability = false;
            std::cout << "** SUCCESS: " << Title << " has been borrowed.\n";
        } else {
            std::cout << "** ERROR: " << Title << " is not available for loan.\n";
        }
    }

    void returnBook() {
        Availability = true;
        std::cout << "** SUCCESS: " << Title << " has been returned.\n";
    }

    // Getters necessary for Quick Sort comparison
    std::string getIsbn() const { return Isbn; }
    std::string getTitle() const { return Title; }
};

class Ebook : public Book {
private:
    std::string LicenseEndDate; 

public:
    Ebook(const std::string& title, const std::string& author, const std::string& isbn, const std::string& licenseEnd)
        : Book(title, author, isbn), LicenseEndDate(licenseEnd) {}
    
    // Using 'override' to ensure the virtual function from the base class is properly overwritten
    void displayBookDetails() const override {
        Book::displayBookDetails(); 
        std::cout << std::left << std::setw(15) << "Type:" << "E-Book" << std::endl;
        std::cout << std::left << std::setw(15) << "License End:" << LicenseEndDate << std::endl;
    }

    void setLicenseEnd(const std::string& date) { LicenseEndDate = date; }
};

class Hardcopy : public Book {
private:
    std::string ShelfLocation; 

public:
    Hardcopy(const std::string& title, const std::string& author, const std::string& isbn, const std::string& location)
        : Book(title, author, isbn), ShelfLocation(location) {}

    // Using 'override' for polymorphism
    void displayBookDetails() const override {
        Book::displayBookDetails(); 
        std::cout << std::left << std::setw(15) << "Type:" << "Physical Copy" << std::endl;
        std::cout << std::left << std::setw(15) << "Location:" << ShelfLocation << std::endl;
    }

    void setShelfLocation(const std::string& location) { ShelfLocation = location; }
};

#endif // BOOK_H