/* 
   PROBLEM: 21. Merge Two Sorted Lists (LeetCode)
   TOPIC: Linked List / Recursion / Iteration
   PATTERN: Dummy Node + Two Pointer
   
   THEORY:
   - Task: Merge two sorted linked lists into one sorted list.
   
   - Approach: Dummy Node + Comparison
     1. Create a 'dummy' node to simplify the process of attaching the first node.
     2. Use a 'tail' pointer to keep track of the last node in the merged list.
     3. Iterate through both lists simultaneously using two pointers.
     4. Compare the values at 'list1' and 'list2'. Attach the smaller node to 'tail->next' and move that list's pointer forward.
     5. Handle Remaining Nodes: If one list finishes before the other, attach the remaining part of the non-empty list to 'tail->next'.
     6. Return 'dummy->next'.

   - Time Complexity: O(N + M) - Where N and M are the lengths of the two lists.
   - Space Complexity: O(1) - Merging is done by rearranging existing pointers.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Step 1: Create a dummy node to act as a placeholder
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Step 2: Iterate through both lists and pick the smaller element
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Step 3: Attach the remaining nodes of the non-empty list
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // Return the actual head (next node after dummy)
        return dummy.next;
    }
};
