#include <iostream>
#include <vector>
using namespace std;

// Binary search requires a sorted array.
// It compares with the middle element and removes half of the search space.
// Time: O(log n), Space: O(1).
int binarysearch(const vector<int>& arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;

    int result = binarysearch(arr, x);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
