/* 
   PROBLEM: 268. Missing Number (LeetCode)
   TOPIC: Arrays / Sorting / Bit Manipulation
   PATTERN: Multiple Approaches (Math, XOR, Cyclic Sort, Sorting)
   
   THEORY:
   - Task: Find the missing number in an array containing 'n' distinct numbers in range [0, n].
   
   - Approaches:
     1. Sum Formula: Total expected sum - actual sum.
     2. XOR Logic: (0^1^...^n) ^ (nums[0]^nums[1]^...^nums[n-1]) leaves the missing number.
     3. Cyclic Sort: Place each 'x' at 'nums[x]'. The index 'i' where 'nums[i] != i' is the answer.
     4. Sorting (N log N): Sort first, then check index mismatch.

   - Complexity:
     - Math/XOR/Cyclic: O(N) Time, O(1) Space.
     - Sorting: O(N log N) Time, O(1) Space.
*/

#include <vector>
#include <algorithm>

using namespace std;

// ✅ 1. Sum Formula Approach (Optimal & Simple)
class SolutionSum {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actualSum = 0;
        for(int x : nums) actualSum += x;
        
        int expectedSum = n * (n + 1) / 2;
        return expectedSum - actualSum;
    }
};

// ✅ 2. XOR Approach (Best for overflow safety)
class SolutionXOR {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i <= n; i++) ans ^= i;
        for(int x : nums) ans ^= x;
        return ans;
    }
};

// ✅ 3. Cyclic Sort Approach (Pattern-based)
class SolutionCyclic {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, n = nums.size();
        while(i < n) {
            if(nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            } else {
                i++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i) return i;
        }
        return n;
    }
};

// ✅ 4. Sorting Approach (N log N)
class SolutionSort {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] != i) return i;
        }
        return n;
    }
};
