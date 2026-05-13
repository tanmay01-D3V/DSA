#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int arr1[5] = {10,20,30,40,50};
    int arr2[10] = {10,20,30,40,50,60,70,80,90,100};

    int result1 = binarySearch(arr1, 5, 20);
    int result2 = binarySearch(arr2, 10, 80);

    cout << "Index in arr1: " << result1 << endl;
    cout << "Index in arr2: " << result2 << endl;

    return 0;
}


