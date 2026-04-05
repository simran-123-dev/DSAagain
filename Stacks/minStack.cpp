/* 
   PROBLEM: 155. Min Stack (Standard Approach)
   TOPIC: Stacks / Design
   PATTERN: Dual Stack for Auxiliary Data
   
   THEORY:
   - Task: Support push, pop, top, and retrieving the minimum element in O(1) time.
   
   - Approach: Two Stacks
     1. Main Stack (st): Stores all the actual elements.
     2. Min Stack (minSt): Stores the "minimum so far" at each level.
     
   - Logic:
     - Push(x): Push 'x' to 'st'. If 'minSt' is empty or 'x' <= current min, push 'x' to 'minSt'.
     - Pop(): If 'st.top()' is the same as 'minSt.top()', pop from both. Otherwise, only pop from 'st'.
     - GetMin(): Simply return 'minSt.top()'.

   - Time Complexity: O(1) for all operations.
   - Space Complexity: O(N) in the worst case (if elements are pushed in non-increasing order).
*/

#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        // If minSt is empty or val is smaller than/equal to current min
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
/* 
   PROBLEM: 155. Min Stack (Optimized Approach)
   TOPIC: Stacks / Design / Math
   PATTERN: Value Encoding for O(1) Space
   
   THEORY:
   - Task: Retrieve minimum in O(1) time WITHOUT using an extra stack.
   
   - Approach: Mathematical Encoding
     1. Maintain a single variable 'minVal' to track the current minimum.
     2. Push Logic: If 'val' < 'minVal', instead of pushing 'val', we push a modified value:
        Formula: '2 * val - minVal'. Then update 'minVal = val'.
        (This modified value will always be smaller than the new 'minVal').
     3. Pop Logic: If 'st.top()' < 'minVal', it means the top is an encoded value. We must recover the previous minimum:
        Formula: 'minVal = 2 * minVal - st.top()'.
     
   - Time Complexity: O(1) for all operations.
   - Space Complexity: O(1) (Extra space besides the required stack).
*/

#include <stack>

using namespace std;
class MinStack {
private:
    long long minVal;
    stack<long long> st;

public:
    MinStack() {
        minVal = 0;  // initialize (safe default)
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minVal = val;
        }
        else{
            if(val < minVal){
                st.push(2LL * val - minVal);  // corrected formula
                minVal = val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long topVal = st.top();
        st.pop();

        if(topVal < minVal){
            minVal = 2LL * minVal - topVal;
        }
    }
    
    int top() {
        if(st.empty()) return -1;  // safety

        if(st.top() < minVal){
            return (int)minVal;
        }
        return (int)st.top();
    }
    
    int getMin() {
        if(st.empty()) return -1;  // safety
        return (int)minVal;
    }
};
