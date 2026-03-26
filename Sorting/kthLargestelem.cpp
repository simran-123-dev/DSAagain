/* 
   PROBLEM: 215. Kth Largest Element in an Array (LeetCode)
   TOPIC: Arrays / Sorting / Selection
   PATTERN: Quick Select (Hoare's Selection Algorithm)
   
   THEORY:
   - Task: Find the Kth largest element in an unsorted array without full sorting.
   
   - Approach: Quick Select
     1. Partitioning: Similar to Quick Sort, we pick a pivot and rearrange elements. 
     2. Ascending Strategy: By placing smaller elements on the left, the Kth largest element will end up at index 'n - k'.
     3. Reduction: Unlike Quick Sort which recurses into both halves, Quick Select only recurses into the half containing the target index.
     4. Randomization: Using a random pivot prevents the O(N²) worst-case scenario on already sorted data.

   - Time Complexity: O(N) average, O(N²) worst-case.
   - Space Complexity: O(1) iterative.
*/

#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        // In a sorted ascending array, the Kth largest is at index (n - k)
        int targetIdx = n - k;

        while (left <= right) {
            // Random pivot selection to ensure average O(N) performance
            int pivotIdx = left + rand() % (right - left + 1);
            int finalPivotIdx = partition(nums, left, right, pivotIdx);

            if (finalPivotIdx == targetIdx) {
                return nums[finalPivotIdx];
            } else if (finalPivotIdx > targetIdx) {
                right = finalPivotIdx - 1;
            } else {
                left = finalPivotIdx + 1;
            }
        }
        return -1;
    }

private:
    int partition(vector<int>& nums, int left, int right, int pivotIdx) {
        int pivotVal = nums[pivotIdx];
        
        // Move pivot to the end
        swap(nums[pivotIdx], nums[right]);

        int storeIdx = left;
        for (int i = left; i < right; i++) {
            // Moving smaller elements to the left
            if (nums[i] < pivotVal) {
                swap(nums[i], nums[storeIdx]);
                storeIdx++;
            }
        }

        // Move pivot to its final sorted place
        swap(nums[storeIdx], nums[right]);
        return storeIdx;
    }
};
