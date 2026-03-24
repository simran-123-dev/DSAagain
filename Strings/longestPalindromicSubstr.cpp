/* 
   PROBLEM: 5. Longest Palindromic Substring (LeetCode)
   TOPIC: Strings / Dynamic Programming / Two Pointers
   PATTERN: Expand Around Center
   
   THEORY:
   - Task: Find the longest contiguous substring within 's' that reads the same forwards and backwards.
   
   - Approach: Expand Around Center Method
     1. Centering: A palindrome can be centered at a character (odd length like "aba") or between characters (even length like "abba").
     2. Iteration: Loop through each character (and each gap between characters) as a potential center.
     3. Expansion: For each center, expand outwards as long as the left and right characters match and remain within bounds.
     4. Track Maximum: Keep track of the starting index and length of the longest palindrome found during these expansions.
     5. Substring: Extract and return the result using 's.substr(start, maxLen)'.

   - Time Complexity: O(N²) - Where N is the length of the string (N centers, each taking up to O(N) to expand).
   - Space Complexity: O(1) - Constant space is used as we only store indices and lengths.
*/

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        int start = 0, maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            // Check for odd length palindromes (center is at i)
            int len1 = expandAroundCenter(s, i, i);
            // Check for even length palindromes (center is between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                // Calculate start index based on center i and current length
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }

private:
    int expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Returns the length of the palindrome found
        return right - left - 1;
    }
};
