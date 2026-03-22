/* 
   PROBLEM: 1. Two Sum (LeetCode)
   TOPIC: Arrays / Hashing
   PATTERN: Complement Search using HashMap
   
   THEORY:
   - Task: Find indices of two numbers such that they add up to a specific target.
   - Brute Force: Two nested loops to check every pair. Time: O(n^2), Space: O(1).
   - Optimal (One-Pass HashMap):
     1. While iterating, calculate the 'complement' (target - current_element).
     2. Check if this complement exists in our HashMap (it stores value -> index).
     3. If yes, we found the pair! Return their indices.
     4. If no, add the current element and its index to the HashMap.
   - Time Complexity: O(n) - One pass only.
   - Space Complexity: O(n) - To store the elements in the map.
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // --- APPROACH 1: BRUTE FORCE (Commented) ---
        /*
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        */

        // --- APPROACH 2: OPTIMAL (HASHMAP) ---
        unordered_map<int, int> mp; // Stores {value, index}
        
        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i]; // Hume kya chahiye?
            
            // Agar 'remaining' map mein mil gaya, toh kaam ho gaya!
            if (mp.find(remaining) != mp.end()) {
                return {mp[remaining], i};
            }
            
            // Warna current number ko uske index ke saath map mein daal do
            mp[nums[i]] = i;
        }
        
        return {}; // Agar koi pair na mile
    }
};
