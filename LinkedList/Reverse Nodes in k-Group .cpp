/* 
   PROBLEM: 25. Reverse Nodes in k-Group (LeetCode)
   TOPIC: Linked List / Manipulation
   PATTERN: Group-wise Reversal (Recursive or Iterative)
   
   THEORY:
   - Task: Reverse nodes of a linked list 'k' at a time and return its modified list.
   
   - Approach: Recursive / Iterative Reversal
     1. Check Availability: First, check if there are at least 'k' nodes remaining. If not, return 'head' (no reversal).
     2. Identify Group: Locate the (k+1)-th node to serve as the start of the next group.
     3. Reverse Group: Reverse the current 'k' nodes using the standard iterative reversal pattern.
     4. Recursion: Recursively call the function for the remaining list.
     5. Connect: Connect the tail of the current reversed group (the original 'head') to the result of the recursive call.
     6. Result: The new head of the reversed group is returned.

   - Time Complexity: O(N) - Each node is visited and reversed exactly once.
   - Space Complexity: O(N/k) - Recursive stack depth (can be O(1) if implemented iteratively).
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if there are at least k nodes left
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (!curr) return head; // If less than k nodes, return head as is
            curr = curr->next;
        }

        // Step 2: Reverse the first k nodes
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;
        ListNode* tempHead = head;
        
        for (int i = 0; i < k; i++) {
            nextNode = tempHead->next;
            tempHead->next = prev;
            prev = tempHead;
            tempHead = nextNode;
        }

        // Step 3: head is now the tail of this reversed group
        // Recursively call for the rest and connect
        if (nextNode != nullptr) {
            head->next = reverseKGroup(nextNode, k);
        }

        // Step 4: prev is the new head of this reversed segment
        return prev;
    }
};
