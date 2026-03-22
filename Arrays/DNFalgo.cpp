/* 
   PROBLEM: 75. Sort Colors (LeetCode)
   TOPIC: Arrays / Two-Pointers (Three-Pointer Strategy)
   PATTERN: Dutch National Flag (DNF) Algorithm
   
   THEORY:
   - Task: Sort an array with 0s, 1s, and 2s in-place (without built-in sort).
   
   - Approach 1: Built-in Sorting (Brute Force)
     Code: sort(nums.begin(), nums.end());
     Time: O(n log n), Space: O(1). (Not ideal due to follow-up constraints).

   - Approach 2: Dutch National Flag Algorithm (Optimal)
     - Use 3 pointers: low (for 0s), mid (for 1s), and high (for 2s).
     - Pointer positions:
       1. Elements from 0 to low-1 are all 0s.
       2. Elements from low to mid-1 are all 1s.
       3. Elements from high+1 to n-1 are all 2s.
     - While mid <= high:
       - If nums[mid] == 0: Swap(nums[low], nums[mid]), low++, mid++.
       - If nums[mid] == 1: Just mid++ (it's already in the middle).
       - If nums[mid] == 2: Swap(nums[mid], nums[high]), high--.
         (Important: We don't increment mid here because the swapped element 
          from 'high' needs to be processed).

   - Time Complexity: O(n) - Single pass through the array.
   - Space Complexity: O(1) - Constant space used.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;           // Tracks where the next 0 should go
        int mid = 0;           // Current element tracker
        int high = nums.size() - 1; // Tracks where the next 2 should go

        while (mid <= high) {
            if (nums[mid] == 0) {
                // If it's a 0, move it to the low-end
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                // If it's a 1, it's already in the 'middle' area
                mid++;
            } 
            else { // nums[mid] == 2
                // If it's a 2, move it to the high-end
                swap(nums[mid], nums[high]);
                high--;
                // Note: mid is not incremented because the new nums[mid] 
                // could be 0, 1, or 2 and must be checked.
            }
        }
    }
};
