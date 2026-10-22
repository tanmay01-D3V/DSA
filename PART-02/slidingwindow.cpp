#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int maxSubarraySum(const std::vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k || k <= 0) return 0;

    int current_window_sum = 0;
    
    // 1. Compute the sum of the first window
    for (int i = 0; i < k; ++i) {
        current_window_sum += arr[i];
    }
    
    int max_sum = current_window_sum;

    // 2. Slide the window from index k to the end of the array
    for (int i = k; i < n; ++i) {
        // Add the next element and remove the element that left the window
        current_window_sum += arr[i] - arr[i - k]; 
        max_sum = std::max(max_sum, current_window_sum);
    }

    return max_sum;
}

int main() {
    std::vector<int> arr = {5, 2, -1, 0, 3};
    int k = 3;
    
    std::cout << "Maximum sum of a subarray of size " << k << " is: " 
              << maxSubarraySum(arr, k) << std::endl; // Output: 6
    return 0;
}
