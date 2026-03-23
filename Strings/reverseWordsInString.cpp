/* 
   PROBLEM: 151. Reverse Words in a String (LeetCode)
   TOPIC: Strings / Vector
   PATTERN: String Tokenization & Reversal
   
   THEORY:
   - Task: Extract words from a string (ignoring extra spaces) and reverse their order.
   
   - Approach: Vector Tokenization
     1. Tokenization: Traverse the string and use two pointers (`i` and `j`) to identify the boundaries of each word.
     2. Handling Spaces: Explicitly skip spaces by incrementing the pointer `i` until a non-space character is found.
     3. Substring Extraction: Use `s.substr(i, j - i)` to extract the word and push it into a `vector<string>`.
     4. Reversal: Reverse the entire vector so the last word becomes the first.
     5. Joining: Iterate through the reversed vector and concatenate words into a final result string, adding a single space between them.

   - Time Complexity: O(N) - Where N is the length of the string (one pass for extraction, one for joining).
   - Space Complexity: O(N) - To store the words in the vector and the final result string.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        int n = s.size();
        int i = 0;

        // Step 1: Extract words and store in vector
        while (i < n) {
            // Skip leading spaces or spaces between words
            while (i < n && s[i] == ' ') i++;
            
            int j = i;
            // Find the end of the current word
            while (j < n && s[j] != ' ') j++;
            
            // If i < j, it means we found a valid word
            if (i < j) {
                ans.push_back(s.substr(i, j - i));
            }
            // Move pointer to the end of the word
            i = j;
        }

        // Step 2: Reverse the order of words in the vector
        reverse(ans.begin(), ans.end());

        // Step 3: Join words with a single space
        string result = "";
        for (int k = 0; k < ans.size(); k++) {
            result += ans[k];
            // Add space only if it's not the last word
            if (k != ans.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};
