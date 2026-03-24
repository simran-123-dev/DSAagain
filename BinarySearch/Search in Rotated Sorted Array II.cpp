/* 
   PROBLEM: 81. Search in Rotated Sorted Array II (LeetCode)
   TOPIC: Arrays / Searching
   PATTERN: Modified Binary Search with Duplicates
   
   THEORY:
   - Task: Find a target value in a rotated sorted array that CONTAINS duplicates.
   
   - Approach: Handle Ambiguity
     1. The Challenge: If 'nums[st] == nums[mid] == nums[end]', we cannot determine which half is sorted (e.g., [1,0,1,1,1]).
     2. Duplicate Handling: When the above condition occurs, simply increment 'st' and decrement 'end' to shrink the search space.
     3. Standard Logic: Once the ambiguity is removed, apply the same "Identify Sorted Half" logic from the previous problem.
     4. Return Type: This problem asks for a boolean (true/false) rather than an index.

   - Time Complexity: O(log N) average, but O(N) worst-case (if all elements are the same).
   - Space Complexity: O(1).
*/

#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) return true;

            // TRICKY PART: If st, mid, and end are the same, we can't tell which side is sorted
            if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
                st++;
                end--;
                continue;
            }

            // Identify the sorted half
            if (nums[st] <= nums[mid]) {
                // Left half is sorted
                if (nums[st] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else {
                // Right half is sorted
                if (nums[mid] < target && target <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};
