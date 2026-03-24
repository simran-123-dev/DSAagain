/* 
   PROBLEM: 704. Binary Search (LeetCode)
   TOPIC: Arrays / Searching
   PATTERN: Divide and Conquer (Binary Search)
   
   THEORY:
   - Task: Find a target value within a sorted array in logarithmic time.
   
   - Approach: Two-Pointer Convergence
     1. Initialization: Set 'st' (start) at index 0 and 'end' at the last index.
     2. Midpoint Calculation: Use 'st + (end - st) / 2' to prevent potential integer overflow.
     3. Comparison:
        - If target equals mid, the search is complete.
        - If target is smaller than mid, discard the right half by moving 'end'.
        - If target is larger than mid, discard the left half by moving 'st'.
     4. Termination: If 'st' exceeds 'end', the target does not exist in the array.

   - Time Complexity: O(log N) - The search space is halved in every iteration.
   - Space Complexity: O(1) - Iterative approach uses no extra memory.
*/

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {
            // Calculate mid safely to avoid overflow
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (target < nums[mid]) {
                // Target is in the left half
                end = mid - 1;
            }
            else {
                // Target is in the right half
                st = mid + 1;
            }
        }
        
        return -1; // Target not found
    }
};
