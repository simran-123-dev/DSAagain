/* 
   PROBLEM: 283. Move Zeroes (LeetCode)
   TOPIC: Arrays / Two Pointers
   PATTERN: In-place Shifting
   
   THEORY:
   - Task: Move all 0's to the end while maintaining the relative order of non-zero elements.
   - Requirement: Must do this in-place without making a copy of the array.

   - Approach 1: Extra Space (Commented)
     Create an 'ans' vector, push all non-zeros, then fill the rest with zeros.
     Time: O(n), Space: O(n).

   - Approach 2: Two-Pointer (Optimal In-place)
     1. Maintain a 'left' pointer (initially 0).
     2. Iterate with 'right' pointer. If nums[right] is non-zero, swap nums[left] and nums[right].
     3. Increment 'left' only when a swap (or non-zero placement) happens.
     Time: O(n), Space: O(1).
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /* 
        --- APPROACH 1: EXTRA SPACE ---
        int n = nums.size();
        vector<int> ans;
        for(int val : nums) {
            if(val != 0) ans.push_back(val);
        }
        while(ans.size() < n) {
            ans.push_back(0);
        }
        nums = ans;
        */

        // --- APPROACH 2: OPTIMAL TWO-POINTER (In-place) ---
        int left = 0; // Pointer for the next non-zero element position
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                // Swap current non-zero element with the element at 'left' pointer
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};
