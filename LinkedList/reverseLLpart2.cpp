/* 
   PROBLEM: 92. Reverse Linked List II (LeetCode)
   TOPIC: Linked List / Manipulation
   PATTERN: Partial Reversal (In-place)
   
   THEORY:
   - Task: Reverse the nodes of a linked list from position 'left' to 'right'.
   
   - Approach: One-Pass Iterative
     1. Dummy Node: Use a dummy node to handle cases where 'left' is 1 (reversing from the head).
     2. Positioning: Move a 'prev' pointer to the node just before the reversal starts (position 'left-1').
     3. Reversal Logic (The "Bridge" Swap):
        - Set 'curr' as 'prev->next'.
        - For each step (up to 'right-left' times):
          a. Identify 'next' node as 'curr->next'.
          b. Detach 'next' and re-insert it immediately after 'prev'.
          c. Update pointers to maintain the rest of the list.
     4. Result: Return 'dummy->next'.

   - Time Complexity: O(N) - We traverse the list once.
   - Space Complexity: O(1) - No extra space used except pointers.
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Base case: No reversal needed
        if (!head || left == right) return head;

        // Step 1: Create dummy node to simplify head changes
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Reach the node just before the 'left' position
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 3: Reversing the specified sub-list
        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = curr->next;
            
            // Re-wiring pointers to reverse 'nextNode'
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        // Step 4: Cleanup and return
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
