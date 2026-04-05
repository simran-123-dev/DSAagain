commit 5e6f7g8
Author: Developer <dev@example.com>
Date:   Sun Apr 05 03:50:00 2026 +0100

    feat: add Next Greater Element II (Circular Array)

    - Added O(N^2) Brute Force for circular traversal
    - Added O(N) Monotonic Stack optimization using virtual doubling
    - Included complexity analysis and modulo logic for circularity

/* 
   PROBLEM: 503. Next Greater Element II (Brute Force)
   TOPIC: Arrays / Circular Search
   PATTERN: Nested Loops with Modulo
   
   THEORY:
   - Task: Find the next greater element in a circular array.
   
   - Approach: 
     1. For every index 'i', check the next 'n-1' elements in the array.
     2. Use the modulo operator (%) to "wrap around" to the start of the array once the end is reached.
     
   - Logic:
     - Outer loop runs 'n' times.
     - Inner loop runs 'n-1' times, checking nums[(i + j) % n].

   - Time Complexity: O(N^2)
   - Space Complexity: O(1) (excluding result storage)
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (nums[(i + j) % n] > nums[i]) {
                    res[i] = nums[(i + j) % n];
                    break;
                }
            }
        }
        return res;
    }
};

/* 
   PROBLEM: 503. Next Greater Element II (Optimized)
   TOPIC: Stacks / Monotonic Stack
   PATTERN: Virtual Doubling of Array
   
   THEORY:
   - Task: Efficiently find NGE in a circular array in O(N).
   
   - Approach: 
     1. Simulate a doubled array ([nums, nums]) to handle the circular property.
     2. Instead of physical doubling, iterate from index '2n - 1' down to '0'.
     3. Use a monotonic stack to store elements.
     
   - Logic:
     - While stack top is <= current element, pop (it cannot be an NGE).
     - If stack is not empty, 'stack.top' is the NGE for 'nums[i % n]'.
     - Push current element onto the stack for previous indices to check.

   - Time Complexity: O(N) - Each element is pushed and popped at most twice.
   - Space Complexity: O(N) for the stack.
*/

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; // Stores values (or indices)

        // Iterate backwards through a virtual doubled array
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            
            // Only fill result for the first 'n' indices (the actual array)
            if (i < n) {
                res[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        
        return res;
    }
};
