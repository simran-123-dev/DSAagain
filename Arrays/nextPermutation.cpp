/* 
   PROBLEM: 31. Next Permutation (LeetCode)
   TOPIC: Arrays / Permutations
   PATTERN: Pivot and Suffix Reversal (Lexicographical Order)
   
   THEORY:
   - Task: Find the next lexicographically greater permutation of numbers.
   - If no such arrangement exists (array is sorted descending), rearrange it as the lowest possible order (sorted ascending).
   
   - Approach: Three-Step Optimized Algorithm
     1. Find the Pivot: 
        - Scan from right to left to find the first index 'i' such that nums[i] < nums[i+1].
        - This 'i' is the first place where we can increase the number's value.
     
     2. Find the Successor:
        - If 'i' exists, scan from right to left again to find the first index 'j' such that nums[j] > nums[i].
        - Swap nums[i] and nums[j]. This makes the number slightly larger.
     
     3. Reverse the Suffix:
        - Reverse the subarray starting from index i+1 to the end.
        - Since the suffix was in descending order, reversing it makes it ascending (the smallest possible value for that part).

   - Example: [1, 2, 5, 4, 3]
     1. Pivot is 2 (at index 1) because 2 < 5.
     2. Successor of 2 is 3 (at index 4) because 3 > 2. Swap(2, 3) -> [1, 3, 5, 4, 2].
     3. Reverse suffix [5, 4, 2] -> [1, 3, 2, 4, 5]. Result!

   - Time Complexity: O(n) - Two linear scans and one reversal.
   - Space Complexity: O(1) - In-place modification.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the right (Pivot)
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: Find the element just larger than nums[i] from the right (Successor)
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Swap the pivot with the successor
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the suffix (everything after the pivot index)
        // If i was -1, it reverses the whole array (correct for last permutation)
        reverse(nums.begin() + i + 1, nums.end());
    }
};
