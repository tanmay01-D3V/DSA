#include <iostream>
#include <string>
using namespace std;

// Function to check if a number is a palindrome
bool isPalindrome(int num) {
    // Negative numbers are not palindromes (e.g., -121 reversed becomes 121-)
    if (num < 0) return false;

    int originalNum = num;
    long long reversedNum = 0; // Use long long to prevent integer overflow during reversal

    while (num > 0) {
        int lastDigit = num % 10;                  // Extract the last digit
        reversedNum = (reversedNum * 10) + lastDigit; // Build the reversed number
        num /= 10;                                  // Remove the last digit
    }

    // Return true if original and reversed numbers match
    return originalNum == reversedNum;
}

// Function to check whether a string reads the same forwards and backwards
bool isPalindrome(const string& text) {
    size_t left = 0;
    size_t right = text.size();

    while (left < right) {
        --right;
        if (text[left] != text[right]) return false;
        ++left;
    }

    return true;
}

int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    if (isPalindrome(number)) {
        cout << number << " is a palindrome number." << endl;
    } else {
        cout << number << " is not a palindrome number." << endl;
    }

    string text;
    cout << "Enter a string: ";
    cin >> text;

    if (isPalindrome(text)) {
        cout << text << " is a palindrome string." << endl;
    } else {
        cout << text << " is not a palindrome string." << endl;
    }

    return 0;
}
