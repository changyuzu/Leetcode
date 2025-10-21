/*
For this problem, we need to swap every pair of nodes
We can't modify the values of the nodes, so we can only modify their next pointers
We can do this with 3 pointers:
- fast: the node in front
- slow: the node behind
- prev: the node before slow, to connect the swapped nodes
Let's take this linked list for example: dummy -> 1 -> 2 -> 3 -> 4 -> null
I put a dummy pointer at the beginning so we can return the head of the linked list after the swaps
The fast pointer starts at the head, while slow and prev starts at the dummy node
Each iteration, we start by moving the fast and slow pointers forward and do the swap
To do the swap, we need to do the following things in order:
- Direct the next pointer of slow to the next pointer of fast
	dummy (prev) -> 1 (slow) -> 3 -> 4 -> null
								^
						2 (fast)|
- Direct the next pointer of fast to slow
	dummy (prev) -> 1 (slow) -> 3 -> 4 -> null
					^
			2 (fast)|
- Direct the next pointer of prev to fast
	dummy (prev) -> 2 (fast) -> 1 (slow) -> 3 -> 4 -> null
- Move fast to the next pointer of slow, and prev to slow
	dummy -> 2 -> 1 (slow, prev) -> 3 (fast) -> 4 -> null
The iteration continues to repeat while fast and its next element haven't reached the nullptr
This takes care of cases where there are an odd number of nodes
Once we've reached the end, return the next pointer of the dummy node
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* fast = head;
        ListNode* slow = dummy;
        ListNode* prev = dummy;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
            slow->next = fast->next;
            fast->next = slow;
            prev->next = fast;
            fast = slow->next;
            prev = slow;
        }
        return dummy->next;
    }
};