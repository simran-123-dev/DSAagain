/* 
   PROBLEM: 15. 3Sum (LeetCode)
   TOPIC: Arrays / Two-Pointers
   PATTERN: Sorting + Two-Pointer approach
   
   THEORY:
   - Task: Find all unique triplets [nums[i], nums[j], nums[k]] such that i != j != k and their sum is 0.
   
   - Approach:
     1. Sort the Array: Crucial for using Two-Pointer and avoiding duplicates.
     2. Fix One Element (i): Iterate through the array and for each 'nums[i]', find two other numbers (j and k) using Two-Pointers that sum to '-nums[i]'.
     3. Two-Pointer Hunt:
        - Set 'j = i + 1' and 'k = n - 1'.
        - If sum < 0: Move 'j++' to increase sum.
        - If sum > 0: Move 'k--' to decrease sum.
        - If sum == 0: Found a triplet! Add to result.
     4. Skip Duplicates: This is the most important part. After finding a triplet or picking 'i', skip all identical adjacent numbers to ensure unique results.

   - Time Complexity: O(n²) - One loop for 'i' and another Two-Pointer scan for 'j' and 'k'.
   - Space Complexity: O(1) or O(n) - Depending on the sorting implementation.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // Step 2: Skip duplicate elements for 'i'
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Two-pointer approach
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++; // Need a bigger number
                } 
                else if (sum > 0) {
                    k--; // Need a smaller number
                } 
                else {
                    // sum == 0, found a triplet
                    result.push_back({nums[i], nums[j], nums[k]});

                    // Step 4: Skip duplicates for 'j' and 'k'
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    // Move pointers after finding a valid triplet
                    j++;
                    k--;
                }
            }
        }
        return result;
    }
};
