/* 
   PROBLEM: 189. Rotate Array (LeetCode)
   TOPIC: Arrays / Two Pointers
   PATTERN: Array Reversal Logic
   
   THEORY:
   - Task: Rotate an array to the right by k steps.
   - Example: [1,2,3,4,5], k=2 -> [4,5,1,2,3]
   
   - Approach 1: Extra Space (Commented)
     Create a temporary array, copy elements to their new positions: (i + k) % n.
     Time: O(n), Space: O(n).

   - Approach 2: Optimal Reversal (In-place)
     1. Handle k: If k > n, use k = k % n (rotating n times gives the same array).
     2. Reverse the entire array.
     3. Reverse the first 'k' elements.
     4. Reverse the remaining 'n-k' elements.
     Time: O(n), Space: O(1).
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Normalize k if it's larger than n
        k = k % n;

        /* 
        --- APPROACH 1: EXTRA SPACE ---
        vector<int> temp(n);
        for(int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
        */

        // --- APPROACH 2: OPTIMAL REVERSAL ---
        // 1. Reverse the whole array: [1,2,3,4,5] -> [5,4,3,2,1]
        reverse(nums.begin(), nums.end());

        // 2. Reverse first k elements: [5,4,3,2,1] -> [4,5,3,2,1] (if k=2)
        reverse(nums.begin(), nums.begin() + k);

        // 3. Reverse the rest: [4,5,3,2,1] -> [4,5,1,2,3]
        reverse(nums.begin() + k, nums.end());
    }
};
