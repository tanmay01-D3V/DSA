#include<iostream>
#include <vector> 
using namespace std;

int binarysearch(vector<int> &arr, int x) // Function to perform binary search on a sorted array
{
    int low = 0, high = arr.size() - 1; // Initialize low and high pointers

    while (low <= high) // Loop until the pointers meet 
    {
        int mid = low + (high - low) / 2; // Calculate the middle index to avoid overflow

        if (arr[mid] == x) // If the middle element is the target, return its index
            return mid;
        else if (arr[mid] < x) // If the middle element is less than the target, search in the right half
            low = mid + 1;
        else    // If the middle element is greater than the target, search in the left half
            high = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;

    int result = binarysearch(arr, x);  // Call the binary search function and store the result
    if (result != -1)   // If the result is not -1, the element was found, print its index
        cout << "Element found at index: " << result << endl;
    else    // If the result is -1, the element was not found, print a message indicating that the element is not in the array
        cout << "Element not found in the array." << endl;

    return 0;
}