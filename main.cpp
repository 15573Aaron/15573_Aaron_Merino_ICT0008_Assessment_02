// main.cpp

#include "book.h"
#include "sorting.h"
#include <vector>
#include <algorithm> 
#include <string>
#include <limits> // For std::numeric_limits
#include <iomanip>

// Function Declarations
void printLibrary(const std::vector<Book*>& library, const std::string& title);
void displayMenu();
void handleBookOperation(std::vector<Book*>& library, const std::string& isbn, bool isBorrow);
void handleSortOperation(std::vector<Book*>& library);

int main() {
    
    // Initializing the library inventory
    std::vector<Book*> library;
    library.push_back(new Hardcopy("Don Quixote", "Miguel de Cervantes", "978-8424911475", "A-301"));
    library.push_back(new Ebook("Alas de Onix", "Alexandra A. Martin", "978-0132351124", "2020-11-28"));
    library.push_back(new Hardcopy("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565", "B-105"));
    library.push_back(new Ebook("C++ Primer", "Stanley B. Lippman", "978-0321714114", "2027-01-01"));

    int choice;
    bool running = true;
    
    std::cout << "--- Library Management System Initialized ---\n";

    while (running) {
        displayMenu();
        std::cout << "Select an option: ";
        
        // Input validation for menu choice
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n*** Invalid input. Please enter a number from 1 to 5. ***\n";
            continue;
        }

        std::string isbn;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer after number input

        switch (choice) {
            case 1: // 1. View all books
                printLibrary(library, "Complete Book Inventory");
                break;
            case 2: // 2. Sort books
                handleSortOperation(library);
                break;
            case 3: // 3. Borrow a book
                std::cout << "Enter the ISBN of the book to borrow: ";
                std::getline(std::cin, isbn);
                handleBookOperation(library, isbn, true);
                break;
            case 4: // 4. Return a book
                std::cout << "Enter the ISBN of the book to return: ";
                std::getline(std::cin, isbn);
                handleBookOperation(library, isbn, false);
                break;
            case 5: // 5. Exit
                std::cout << "\nClosing the system. Goodbye!\n";
                running = false;
                break;
            default:
                std::cout << "\n*** Option not recognized. Please enter a number from 1 to 5. ***\n";
                break;
        }
    }

    // Memory Cleanup (Crucial for C++ with 'new')
    for (Book* book : library) {
        delete book; 
    }
    library.clear();
    
    return 0;
}

// Function Implementations

void displayMenu() {
    std::cout << "\n-------------------------------------------------\n";
    std::cout << " Main Menu\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << " 1. View all books\n";
    std::cout << " 2. Sort books (by Title or ISBN)\n";
    std::cout << " 3. Borrow a book\n";
    std::cout << " 4. Return a book\n";
    std::cout << " 5. Exit\n";
    std::cout << "-------------------------------------------------\n";
}

void printLibrary(const std::vector<Book*>& library, const std::string& title) {
    if (library.empty()) {
        std::cout << "\n--- The library is currently empty. ---\n";
        return;
    }
    std::cout << "\n================================================\n";
    std::cout << " " << title << " (" << library.size() << " books)\n";
    std::cout << "================================================\n";
    
    for (const auto& book : library) {
        // Polymorphism in action: calls the correct derived class display method
        book->displayBookDetails(); 
        std::cout << "------------------------------------------\n";
    }
}

void handleBookOperation(std::vector<Book*>& library, const std::string& isbn, bool isBorrow) {
    // Uses std::find_if to locate the book by ISBN
    auto it = std::find_if(library.begin(), library.end(), 
        [&isbn](Book* b) { return b->getIsbn() == isbn; });

    if (it != library.end()) {
        if (isBorrow) {
            (*it)->borrowBook();
        } else {
            (*it)->returnBook();
        }
    } else {
        std::cout << "\n*** Error: Book with ISBN " << isbn << " not found. ***\n";
    }
}

void handleSortOperation(std::vector<Book*>& library) {
    int sortChoice;
    std::cout << "\nSorting Options:\n";
    std::cout << " 1. Sort by Title\n";
    std::cout << " 2. Sort by ISBN\n";
    std::cout << "Select criteria: ";
    
    if (!(std::cin >> sortChoice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n*** Invalid input. Returning to main menu. ***\n";
        return;
    }
    
    if (sortChoice == 1) {
        QuickSort(library, 0, library.size() - 1, TITLE);
        std::cout << "\nInventory successfully sorted by Title.\n";
        printLibrary(library, "Inventory Sorted by TITLE");
    } else if (sortChoice == 2) {
        QuickSort(library, 0, library.size() - 1, ISBN);
        std::cout << "\nInventory successfully sorted by ISBN.\n";
        printLibrary(library, "Inventory Sorted by ISBN");
    } else {
        std::cout << "\n*** Invalid sorting criterion. ***\n";
    }
}