#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trapBruteForce(const vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0; // Cannot trap water with 0, 1, or 2 bars
    
    int totalWater = 0;

    // Skip the first and last bars as they cannot trap water
    for (int i = 1; i < n - 1; i++) {
        int leftMax = 0, rightMax = 0;

        // Find the maximum height on the left (including current)
        for (int j = 0; j <= i; j++) {
            leftMax = max(leftMax, height[j]);
        }

        // Find the maximum height on the right (including current)
        for (int j = i; j < n; j++) {
            rightMax = max(rightMax, height[j]);
        }

        // Calculate water trapped at current index
        totalWater += min(leftMax, rightMax) - height[i];
    }

    return totalWater;
}

int main() {
    vector<int> height = {3, 0, 1, 0, 4, 0, 2};
    cout << "Brute Force Trapped Water: " << trapBruteForce(height) << " units\n";
    return 0;
}