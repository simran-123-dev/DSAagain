/* 
   PROBLEM: 49. Group Anagrams (LeetCode)
   TOPIC: Strings / Hash Map
   PATTERN: Frequency Counting (Valid Anagram Logic)
   
   THEORY:
   - Task: Given an array of strings, group the anagrams together.
   
   - Approach: Frequency Map Hashing
     1. Key Concept: Anagrams have the exact same character counts. Instead of sorting (O(K log K)), 
        we use the frequency of each character (a-z) to create a unique "fingerprint" or key.
     2. Frequency Array: For each string, create an integer array of size 26 to store character counts.
     3. Key Construction: Convert this array into a unique string key (e.g., "1#0#2#...") to handle 
        multi-digit counts correctly using a delimiter like '#'.
     4. Hash Map: Use `unordered_map<string, vector<string>>` where:
        - Key: The unique frequency string.
        - Value: A list (vector) of all strings that match this frequency.
     5. Result: Collect all the vectors from the map and return them.

   - Time Complexity: O(N * K) - Where N is the number of strings and K is the average length.
     (Faster than sorting approach which is O(N * K log K)).
   - Space Complexity: O(N * K) - To store the strings in the hash map.
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store: FrequencyKey -> List of original strings
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            // Step 1: Create frequency count (Valid Anagram logic)
            vector<int> freq(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
            }

            // Step 2: Convert frequency array to a unique string key
            // Example: "eat" becomes "1#0#0#0#1#...1#..."
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]) + "#";
            }

            // Step 3: Group strings with the same key
            mp[key].push_back(s);
        }

        // Step 4: Extract groups from the map into the result vector
        vector<vector<string>> res;
        for (auto it : mp) {
            res.push_back(it.second);
        }

        return res;
    }
};
