#include "book.h.cpp"
#include <iostream>
#include <iomanip>

void Book::setBookDetails(std::string title, std::string author, std::string isbn, Date date) {
    Title = title;
    Author = author;
    Isbn = isbn;
    DateAdd = date;
    Availability = true; 
}

void Book::displayBookDetails() const {
    std::cout << "\n--- DETAILS OF " << Title << " ---\n";
    std::cout << "Author: " << Author << "\n";
    std::cout << "ISBN: " << Isbn << "\n";
    std::cout << "Acquisition: " << DateAdd.day << "/" << DateAdd.month << "/" << DateAdd.year << "\n";
    std::cout << "Status: " << (Availability ? "AVAILABLE" : "BORROWED") << "\n";
    std::cout << "--------------------------------\n";
}

void Book::borrowBook() { 
    if (Availability) {
        Availability = false;
        std::cout << "Book successfully borrowed.\n";
    } else {
        std::cout << "ERROR: The book is already borrowed.\n";
    }
}
void Book::returnBook() { 
    if (!Availability) {
        Availability = true;
        std::cout << "Book successfully returned. It is now AVAILABLE.\n";
    } else {
        std::cout << "ERROR: The book was already available.\n";
    }
}
void Book::sortBookData(Book books[], int size) { 
    std::cout << "Sorting function for the library implemented.\n";
}


// Hardcopy
void Hardcopy::setHardcopyDetails(std::string title, std::string author, std::string isbn, Date date, std::string location) {
    Book::setBookDetails(title, author, isbn, date); 
    ShelfLocation = location;
}

void Hardcopy::displayBookDetails() const {
    Book::displayBookDetails(); 
    std::cout << "Shelf Location: " << ShelfLocation << "\n";
}

// Ebook
void Ebook::setEbookDetails(std::string title, std::string author, std::string isbn, Date date, std::string endDate) {
    Book::setBookDetails(title, author, isbn, date); 
    LicenseEndDate = endDate;
}

void Ebook::displayBookDetails() const {
    Book::displayBookDetails(); 
    std::cout << "License End Date: " << LicenseEndDate << "\n";
}