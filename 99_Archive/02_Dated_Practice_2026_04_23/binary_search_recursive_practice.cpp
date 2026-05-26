#include <iostream>
#include <vector>
using namespace std;

// Recursive binary search.
// Precondition: arr must be sorted in ascending order.
// Each recursive call searches only one half of the remaining range.
int binarySearch(const vector<int>& arr, int target, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return mid;
        if (arr[mid] > target) return binarySearch(arr, target, low, mid - 1);
        return binarySearch(arr, target, mid + 1, high);
    }

    return -1;
}

int main() {
    vector<int> arr = {3, 8, 17, 29, 42, 54, 61, 75, 88, 93};
    int target = 54;

    int result = binarySearch(arr, target, 0, arr.size() - 1);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;
    return 0;
}
