#include <iostream>
#include <vector>
using namespace std;

// Binary search only works when the input is sorted.
// Idea: repeatedly discard the half that cannot contain the target.
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
    vector<int> arr = {3, 8, 17, 29, 42, 54, 61, 75, 88, 93};
    int x = 54;

    int result = binarysearch(arr, x);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
