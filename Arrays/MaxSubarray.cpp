/* 
   PROBLEM: 53. Maximum Subarray (Kadane's Algorithm)
   TOPIC: Arrays / Dynamic Programming
   PATTERN: Incremental Sum / Greedy
   
   THEORY:
   - Task: Find the contiguous subarray with the largest sum.
   - Brute Force: Check all subarrays. Time: O(n^2), Space: O(1).
   - Optimal (Kadane's): 
     1. Maintain a running sum (currSum).
     2. If currSum becomes negative, it's better to restart from 0 (Greedy approach).
     3. Keep track of the maximum sum seen so far (maxSum).
   - Time Complexity: O(n), Space Complexity: O(1).
*/

#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN; // Sabse choti value se start karenge
        
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i]; // Current sum mein element add karo
            
            maxSum = max(maxSum, currSum); // Max update karo
            
            // AGAR SUM NEGATIVE HAI, TOH ISE RESTART KARO (0)
            if (currSum < 0) {
                currSum = 0;
            }
        }
        
        return maxSum; // Poora loop hone ke baad return
    }
};
