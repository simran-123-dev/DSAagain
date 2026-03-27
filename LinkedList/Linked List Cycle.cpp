/* 
   PROBLEM: 141. Linked List Cycle (LeetCode)
   TOPIC: Linked List / Two Pointers
   PATTERN: Floyd's Cycle-Finding Algorithm (Tortoise and Hare)
   
   THEORY:
   - Task: Determine if a linked list has a cycle (where a node's 'next' points back to a previous node).
   
   - Approach: Slow & Fast Pointers
     1. Initialize 'slow' and 'fast' pointers at the head.
     2. Move 'slow' one step and 'fast' two steps at a time.
     3. Logic: If there is no cycle, 'fast' will reach the end (nullptr).
     4. Intersection: If there is a cycle, the 'fast' pointer will eventually "lap" the 'slow' pointer, and they will meet at the same node.
     5. Verification: If 'slow == fast', return true.

   - Time Complexity: O(N) - Linear scan.
   - Space Complexity: O(1) - Constant space used.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Base Case: Empty list or single node cannot have a cycle
        if (!head || !head->next) return false;

        ListNode *slow = head;
        ListNode *fast = head;

        // Move fast 2 steps and slow 1 step
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // If they meet, a cycle exists
            if (slow == fast) {
                return true;
            }
        }

        // If fast reaches the end, no cycle exists
        return false;
    }
};
