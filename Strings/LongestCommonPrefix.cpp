/* 
   PROBLEM: 14. Longest Common Prefix (LeetCode)
   TOPIC: Strings / Sorting
   PATTERN: Lexicographical Comparison
   
   THEORY:
   - Task: Find the longest common prefix string amongst an array of strings.
   
   - Approach: Sorting & Extremes Method
     1. Sorting: Sort the array lexicographically. This puts the most "different" strings at the start and end of the vector.
     2. Identify Extremes: Take the 'first' string and the 'last' string after sorting.
     3. Minimal Comparison: Any prefix shared by the first and last strings must, by definition of sorting, be shared by every string in between.
     4. Character Matching: Iterate through characters of the first and last strings until a mismatch is found or the end of a string is reached.
     5. Substring: Return the common portion using 'substr()'.

   - Time Complexity: O(N * L log N) - Where N is the number of strings and L is the average length (due to sorting).
   - Space Complexity: O(1) or O(L) - Depending on the sorting algorithm's stack space.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Sort to bring the most dissimilar strings to the front and back
        sort(strs.begin(), strs.end());
        
        string first = strs.front();
        string last = strs.back();
        int i = 0;
        int minLength = min(first.size(), last.size());
        
        // Compare only the first and last strings
        while (i < minLength && first[i] == last[i]) {
            i++;
        }
        
        return first.substr(0, i);
    }
};
