/* 
   PROBLEM: 153. Find Minimum in Rotated Sorted Array (LeetCode)
   TOPIC: Arrays / Binary Search
   PATTERN: Binary Search on Pivot
   
   THEORY:
   - Task: Find the minimum element in a sorted array that has been rotated.
   
   - Approach: Boundary Comparison
     1. Key Observation: In a rotated sorted array, the minimum element is the only element that is smaller than the elements to its left.
     2. Comparison: Instead of comparing 'mid' to 'mid+1', we compare 'nums[mid]' to 'nums[end]'.
     3. Case 1 (nums[mid] > nums[end]): 
        - This means the right side is "lower" than it should be. The pivot (minimum) MUST be in the right half.
        - Move 'st = mid + 1'.
     4. Case 2 (nums[mid] <= nums[end]):
        - This means the right side is sorted normally. The minimum is either 'mid' itself or somewhere to the left.
        - Move 'end = mid'.
     5. Convergence: Just like the Peak problem, 'st' and 'end' will meet at the minimum.

   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        // Using < to avoid the infinite loop we discussed!
        while (st < end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] > nums[end]) {
                // The minimum is definitely in the right half
                st = mid + 1;
            } else {
                // nums[mid] <= nums[end]
                // mid could be the minimum, or it's to the left
                end = mid;
            }
        }
        
        // st and end converge to the minimum element
        return nums[st];
    }
};
