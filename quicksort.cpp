#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Partition function - the heart of QuickSort
int partition(vector<int>& arr, int low, int high) {
    cout<<"low : "<<low<<endl;
    // Choose the last element as pivot
    int pivot = arr[high];
    
    // Index of smaller element (indicates right position of pivot)
    int i = low - 1;
    cout<<"i : "<<i<<endl;
    
    // Traverse through array
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;    // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    
    // Place pivot in correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Return partition index
}

// Main QuickSort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find partition index
        int pi = partition(arr, low, high);
        
        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);     // Left subarray
        quickSort(arr, pi + 1, high);    // Right subarray
    }
}

// Helper function to call QuickSort
void quickSort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr);
    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}