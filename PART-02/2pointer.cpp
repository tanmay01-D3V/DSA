#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        // Map to store: { number -> its_index }
        std::unordered_map<int, int> seen_numbers;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the required complement has already been seen
            if (seen_numbers.find(complement) != seen_numbers.end()) {
                // Return the index of the complement and the current index
                return {seen_numbers[complement], i};
            }
            
            // Store the current number and its index in the map
            seen_numbers[nums[i]] = i;
        }
        
        // Return an empty vector if no solution exists (per LeetCode constraints, 
        // a solution is always guaranteed)
        return {};
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    std::vector<int> result = solution.twoSum(nums, target);
    
    if (!result.empty()) {
        std::cout << "Indices: [" << result[0] << ", " << result[1] << "]\n";
    } else {
        std::cout << "No solution found.\n";
    }
    
    return 0;
}
