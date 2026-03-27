/* 
   PROBLEM: 160. Intersection of Two Linked Lists (LeetCode)
   TOPIC: Linked List / Two Pointers
   PATTERN: Two Pointer "Path Switch" Strategy
   
   THEORY:
   - Task: Find the node at which the intersection of two singly linked lists begins. Return NULL if there is no intersection.
   
   - Approach 1: Difference in Length
     1. Calculate lengths of both lists.
     2. Move the pointer of the longer list ahead by the difference (len1 - len2).
     3. Move both pointers together until they meet.

   - Approach 2: Two Pointer Path Switch (Most Elegant)
     1. Initialize two pointers 'p1' and 'p2' at the heads of 'listA' and 'listB'.
     2. Move both pointers one step at a time.
     3. When 'p1' reaches the end, redirect it to the head of 'listB'.
     4. When 'p2' reaches the end, redirect it to the head of 'listA'.
     5. Intersection: If they intersect, they will meet at the intersection node because they both travel exactly 'lenA + lenB' distance.
     6. No Intersection: If they don't intersect, they will both meet at 'nullptr' after switching paths.

   - Time Complexity: O(M + N) - Where M and N are lengths of the lists.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *p1 = headA;
        ListNode *p2 = headB;

        // Loop until pointers meet or both become NULL
        while (p1 != p2) {
            // If p1 reaches end, switch to headB; else move to next
            p1 = (p1 == nullptr) ? headB : p1->next;
            
            // If p2 reaches end, switch to headA; else move to next
            p2 = (p2 == nullptr) ? headA : p2->next;
        }

        // Returns the meeting node (intersection) or NULL
        return p1;
    }
};
