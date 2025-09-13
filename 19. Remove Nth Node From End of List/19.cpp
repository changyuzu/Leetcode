/*
For this problem, we use the fast-slow pointer approach to solve the problem in one pass
First, the fast pointer moves forward n steps
If the fast pointer has reached the end of the list, that means we need to remove the first element, so simply return the next pointer of head
Otherwise, we start the slow pointer at the head of the linked list, and move forward until fast reaches the last non-null element
We need the fast element to be at the last non-null element, because when fast reaches null, the slow pointer is at the node that we should remove
But in order to remove an element, we need to be at the element before it, so we stop both pointers before fast reaches null
Then we can just assign the next pointer of slow to the next element of the removed node, and return head
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
        ListNode* fast = head;
        while (n--) fast = fast->next;
        if (fast == nullptr) return head->next;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};