/* 
   PROBLEM: 438. Find All Anagrams in a String (LeetCode)
   TOPIC: Strings / Hash Table
   PATTERN: Fixed-Size Sliding Window
   
   THEORY:
   - Task: Find all start indices of p's anagrams in s.
   
   - Approach: Frequency Array & Sliding Window
     1. Preprocessing: Use a frequency array (size 26) to store the character counts of string 'p'.
     2. Window Management: Maintain a second frequency array for the current window in 's' of size equal to 'p.size()'.
     3. Sliding: As the window moves, add the new character entering the window and remove the character that just left.
     4. Comparison: Directly compare the two frequency arrays. If they match, the current window is an anagram.
     5. Efficiency: Instead of re-scanning the substring, updating the frequency array takes O(1) per step.

   - Time Complexity: O(N) - Where N is the length of string 's'. We traverse the string once.
   - Space Complexity: O(1) - The frequency arrays are fixed at size 26 regardless of input size.
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;

        vector<int> pCount(26, 0), sCount(26, 0);
        int k = p.size();

        // Build frequency for string p
        for (char c : p) {
            pCount[c - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            // Add current character to window
            sCount[s[i] - 'a']++;

            // Remove character that is no longer in the window
            if (i >= k) {
                sCount[s[i - k] - 'a']--;
            }

            // Compare character frequencies
            if (sCount == pCount) {
                result.push_back(i - k + 1);
            }
        }

        return result;
    }
};
