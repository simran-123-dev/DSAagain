/* 
   PROBLEM: 217. Contains Duplicate (LeetCode)
   TOPIC: Arrays / Hashing
   PATTERN: Frequency Tracking
   
   THEORY:
   - Task is to find if any element appears at least twice.
   - Brute Force: Use two loops to compare every pair. Time: O(n^2), Space: O(1).
   - Better (Sorting): Sort the array. If duplicates exist, they will be adjacent. 
     Time: O(n log n), Space: O(1) or O(n) depending on sort.
   - Optimal (HashSet): Use a Hash-based data structure to store visited elements. 
     Searching in HashSet takes O(1) on average.
     Time: O(n), Space: O(n).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // --- APPROACH 1: SORTING ---
    bool containsDuplicateSorting(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }

    // --- APPROACH 2: HASHSET (OPTIMAL) ---
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            // Agar element pehle se set mein hai, toh duplicate mil gaya
            if (seen.find(num) != seen.end()) {
                return true;
            }
            // Warna element ko set mein daal do
            seen.insert(num);
        }
        return false;
    }
};
