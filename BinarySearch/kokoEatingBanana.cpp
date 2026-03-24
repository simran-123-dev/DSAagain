/* 
   PROBLEM: 875. Koko Eating Bananas (LeetCode)
   TOPIC: Arrays / Binary Search
   PATTERN: Binary Search on Answer (Monotonic Range)
   
   THEORY:
   - Task: Find the minimum eating speed 'k' such that Koko can eat all piles within 'h' hours.
   
   - Approach: Range-Based Search
     1. Define Search Space: 
        - Minimum speed (st): 1 banana/hour.
        - Maximum speed (end): The size of the largest pile (at this speed, she eats any pile in exactly 1 hour).
     2. Monotonicity: If Koko can finish at speed 'k', she can definitely finish at speed 'k+1'. We want the smallest such 'k'.
     3. Helper Function: For a given speed 'mid', calculate total hours:
        - Hours for a pile = ceil(pile / mid) -> In C++, use '(pile + mid - 1) / mid'.
     4. Binary Search (st < end):
        - If 'totalHours <= h': This speed works! But a slower speed might also work. Move 'end = mid'.
        - If 'totalHours > h': Speed is too slow. Move 'st = mid + 1'.

   - Time Complexity: O(N * log(M)) - Where N is number of piles and M is the max bananas in a pile.
   - Space Complexity: O(1) - Constant auxiliary space.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Find the maximum value in piles to set the upper bound
        int st = 1;
        int end = 0;
        for (int pile : piles) {
            end = max(end, pile);
        }

        while (st < end) {
            int mid = st + (end - st) / 2;
            
            // Calculate total hours needed at speed 'mid'
            long long totalHours = 0; // Use long long to avoid overflow
            for (int pile : piles) {
                // Equivalent to ceil(pile / mid)
                totalHours += (pile + mid - 1) / mid;
            }

            if (totalHours <= h) {
                // Possible answer, but try a smaller speed
                end = mid;
            } else {
                // Too slow, must increase speed
                st = mid + 1;
            }
        }

        return st;
    }
};
