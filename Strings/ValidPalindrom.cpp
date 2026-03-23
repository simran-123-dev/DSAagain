/* 
   PROBLEM: 125. Valid Palindrome (LeetCode)
   TOPIC: Strings / Two-Pointers
   PATTERN: Inward Two-Pointer Strategy
   
   THEORY:
   - Task: Check if a string is a palindrome after converting all uppercase letters into lowercase and removing all non-alphanumeric characters.
   
   - Approach: Two-Pointer Method
     1. Initialization: Set one pointer (st) at the start and another (e) at the end of the string.
     2. Skip Non-Alphanumeric: Use 'isalnum()' to skip spaces, commas, and symbols. This is crucial for strings like "A man, a plan, a canal: Panama".
     3. Case-Insensitive Comparison: Use 'tolower()' to compare characters without worrying about upper/lower case.
     4. Mismatch: If characters at 'st' and 'e' don't match, return false immediately.
     5. Completion: If pointers cross each other without a mismatch, the string is a valid palindrome.

   - Time Complexity: O(n) - We traverse the string at most once.
   - Space Complexity: O(1) - No extra space used besides pointers.
*/

#include <string>
#include <cctype> // For isalnum and tolower

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int e = s.length() - 1;

        while (st < e) {
            // Skip non-alphanumeric characters from the left
            while (st < e && !isalnum(s[st])) {
                st++;
            }
            // Skip non-alphanumeric characters from the right
            while (st < e && !isalnum(s[e])) {
                e--;
            }

            // Compare characters in lowercase
            if (tolower(s[st]) != tolower(s[e])) {
                return false;
            }

            // Move pointers inward
            st++;
            e--;
        }
        return true;
    }
};
