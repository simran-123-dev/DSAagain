/* 
   PROBLEM: 2. Add Two Numbers (LeetCode)
   TOPIC: Linked List / Math / Simulation
   PATTERN: Elementary Addition (Carry Logic)
   
   THEORY:
   - Task: Add two non-negative numbers represented as linked lists (digits in reverse order).
   
   - Approach: Simulation of Addition
     1. Dummy Node: Use a dummy node to build the result list easily.
     2. Digit-by-Digit: Iterate through both lists using two pointers.
     3. Carry Handling: In each step, calculate 'sum = val1 + val2 + carry'. 
        - New digit = sum % 10.
        - New carry = sum / 10.
     4. Remainder: If one list is shorter, treat its value as 0. 
     5. Final Check: After the loop, if a carry remains (e.g., 5 + 5 = 10), create one last node with the carry value.

   - Time Complexity: O(max(M, N)) - Where M and N are the lengths of the two lists.
   - Space Complexity: O(max(M, N)) - To store the newly created result list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Step 1: Create a dummy node to act as the head of the result list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        // Step 2: Iterate through both lists until both are empty AND no carry remains
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get values from nodes, or 0 if the list has ended
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            // Step 3: Calculate sum and carry
            int sum = carry + x + y;
            carry = sum / 10;
            
            // Create new node with the single digit result
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            // Move pointers to the next nodes
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Step 4: The result starts from dummy's next
        ListNode* result = dummy->next;
        delete dummy; // Memory cleanup
        return result;
    }
};
