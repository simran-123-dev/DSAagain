/* 
   PROBLEM: 4. Median of Two Sorted Arrays (LeetCode)
   TOPIC: Arrays / Binary Search / Divide and Conquer
   PATTERN: Binary Search on Partitions
   
   THEORY:
   - Task: Find the median of two sorted arrays in logarithmic time.
   
   - Approach: Partitioning Method
     1. Smaller Array First: Always perform binary search on the smaller array (nums1) to ensure the $O(\log(min(n, m)))$ complexity.
     2. Partitioning: Divide both arrays into two halves such that:
        - The total number of elements on the left equals the total on the right.
        - Every element on the left is $\le$ every element on the right.
     3. Binary Search Logic: 
        - Find 'i' (partition in nums1) and 'j' (partition in nums2).
        - Check if 'L1 <= R2' and 'L2 <= R1'.
        - If 'L1 > R2', we are too far right in nums1; move 'end = i - 1'.
        - If 'L2 > R1', we are too far left in nums1; move 'st = i + 1'.
     4. Median Calculation:
        - If total elements are odd: 'max(L1, L2)'.
        - If even: '(max(L1, L2) + min(R1, R2)) / 2.0'.

   - Time Complexity: O(log(min(N, M))) - Extremely efficient.
   - Space Complexity: O(1) - No merging or extra arrays used.
*/

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();
        int st = 0, end = n1;

        while (st <= end) {
            int i = st + (end - st) / 2; // Partition in nums1
            int j = (n1 + n2 + 1) / 2 - i; // Partition in nums2

            // Edge cases: use INT_MIN/INT_MAX if partition is at the boundaries
            int L1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int R1 = (i == n1) ? INT_MAX : nums1[i];
            int L2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int R2 = (j == n2) ? INT_MAX : nums2[j];

            if (L1 <= R2 && L2 <= R1) {
                // Correct partition found
                if ((n1 + n2) % 2 == 0) {
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                } else {
                    return max(L1, L2);
                }
            } else if (L1 > R2) {
                // Too far right in nums1
                end = i - 1;
            } else {
                // Too far left in nums1
                st = i + 1;
            }
        }
        return 0.0;
    }
};
