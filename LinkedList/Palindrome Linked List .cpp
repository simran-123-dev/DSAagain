/* 
   PROBLEM: 234. Palindrome Linked List (LeetCode)
   TOPIC: Linked List / Arrays
   PATTERN: Array Conversion / Two Pointer Comparison
   
   THEORY:
   - Task: Determine if a singly linked list is a palindrome.
   
   - Approach 1: Array Conversion (Simple)
     1. Traverse the linked list and store all node values in a vector.
     2. Use two pointers (start and end) on the vector to check if it's a palindrome.
     3. Complexity: O(N) Time, O(N) Space.

   - Approach 2: Optimal In-place (Middle + Reverse + Compare)
     1. Find the middle using Slow/Fast pointers.
     2. Reverse the second half of the list.
     3. Compare the first half and the reversed second half.
     4. Complexity: O(N) Time, O(1) Space.
*/

#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ✅ 1. Array Conversion Approach (Easy to implement)
class SolutionArray {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        
        // Copy list values to array
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }
        
        // Use two-pointer approach on array
        int i = 0, j = vals.size() - 1;
        while (i < j) {
            if (vals[i++] != vals[j--])
                return false;
        }
        return true;
    }
};

// ✅ 2. Optimal In-place Approach (O(1) Space)
class SolutionOptimal {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverse(slow->next);

        // Step 3: Compare
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        while (p2) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};
