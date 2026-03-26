/* 
   PROBLEM: 448. Find All Numbers Disappeared in an Array (LeetCode)
   TOPIC: Arrays / Sorting / Hash Map
   PATTERN: Cyclic Sort (Optimal)
   
   THEORY:
   - Task: Find all integers in the range [1, n] that do not appear in 'nums'.
   
   - Approach 1: Hash Map (Frequency)
     1. Use an unordered_map to store the presence of each number.
     2. Iterate from 1 to n; if a number is not in the map, it's missing.
     3. Complexity: O(N) Time, O(N) Space.

   - Approach 2: Cyclic Sort (In-place)
     1. Since the range is [1, n], the correct index for 'nums[i]' is 'nums[i] - 1'.
     2. Swap numbers until they are at their correct index or a duplicate is found.
     3. After sorting, any index 'i' where 'nums[i] != i + 1' indicates that 'i + 1' is missing.
     4. Complexity: O(N) Time, O(1) Space (Optimal).
*/

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ✅ 1. Hash Map Approach (Easy & Simple)
class SolutionMap {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        for(int num : nums) {
            freq[num] = 1;  // mark present
        }
        
        vector<int> ans;
        for(int i = 1; i <= n; i++) {
            if(freq.find(i) == freq.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// ✅ 2. Cyclic Sort Approach (In-place / Pattern-based)
class SolutionCyclic {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = 0, n = nums.size();

        // Cyclic Sort: Place each number at its correct index (nums[i]-1)
        while (i < n) {
            int correct = nums[i] - 1;

            if (nums[i] != nums[correct]) {
                swap(nums[i], nums[correct]);
            } else {
                i++;
            }
        }

        // Find missing numbers by checking mismatched indices
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};
