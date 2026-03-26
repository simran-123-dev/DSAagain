/* 
   PROBLEM: 912. Sort an Array (LeetCode)
   TOPIC: Sorting / Divide and Conquer
   PATTERN: Merge Sort
   
   THEORY:
   - Task: Sort an array in O(N log N) time without using built-in sort functions.
   
   - Approach: Merge Sort (Divide & Conquer)
     1. Divide: Split the array into two halves until each sub-array contains a single element (base case).
     2. Conquer: Recursively sort both halves.
     3. Combine (Merge): Use two pointers to compare elements from both sorted halves and merge them into a temporary vector in sorted order.
     4. Copy Back: Transfer elements from the temporary vector back to the original array.

   - Time Complexity: O(N log N) in all cases (Best, Average, Worst).
   - Space Complexity: O(N) for the temporary vector used during the merge process.
*/

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        // Compare elements from both halves and push the smaller one
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // If elements remain in the left half
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // If elements remain in the right half
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy temp back to the original range [low, high]
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;   // Base case: single element or empty

        int mid = low + (high - low) / 2;

        // Recursive calls
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        
        // Merge sorted halves
        merge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
