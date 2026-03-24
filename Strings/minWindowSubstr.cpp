/* 
   PROBLEM: 76. Minimum Window Substring (LeetCode)
   TOPIC: Strings / Hash Table
   PATTERN: Sliding Window (Two Pointers)
   
   THEORY:
   - Task: Find the smallest substring in 's' that contains all characters of 't' (including duplicates).
   
   - Approach: Sliding Window with Frequency Maps
     1. Frequency Map: Create a frequency count of all characters in 't'.
     2. Expand: Move the 'right' pointer to include characters in the window until all required characters from 't' are present.
     3. Formed Count: Track how many unique characters from 't' have reached their required frequency in the current window.
     4. Shrink: Once a valid window is found, move the 'left' pointer to find the smallest possible valid substring.
     5. Update Minimum: During shrinking, keep track of the minimum length and its starting position.

   - Time Complexity: O(M + N) - Where M and N are lengths of 's' and 't' respectively.
   - Space Complexity: O(K) - Where K is the number of unique characters (max 256 for ASCII).
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> freq;
        for (char c : t) freq[c]++;

        int required = freq.size();   // Unique characters needed
        int formed = 0;               // Unique characters currently satisfied

        unordered_map<char, int> window;
        int left = 0, right = 0;

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.length()) {
            char c = s[right];
            window[c]++;

            // Check if current character matches the frequency in 't'
            if (freq.count(c) && window[c] == freq[c]) {
                formed++;
            }

            // Try to shrink the window from the left
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                // If removing leftChar breaks the "valid window" condition
                if (freq.count(leftChar) && window[leftChar] < freq[leftChar]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
