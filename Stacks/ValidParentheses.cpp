/* 
   PROBLEM: 20. Valid Parentheses (LeetCode)
   TOPIC: Stacks
   PATTERN: Stack-based Sequence Validation
   
   THEORY:
   - Task: Determine if the input string of brackets is valid.
   
   - Approach: LIFO (Last-In-First-Out)
     1. The Challenge: Brackets must close in the correct order, and the most recently opened bracket must be the first one to close.
     2. Push Logic: If we encounter an opening bracket '(', '[', or '{', push it onto the stack.
     3. Pop/Check Logic: If we encounter a closing bracket:
        - Check if the stack is empty (if so, it's an unmatched closing bracket -> invalid).
        - Check if the top of the stack matches the corresponding opening bracket.
        - If it matches, pop it; otherwise, the sequence is invalid.
     4. Final Check: After the loop, the stack must be empty for the string to be valid.

   - Time Complexity: O(N) - We traverse the string once.
   - Space Complexity: O(N) - In the worst case (all opening brackets), we store all characters in the stack.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char val : s) {
            // Push opening brackets
            if (val == '(' || val == '[' || val == '{') {
                st.push(val);
            } 
            else {
                // If we see a closing bracket but stack is empty, it's invalid
                if (st.empty()) {
                    return false;
                }
                
                // Check for mismatches
                if (val == ')' && st.top() != '(') return false;
                if (val == ']' && st.top() != '[') return false;
                if (val == '}' && st.top() != '{') return false;
                
                // If it matches, remove the opening bracket
                st.pop();
            }
        }
        // If stack is empty, all brackets were matched correctly
        return st.empty();
    }
};
