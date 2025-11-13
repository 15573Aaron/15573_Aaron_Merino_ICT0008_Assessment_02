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
    void displayBookDetails() const;
    void borrowBook();
    void returnBook();
    
    // Método para ordenar
    static void sortBookData(Book books[], int size); 
    
    // Método auxiliar (Getter)
    std::string getIsbn() const { return Isbn; } 
};

#endif // BOOK_H