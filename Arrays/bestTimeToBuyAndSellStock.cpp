/* 
   PROBLEM: 121. Best Time to Buy and Sell Stock (LeetCode)
   TOPIC: Arrays / Greedy / Sliding Window Concept
   PATTERN: One-Pass Min-Tracking
   
   THEORY:
   - Task: Maximize profit by choosing one day to buy and a future day to sell.
   - Brute Force: Check every pair (buy, sell) using two loops. O(n^2).
   - Optimal Approach (Greedy/One-Pass):
     1. Maintain a 'minPrice' variable to track the lowest price seen so far.
     2. For each price, calculate the 'currentProfit' (price - minPrice).
     3. Keep updating 'maxProfit' if 'currentProfit' is greater than the previous max.
     4. This ensures we always sell at the best price relative to the lowest historical price.
   - Time Complexity: O(n) - Single pass through the array.
   - Space Complexity: O(1) - Only two extra variables used.
*/

#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // Stores the minimum price found so far
        int maxProfit = 0;      // Stores the maximum profit achieved
        
        for (int price : prices) {
            // Update the minimum price (Buy low)
            minPrice = min(minPrice, price); 
            
            // Update the maximum profit (Sell high)
            // Profit is calculated by (Today's Price - Historical Min Price)
            maxProfit = max(maxProfit, price - minPrice); 
        }
        
        return maxProfit;
    }
};
