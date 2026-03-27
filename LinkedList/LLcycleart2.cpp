/* 
   PROBLEM: 142. Linked List Cycle II (LeetCode)
   TOPIC: Linked List / Two Pointers
   PATTERN: Floyd's Cycle-Finding Algorithm (Find Entry Point)
   
   THEORY:
   - Task: Find the exact node where the cycle begins. If no cycle exists, return NULL.
   
   - Approach: Two-Step Strategy
     1. Detection: Use 'slow' and 'fast' pointers to detect if a cycle exists. If they meet, a cycle is present.
     2. Entry Point Logic: Once they meet, reset 'slow' to the head. Keep 'fast' at the meeting point.
     3. Synchronised Move: Move both 'slow' and 'fast' one step at a time. The node where they meet again is the start of the cycle.
     4. Mathematical Proof: The distance from head to cycle-start is equal to the distance from the meeting point to cycle-start.

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
    ListNode *detectCycle(ListNode *head) {
        // Base case: empty or single node list
        if (!head || !head->next) return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect if a cycle exists
        bool hasCycle = false;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        // If no cycle was found, return NULL
        if (!hasCycle) return nullptr;

        // Step 2: Find the start of the cycle
        // Reset slow to head, keep fast at the meeting point
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Both pointers now point to the cycle entry node
        return slow;
    }
};
