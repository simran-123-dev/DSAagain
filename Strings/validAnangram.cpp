/* 
   PROBLEM: 242. Valid Anagram (LeetCode)
   TOPIC: Strings / Hashing
   PATTERN: Frequency Counting using Hash Map
   
   THEORY:
   - Task: Determine if string 't' is an anagram of 's'.
   
   - Approach: Hash Map (unordered_map)
     1. Logic: If two strings are anagrams, every character must appear the same number of times in both.
     2. Step 1 (Increment): Iterate through string 's' and store the count of each character in a map.
     3. Step 2 (Decrement): Iterate through string 't' and subtract the count for each character from the same map.
     4. Step 3 (Check): Iterate through the map. If any character's frequency is NOT zero, it means the strings are not anagrams.
   
   - Advantage of Map over Array: 
     - While an array (26 size) is faster for lowercase English letters, a 'map' is more scalable as it can handle any character (symbols, uppercase, etc.) without knowing the range beforehand.

   - Time Complexity: O(n + m) - Where n and m are lengths of strings s and t.
   - Space Complexity: O(K) - Where K is the number of unique characters in the string.
*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Optimization: If lengths are different, they cannot be anagrams
        if (s.length() != t.length()) return false;

        unordered_map<char, int> mp;

        // Count frequency of characters in string 's'
        for (char c : s) {
            mp[c]++;
        }

        // Subtract frequency of characters in string 't'
        for (char c : t) {
            mp[c]--;
        }

        // If it's an anagram, all frequencies in the map should be 0
        for (auto p : mp) {
            if (p.second != 0) {
                return false;
            }
        }

        return true;
    }
};
