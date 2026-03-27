/* 
   PROBLEM: 19. Remove Nth Node From End of List (LeetCode)
   TOPIC: Linked List / Two Pointers
   PATTERN: Fast & Slow Pointer (Fixed Gap)
   
   THEORY:
   - Task: Remove the 'n-th' node from the end of a singly linked list in a single pass.
   
   - Approach: Two Pointers with a Gap
     1. Dummy Node: Use a dummy node pointing to 'head' to handle cases where the head itself needs to be removed.
     2. Create Gap: Move a 'fast' pointer 'n' steps ahead. Now, the gap between 'slow' and 'fast' is 'n'.
     3. Synchronised Move: Move both 'slow' and 'fast' one step at a time until 'fast' reaches the last node.
     4. Final Position: At this point, 'slow' will be pointing to the node JUST BEFORE the target node.
     5. Deletion: Update 'slow->next' to 'slow->next->next' to bypass the target node.

   - Time Complexity: O(N) - Single pass through the list.
   - Space Complexity: O(1) - Constant extra space.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Create a dummy node to handle head removal
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Step 2: Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Step 3: Move both until fast reaches the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 4: slow is now at (N+1)th node from end, skip the Nth node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Memory cleanup
        delete nodeToDelete;
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
