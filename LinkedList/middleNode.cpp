/* 
   PROBLEM: 876. Middle of the Linked List (LeetCode)
   TOPIC: Linked List / Two Pointers
   PATTERN: Slow & Fast Pointers (Tortoise and Hare)
   
   THEORY:
   - Task: Find the middle node of a singly linked list. If there are two middle nodes, return the second one.
   
   - Approach: Two Pointers
     1. Initialize two pointers: 'slow' and 'fast', both pointing to the head.
     2. Strategy: Move 'fast' twice as fast as 'slow' (fast moves 2 steps, slow moves 1 step).
     3. Termination: When 'fast' reaches the end (nullptr) or the last node (fast->next == nullptr), 'slow' will exactly be at the middle.
     4. Property: This ensures O(N) time in a single pass without needing to calculate the total length first.

   - Time Complexity: O(N) - Single pass through the list.
   - Space Complexity: O(1) - Only two extra pointers used.
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
    ListNode* middleNode(ListNode* head) {
        // Handle empty list or single node
        if (!head) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast 2 steps and slow 1 step
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // When fast reaches the end, slow is at the middle
        return slow;
    }
};
