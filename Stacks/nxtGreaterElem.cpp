
/* 
   PROBLEM: 496. Next Greater Element I (Brute Force Approach)
   TOPIC: Arrays / Hash Table
   PATTERN: Nested Linear Search
   
   THEORY:
   - Task: For each element in nums1, find its position in nums2 and then find the first element to its right that is larger.
   
   - Approach: 
     1. Iterate through 'nums1'.
     2. For each 'x', search through 'nums2' until 'x' is found.
     3. Once found, continue searching the rest of 'nums2' for the first 'num > x'.
     
   - Logic:
     - Outer Loop: Selects current target from nums1.
     - Inner Loop: Locates target in nums2 and finds its next greater neighbor.

   - Time Complexity: O(N * M)
   - Space Complexity: O(1) (excluding result storage)
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(int x : nums1) {
            bool found = false;
            int next = -1;
            for(int num : nums2) {
                if(num == x) found = true;
                else if(found && num > x) {
                    next = num;
                    break;
                }
            }
            result.push_back(next);
        }
        return result;
    }
};

/* 
   PROBLEM: 496. Next Greater Element I (Optimized Approach)
   TOPIC: Stacks / Hash Table
   PATTERN: Monotonic Decreasing Stack
   
   THEORY:
   - Task: Pre-calculate the Next Greater Element (NGE) for all elements in nums2 in a single pass.
   
   - Approach: 
     1. Use a stack to keep track of elements whose NGE hasn't been found yet.
     2. As we iterate 'nums2', if 'current' > 'stack.top', then 'current' is the NGE for the top element.
     3. Pop and store this relationship in a hash map.
     
   - Time Complexity: O(N + M)
   - Space Complexity: O(M)
*/

#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                ngeMap[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> result;
        for (int x : nums1) {
            result.push_back(ngeMap.count(x) ? ngeMap[x] : -1);
        }
        return result;
    }
};
