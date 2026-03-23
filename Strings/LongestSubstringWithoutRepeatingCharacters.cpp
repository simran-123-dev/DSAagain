/* 
   PROBLEM: 3. Longest Substring Without Repeating Characters (LeetCode)
   TOPIC: Strings / Sliding Window
   PATTERN: Variable-Size Sliding Window (Hash Map/Array)
   
   THEORY:
   - Task: Find the length of the longest substring without repeating characters.
   
   - Approach: Sliding Window (Two-Pointer)
     1. Frequency Array: Use a fixed-size array (256 for ASCII) to track character counts within the current window.
     2. Expand: Move the 'right' pointer to include characters in the window and increment their frequency.
     3. Shrink: If a duplicate is detected (frequency > 1), increment the 'left' pointer and decrement frequencies until the window is valid again.
     4. Maximize: At each step, calculate the distance between 'right' and 'left' to update the maximum length found.
     5. Efficiency: Instead of nested loops, each character is visited at most twice (once by right, once by left).

   - Time Complexity: O(n) - Linear traversal of the string.
   - Space Complexity: O(1) - The frequency array size is constant (256) regardless of input size.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};   // Frequency array to track character occurrences
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            // Include the current character in the window
            freq[s[right]]++;

            // If a duplicate is found, shrink the window from the left
            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }

            // Update the maximum length of the valid window
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
