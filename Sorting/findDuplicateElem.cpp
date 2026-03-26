/* 
   PROBLEM: 442. Find All Duplicates in an Array (LeetCode)
   TOPIC: Arrays / Sorting
   PATTERN: Cyclic Sort
   
   THEORY:
   - Task: Find all elements that appear TWICE in an array of size 'n' where elements are in range [1, n].
   
   - Approach: Cyclic Sort
     1. Since the range is [1, n], use Cyclic Sort to place each number 'x' at index 'x-1'.
     2. While iterating, if 'nums[i]' is not at its correct position and the target position 'nums[nums[i]-1]' already has the correct value, it means we found a duplicate.
     3. After the sorting pass, any number that is NOT at its correct index ('nums[i] != i + 1') is a duplicate.
     4. Collect these 'nums[i]' values into the result vector.

   - Time Complexity: O(N) (one pass for sorting, one pass for identifying duplicates).
   - Space Complexity: O(1) (ignoring the space for the output list).
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> ans;

        // Step 1: Cyclic Sort - Place each number at index (nums[i] - 1)
        while (i < n) {
            int correct = nums[i] - 1;
            
            // Swap only if the current element is not at the correct position
            // and the target position doesn't already have the correct element
            if (nums[i] != nums[correct]) {
                swap(nums[i], nums[correct]);
            } else {
                i++;
            }
        }

        // Step 2: Identify duplicates
        // Elements that are not at their correct index are the duplicates
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
