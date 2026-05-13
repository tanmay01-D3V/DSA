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
    vector<int> arr = {42, 17, 93, 8, 61, 29, 75, 3, 88, 54};
    int target = 10;
    int result = binarySearch(arr, target, 0, arr.size() - 1);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;
    return 0;
}