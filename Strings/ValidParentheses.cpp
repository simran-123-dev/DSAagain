/* 
   PROBLEM: 20. Valid Parentheses (LeetCode)
   TOPIC: Strings / Stacks
   PATTERN: LIFO (Last-In, First-Out) Matching
   
   THEORY:
   - Task: Determine if an input string containing '(', ')', '{', '}', '[' and ']' is valid.
   - A string is valid if:
     1. Open brackets must be closed by the same type of brackets.
     2. Open brackets must be closed in the correct order.
   
   - Approach: Using a Stack
     1. Iterate through each character:
        - If it's an OPENING bracket ('(', '[', '{'), push it onto the stack.
        - If it's a CLOSING bracket:
          a. Check if stack is empty: If yes, return false (no matching opening bracket).
          b. Check the top of the stack: If the top doesn't match the current closing bracket, return false.
          c. If it matches: Pop the stack and continue.
     2. Final Check: After the loop, the stack must be empty. If something is left, it means some brackets weren't closed.

   - Time Complexity: O(n) - Single pass through the string.
   - Space Complexity: O(n) - In the worst case (e.g., "(((((("), we push all characters onto the stack.
*/

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char val : s) {
            // Step 1: If opening bracket, push to stack
            if (val == '(' || val == '[' || val == '{') {
                st.push(val);
            } 
            else {
                // Step 2: If closing bracket, check stack status
                if (st.empty()) {
                    return false; // No opening bracket to match
                }
                
                // Step 3: Match with the top of the stack
                if (val == ')' && st.top() != '(') {
                    return false;
                }
                if (val == ']' && st.top() != '[') {
                    return false;
                }
                if (val == '}' && st.top() != '{') {
                    return false;
                }
                
                // Step 4: If matched, pop the opening bracket
                st.pop();
            }
        }
        
        // Final check: All brackets must be popped for a valid string
        return st.empty();
    }
};
