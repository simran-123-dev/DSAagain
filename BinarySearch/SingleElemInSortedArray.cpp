/* 
   PROBLEM: 540. Single Element in a Sorted Array (LeetCode)
   TOPIC: Arrays / Binary Search
   PATTERN: Even-Odd Index Pairing
   
   THEORY:
   - Task: Find the one element that appears only once in a sorted array where every other element appears exactly twice.
   
   - Approach: Index Parity Method
     1. The Pattern: In a "normal" array (before the single element), pairs always start at an EVEN index and end at an ODD index (e.g., [0,1], [2,3], [4,5]).
     2. The Shift: Once the single element is inserted, this pattern breaks. All subsequent pairs will start at an ODD index and end at an EVEN index.
     3. Binary Search Strategy:
        - Ensure 'mid' is always an even index (if it's odd, decrement it).
        - Compare 'nums[mid]' with 'nums[mid + 1]'.
        - If they match: The "break" hasn't happened yet. The single element is to the right. Move 'st = mid + 2'.
        - If they don't match: The "break" has already happened (or mid is the single element). Move 'end = mid'.
     4. Result: 'st' will point to the single element.

   - Time Complexity: O(log N) - We effectively check pairs of elements.
   - Space Complexity: O(1) - Constant auxiliary space.
*/

#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        // Using < because we return nums[st] at the end
        while (st < end) {
            int mid = st + (end - st) / 2;

            // TRICK: Force mid to be even to check the start of a potential pair
            if (mid % 2 == 1) {
                mid--;
            }

            // In a normal sequence, nums[even] should equal nums[even + 1]
            if (nums[mid] == nums[mid + 1]) {
                // Pattern is correct, single element is further right
                st = mid + 2;
            } else {
                // Pattern is broken, single element is at mid or to the left
                end = mid;
            }
        }

        return nums[st];
    }
};
