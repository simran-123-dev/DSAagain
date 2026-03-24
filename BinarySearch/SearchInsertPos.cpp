/* 
   PROBLEM: 35. Search Insert Position (LeetCode)
   TOPIC: Arrays / Searching
   PATTERN: Binary Search (Lower Bound)
   
   THEORY:
   - Task: Return the index of a target value if found; if not, return the index where it would be if inserted in order.
   
   - Approach: Standard Binary Search
     1. Search Space: Start with the full range [0, n-1].
     2. Midpoint Logic: Standard safe midpoint 'st + (end - st) / 2'.
     3. Case Matching:
        - If 'target' is found, return its index immediately.
        - If 'target' is smaller than 'mid', search the left half.
        - If 'target' is larger than 'mid', search the right half.
     4. Insertion Point: After the loop terminates, 'st' will naturally point to the smallest index where 'target' can be placed while maintaining sorted order.

   - Time Complexity: O(log N) - Logarithmic search time.
   - Space Complexity: O(1) - Constant space usage.
*/

#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target == nums[mid]) {
                return mid;
            }
            if (target < nums[mid]) {
                // Target must be on the left
                end = mid - 1;
            }
            else {
                // Target must be on the right
                st = mid + 1;
            }
        }
        
        // After the loop, 'st' is the correct insertion index
        return st;
    }
};
