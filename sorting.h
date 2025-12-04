// Sorting.h

#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <string>
#include <algorithm> // for std::swap
#include "book.h" 

// Enumeration for sort field selection
enum SortField {
    TITLE,
    ISBN
};

// Quick Sort Partition function
int partition(std::vector<Book*>& arr, int low, int high, SortField field) {
    Book* pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        bool condition = false;
        
        // Comparison logic based on selected field
        if (field == TITLE) {
            condition = arr[j]->getTitle() < pivot->getTitle();
        } else if (field == ISBN) {
            condition = arr[j]->getIsbn() < pivot->getIsbn();
        }

        if (condition) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick Sort Recursive function
void QuickSort(std::vector<Book*>& arr, int low, int high, SortField field = TITLE) {
    if (low < high) {
        int pi = partition(arr, low, high, field);

        QuickSort(arr, low, pi - 1, field);
        QuickSort(arr, pi + 1, high, field);
    }
}

#endif // SORTING_H