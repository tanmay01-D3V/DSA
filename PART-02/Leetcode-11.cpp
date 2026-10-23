#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            // Calculate current area
            int currentWidth = right - left;
            int currentHeight = min(height[left], height[right]);
            int currentArea = currentWidth * currentHeight;

            // Update maximum area found so far
            maxArea = max(maxArea, currentArea);

            // Greedy move: shift the pointer at the shorter bar
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Expected Output = 49
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max Area for Test Case 1: " << sol.maxArea(height1) << endl;

    // Test Case 2: Expected Output = 1
    vector<int> height2 = {1, 1};
    cout << "Max Area for Test Case 2: " << sol.maxArea(height2) << endl;

    return 0;
}