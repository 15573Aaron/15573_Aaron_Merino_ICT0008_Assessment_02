#ifndef BOOK_H
#define BOOK_H

#include <string>

struct Date {
    int day;
    int month;
    int year;
};

class Book {
private:
    std::string Title;
    std::string Author;
    std::string Isbn;
    bool Availability;     
    Date DateAdd;          

public:
    void setBookDetails(std::string title, std::string author, std::string isbn, Date date);
    virtual void displayBookDetails() const;
    void borrowBook();
    void returnBook();
    
    static void sortBookData(Book books[], int size); 
    
    std::string getIsbn() const { return Isbn; }
    virtual ~Book() {}
};

// Hardcopy
class Hardcopy : public Book {
private:
    std::string ShelfLocation;
public:
    void setHardcopyDetails(std::string title, std::string author, std::string isbn, Date date, std::string location);
    void displayBookDetails() const override; 
};

// Ebook
class Ebook : public Book {
private:
    std::string LicenseEndDate;
public:
    void setEbookDetails(std::string title, std::string author, std::string isbn, Date date, std::string endDate);
    void displayBookDetails() const override; 
};

#endif // BOOK_H