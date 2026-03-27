/* 
   PROBLEM: 41. First Missing Positive (LeetCode)
   TOPIC: Arrays / Sorting
   PATTERN: Cyclic Sort (In-place)
   
   THEORY:
   - Task: Find the smallest missing positive integer in O(N) time and O(1) space.
   
   - Approach:
     1. Use Cyclic Sort to place each number 'x' at index 'x-1' (e.g., 1 at index 0).
     2. Ignore numbers <= 0 or > n (as they can't be the smallest missing positive).
     3. After sorting, the first index 'i' where 'nums[i] != i + 1' tells us that 'i + 1' is missing.
     4. If all match, the answer is 'n + 1'.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        // Step 1: Cyclic Sort
        while (i < n) {
            // Correct position for x is index x-1
            // Use long long or check range to prevent overflow/errors
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }

        // Step 2: Find the first mismatch
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // Step 3: If all positions match, n+1 is the missing one
        return n + 1;
    }
};
