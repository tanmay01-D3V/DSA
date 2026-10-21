#include <iostream>
#include <vector>
using namespace std;

// Merge sort is a divide-and-conquer algorithm:
// 1. Divide the array into two halves.
// 2. Sort each half recursively.
// 3. Merge the two sorted halves back together.
// Time: O(n log n) in all cases, Space: O(n).
void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted halves into a temporary vector, then copy back.
    int i = l, j = m + 1, k = 0;
    vector<int> temp(r - l + 1);

    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for (i = l, k = 0; i <= r; i++, k++) {
        arr[i] = temp[k];
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
