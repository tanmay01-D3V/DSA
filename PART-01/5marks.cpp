// 4. Subtract Two Numbers
#include <iostream>
#include <array>
using namespace std;

void subtractArray() {
    array<int, 2> nums = {10, 4};
    cout << "Result : " << nums[0] - nums[1] << "\n";
}


int main() {
    cout << "=== Subtract Two Numbers (a=10, b=4) ===\n\n";
    subtractArray();
    return 0;
}