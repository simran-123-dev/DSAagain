/* 
   PROBLEM: 56. Merge Intervals (LeetCode)
   TOPIC: Arrays / Sorting
   PATTERN: Overlapping Intervals
   
   THEORY:
   - Task: Ek array diya hai intervals ka, humein overlapping intervals ko merge karke ek final list deni hai.
   
   - Approach:
     1. Sorting (Sabse Zaroori): Pehle intervals ko unke 'start time' ke basis par sort karo. Sorting se saare overlapping intervals ek ke baad ek aa jayenge.
     
     2. Iteration: 
        - Pehle interval ko 'result' array mein daal do.
        - Agle intervals ko check karo:
          - Case A (Overlap): Agar current interval ka 'start' pichle merged interval ke 'end' se chota ya barabar (<=) hai, toh iska matlab ye overlap ho raha hai. Iska end update kar do: max(last_end, current_end).
          - Case B (No Overlap): Agar overlap nahi hai, toh is interval ko naya entry maankar result mein push kar do.

   - Example: [[1,3],[2,6],[8,10]]
     - Sort: Already sorted.
     - [1,3] push kiya.
     - [2,6] check kiya: 2 <= 3 (overlap!). Update end to max(3, 6) -> [1,6].
     - [8,10] check kiya: 8 > 6 (no overlap). Push [8,10].
     - Final: [[1,6],[8,10]].

   - Time Complexity: O(n log n) - Sorting ki wajah se.
   - Space Complexity: O(n) - Result store karne ke liye (ya sorting ke liye use hui extra space).
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        // Step 2: Push the first interval to start comparing
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            // Check if current interval overlaps with the last merged interval
            if (intervals[i][0] <= merged.back()[1]) {
                // If overlap, update the end of the last interval
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                // If no overlap, add the current interval to the list
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
