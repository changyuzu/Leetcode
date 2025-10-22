/*
This problem is similar to 24. Swap Nodes in Pairs
But instead of swapping each pair of nodes, we need to swap odd indexes to put them before even indexes
We need to alter the nodes' next pointers instead of the values, so we still need 3 pointers
- fast: Points to the odd index
- slow: Points to the slow index
- prev: Points to the previous odd index
Basically, we need to connect the odd indexes to the end of the previous odd index, and the even indexes to the node that would originally be the next node for the odd nodes
First, define some base conditions, where if head or head->next are nullptr, simply return head
That's because we can't swap the nodes when there are less than 2
If there are at least 2 nodes, we start by initializing the pointers:
- fast: head->next
- slow: head
- prev: head
Use this linked list as example: dummy -> 1 (S, P) -> 2 (F) -> 3 -> 4 -> 5 -> null
While fast and its next pointer aren't nullptr, do the following:
- Move both fast and slow forward
	dummy -> 1 (P) -> 2 (S) -> 3 (F) -> 4 -> 5 -> null
- Point slow->next to fast->next
	dummy -> 1 (P) -> 2 (S) -> 4 -> 5 -> null
							   ^
						  3 (F)|
- Point fast->next to prev->next
	dummy -> 1 (P) -> 2 (S) -> 4 -> 5 -> null
					  ^
				 3 (F)|
- Point prev->next to fast
	dummy -> 1 (P) -> 3 (F) -> 2 (S) -> 4 -> 5 -> null
- Move fast to the next element of slow, and prev 1 step forward
Repeat this until either fast or fast->next reaches nullptr, then return head
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        ListNode* prev = slow;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
            slow->next = fast->next;
            fast->next = prev->next;
            prev->next = fast;
            fast = slow->next;
            prev = prev->next;
        }
        return head;
    }
};