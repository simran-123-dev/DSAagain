/* 
   PROBLEM: 33. Search in Rotated Sorted Array (LeetCode)
   TOPIC: Arrays / Searching
   PATTERN: Modified Binary Search
   
   THEORY:
   - Task: Find a target value in a sorted array that has been rotated at an unknown pivot.
   
   - Approach: Range Identification Method
     1. Invariants: In a rotated sorted array, at least one half (left or right) of the current range [st, end] is always sorted.
     2. Midpoint Check: Standard 'st + (end - st) / 2' and check if 'nums[mid] == target'.
     3. Identify Sorted Half:
        - If 'nums[st] <= nums[mid]', the left half is sorted.
        - Otherwise, the right half must be sorted.
     4. Target Check: 
        - If target is within the sorted half's range, narrow the search to that half.
        - If not, the target must be in the unsorted/other half.
     5. Efficiency: This avoids finding the pivot point explicitly.

   - Time Complexity: O(log N) - Logarithmic search despite the rotation.
   - Space Complexity: O(1) - Constant auxiliary space.
*/

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int end = n - 1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            if (target == nums[mid]) {
                return mid;
            }
            
            // Check if the left side [st...mid] is sorted
            if (nums[st] <= nums[mid]) {
                // If target is within the sorted left range
                if (nums[st] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } 
            // Otherwise, the right side [mid...end] must be sorted
            else {
                // If target is within the sorted right range
                if (nums[mid] < target && target <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
