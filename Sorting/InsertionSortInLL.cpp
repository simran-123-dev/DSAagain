/* 
   PROBLEM: 147. Insertion Sort List (LeetCode)
   TOPIC: Linked List / Sorting
   PATTERN: Insertion Sort on Linked List
   
   THEORY:
   - Task: Sort a linked list using the insertion sort algorithm.
   
   - Approach: Dummy Node + Pointer Manipulation
     1. Create a 'dummy' node to act as the head of the sorted list.
     2. Iterate through the original list using a 'curr' pointer.
     3. For each 'curr' node, find its correct position in the sorted list by starting from the 'dummy'.
     4. Find the position where 'prev->next->val' is greater than 'curr->val'.
     5. Insert 'curr' between 'prev' and 'prev->next'.
     6. Move to the next node stored in a 'next' pointer.

   - Time Complexity: O(N²) - Worst case (reverse sorted list).
   - Space Complexity: O(1) - Sorting is done in-place.
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Dummy node to handle insertions at the head easily
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;

        while (curr) {
            // Find the insertion point in the sorted part
            ListNode* prev = dummy;
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Save the next node to process
            ListNode* next = curr->next;

            // Insert curr into the sorted list
            curr->next = prev->next;
            prev->next = curr;

            // Move to the next node in the original list
            curr = next;
        }

        ListNode* result = dummy->next;
        delete dummy; // Memory cleanup
        return result;
    }
};
