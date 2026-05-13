#include<iostream>
using namespace std;

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return; // Base case: if the array has one or zero elements, it's already sorted

    int m = l + (r - l) / 2; // Find the midpoint of the array
    mergeSort(arr, l, m); // Recursively sort the left half
    mergeSort(arr, m + 1, r); // Recursively sort the right half

    // Merge the sorted halves
    int i = l, j = m + 1, k = 0;
    int temp[r - l + 1]; // Temporary array to hold merged results

    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++]; // Add left element to temp and move left pointer
        } else {
            temp[k++] = arr[j++]; // Add right element to temp and move right pointer
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++]; // Add remaining left elements to temp
    }

    while (j <= r) {
        temp[k++] = arr[j++]; // Add remaining right elements to temp
    }

    for (i = l, k = 0; i <= r; i++, k++) {
        arr[i] = temp[k]; // Copy merged elements back to original array
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}