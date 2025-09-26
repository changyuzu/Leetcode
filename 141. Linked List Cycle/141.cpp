/*
This problem can be solved using fast-slow pointers
The fast pointer moves forward 2 steps at a time, while the slow pointer moves 1 at a time
If there is a loop in the linked-list, the fast pointer is bound to meet with the slow pointer at some point during the iteration
If there is no loop, the fast pointer will reach the end of the linked list (nullptr) without ever meeting slow
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
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};