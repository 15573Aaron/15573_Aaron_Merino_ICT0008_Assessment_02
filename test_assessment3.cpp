#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include "book.h" 
#include "sorting.h" 

void run_initialization_tests();
void run_sorting_tests(); 
void print_library(const std::vector<Book*>& library, const std::string& title); 

int main() {
    std::cout << "=================================================\n";
    std::cout << "  CLASS TESTING START (Assessment 3)\n";
    std::cout << "=================================================\n";

    run_initialization_tests();
    run_sorting_tests(); 
    
    std::cout << "\n=================================================\n";
    std::cout << "  END OF ALL CLASS TESTING.\n";
    std::cout << "=================================================\n";
    
    return 0;
}

void run_initialization_tests() {
    std::cout << "\n--- TEST 1: Correct Initialization (Evidence 1.1) ---\n";
    
    Book* book_c1 = new Hardcopy("The last way", "Aaron Borges", "978-0307267439", "2026-6-12");
    book_c1->displayBookDetails();
    
    Book* book_c2 = new Ebook("Don limpio", "Jorge Martin", "978-0132351124", "2026-12-31");
    book_c2->displayBookDetails();

    Book* book_c3 = new Ebook("El principito", "Noelia Martin", "978-0132351978", "2026-01-01");
    book_c3->displayBookDetails();

    std::cout << "\n--- TEST 2: INCORRECT Initialization (Evidence 1.2 - Downside Exposure) ---\n";
    
    Book* book_i1 = new Hardcopy("", "Anonymous", "999-1111111111", "X-000");
    std::cout << ">> Book I1: Empty Title Test (Vulnerability Exposed):\n";
    book_i1->displayBookDetails(); 
    
    Book* book_i2 = new Ebook("Valid Title", "Valid Author", "", "2028-01-01");
    std::cout << ">> Book I2: Empty ISBN Test (Vulnerability Exposed):\n";
    book_i2->displayBookDetails(); 

    Book* book_i3 = new Hardcopy("Anonymous", "", "999-1111111333", "X-001");
    std::cout << ">> Book I3: Empty Author Test (Vulnerability Exposed):\n";
    book_i3->displayBookDetails(); 

    std::cout << "\nCleaning memory from initialization test...\n";
    delete book_c1;
    delete book_c2;
    delete book_c3;
    delete book_i1;
    delete book_i2;
    delete book_i3;
}

void print_library(const std::vector<Book*>& library, const std::string& title) {
    std::cout << "\n--- " << title << " ---\n";
    for (Book* book : library) {
        std::cout << "  - " << book->getTitle() << " (ISBN: " << book->getIsbn() << ")\n";
    }
}

void run_sorting_tests() {
    std::cout << "\n\n--- TEST 3: Sorting with QuickSort by Title ---\n";

    Book* A = new Hardcopy("A_Atlas", "Anon A", "100", "L1");
    Book* B = new Hardcopy("B_Biology", "Anon B", "200", "L2");
    Book* C = new Hardcopy("C_Chemistry", "Anon C", "300", "L3");
    
    std::vector<Book*> all_books = {A, B, C}; 

    std::vector<Book*> ascending = {A, B, C};
    print_library(ascending, "VECTOR INITIAL: Ascending");
    QuickSort(ascending, 0, ascending.size() - 1, TITLE);
    print_library(ascending, "VECTOR SORTED: Ascending (Expected A, B, C)");

    std::vector<Book*> descending = {C, B, A};
    print_library(descending, "VECTOR INITIAL: Descending");
    QuickSort(descending, 0, descending.size() - 1, TITLE);
    print_library(descending, "VECTOR SORTED: Descending (Expected A, B, C)");
    
    std::vector<Book*> mixed = {B, A, C};
    print_library(mixed, "VECTOR INITIAL: Mixed");
    QuickSort(mixed, 0, mixed.size() - 1, TITLE);
    print_library(mixed, "VECTOR SORTED: Mixed (Expected A, B, C)");

    std::cout << "\nCleaning memory from sorting test...\n";
    for (Book* book : all_books) {
        delete book;
    }
}