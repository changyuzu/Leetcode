/*
This problem can be solved by simply comparing the values of the two list nodes at the current point
If list2 is smaller than list1, then we attach list2 to the end of the current sorted list and move list2 forward
Otherwise, we attach list1 to the end of the current sorted list and move list1 forward
We just need to check for cases where list1 and/or list2 are nullptr
And, since one of the linked lists is bound to reach the end first, we need to ensure that the rest of the remaining list is also attached to the sorted linked list
I used a dummy head with its next pointer pointed to the first node of the sorted linked list, so we can just return its next pointer once we've finished going through all the nodes
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
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        else if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        ListNode* head = new ListNode();
        if (list2->val < list1->val)
        {
            head = list2;
            list2 = list2->next;
        }
        else
        {
            head = list1;
            list1 = list1->next;
        }
        ListNode* dummy = new ListNode(-1, head);
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list2->val < list1->val)
            {
                head->next = list2;
                head = head->next;
                list2 = list2->next;
            }
            else
            {
                head->next = list1;
                head = head->next;
                list1 = list1->next;
            }
        }
        while (list1 != nullptr)
        {
            head->next = list1;
            head = head->next;
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            head->next = list2;
            head = head->next;
            list2 = list2->next;
        }
        return dummy->next;
    }
};