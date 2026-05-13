#include<iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) return binarySearch(arr, target, low, mid - 1);   // ✅ go left
        else return binarySearch(arr, target, mid + 1, high);                          // ✅ go right
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    int result = binarySearch(arr, target, 0, arr.size() - 1);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;
    return 0;
}