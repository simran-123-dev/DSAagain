

/* 
   PROBLEM: 739. Daily Temperatures (LeetCode)
   TOPIC: Stacks
   PATTERN: Monotonic Stack (Next Greater Element)
   
   THEORY:
   - Task: Find how many days you have to wait until a warmer temperature.
   
   - Approach: Monotonic Decreasing Stack
     1. Logic: Hum stack mein un dino ke "index" store karte hain jinka abhi tak koi "warmer day" nahi mila.
     2. Process: Jab bhi current temperature stack ke top wale temperature se zyada hota hai:
        - Iska matlab humein stack ke top wale index ke liye "next warmer day" mil gaya hai.
        - Hum distance calculate karte hain: `current_index - stack_top_index`.
        - Stack se pop karte hain aur process repeat karte hain.
     3. Push: Current index ko stack mein push kar dete hain taaki aage uske liye warmer day dhund sakein.

   - Time Complexity: O(N) - Har element maximum ek baar push aur ek baar pop hota hai.
   - Space Complexity: O(N) - Result vector aur stack ke liye.
*/

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; 
        
        for (int i = 0; i < n; i++) {
            // Check if current temp is warmer than the index at stack top
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;   
            }
            // Push current index to find its warmer day later
            st.push(i);
        }
        return ans;
    }
};
