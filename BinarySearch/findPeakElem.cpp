/* 
   PROBLEM: 162. Find Peak Element (LeetCode)
   TOPIC: Arrays / Binary Search
   PATTERN: Binary Search on Slopes
   
   THEORY:
   - Task: Find any peak element in O(log N) time.
   
   - The TLE Fix:
     1. Condition: Use 'while (st < end)' instead of '<='. This prevents an infinite loop when the pointers meet.
     2. Boundary: By checking 'nums[mid] < nums[mid + 1]', we are looking ahead. Using 'st < end' ensures that 'mid + 1' is always a valid index within the current search range.
     3. Convergence: When 'st == end', the pointers have "trapped" the peak, and we return that index.

   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/

#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        // Use < instead of <= to avoid infinite loop when st == end
        while (st < end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // We are on an upward slope, peak is to the right
                st = mid + 1;
            } else {
                // We are on a downward slope, mid could be the peak
                end = mid;
            }
        }
        
        // Loop ends when st == end, which is our peak
        return st;
    }
};
