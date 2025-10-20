/*
For this problem, I modified l1 in-place to save memory
The concept is the same, whether or not you decide to use a separate linked list
As you go through each node, keep track of the carry value, and put the sum % 10 value in your resulting list
You just need to be careful of cases where the sizes of the two linked lists are different, and cases where the carry value exceeds the original size of either linked list
In any case, I have 2 while loops:
- The first one keeps going while both l1 and l2 haven't reached nullptr
	- I took care of the case where l1 is shorter than l2 directly here
		- If l1->next == nullptr and carry > 0 OR l2 still has other nodes left, we attach another node with value 0 to the end of l1
- Since the case of l1 being shorter than l2 has been taken care of, the second while loop just takes care of cases where l1 is longer
	- Do note that in the original condition for extending l1, (carry > 0) is also a condition
	- So while l1 hasn't reached nullptr, we continue adding with the carry
	- While carry > 0, we keep extending l1
Once we've finished adding everything, return the head of the linked list
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = l1;
        while (l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            carry = (sum > 9);
            l1->val = sum % 10;
            if (l1->next == nullptr && (carry > 0 || l2->next != nullptr)) l1->next = new ListNode(0);
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            int sum = l1->val + carry;
            carry = (sum > 9);
            l1->val = sum % 10;
            if (carry > 0 && l1->next == nullptr) l1->next = new ListNode(0);
            l1 = l1->next;
        }
        return head;
    }
};