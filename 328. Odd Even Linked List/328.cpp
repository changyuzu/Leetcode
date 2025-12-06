/*
This problem can be solved using 2 pointers
One keeps track of the odd nodes, the other keeps track of the even nodes
So, we can keep track of the odd nodes and even nodes separately, and connect the end of the odd nodes to the head of the even nodes
Because of this, we also need to keep track of where the even node starts
Start by checking if head or head->next are nullptr, in which case there is no need to rearrange, and we just return head
Otherwise, we declare the 2 pointers for odd and even, and another pointer for the head of the even list
Then, we just need to rearrange the next pointers for the nodes accordingly
The next pointer of `odd` will be the next pointer of `even`, making the previous odd node point to the next odd node
Move odd forward, then do the same for the even node and mode even forward
Remember that we must stop before odd reaches nullptr, hence why I added (even->next != nullptr) in the condition for the while loop
Once we've grouped the odd and even nodes, just connect the last odd node to the head of the even nodes, and return head
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
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = even;
        while (odd != nullptr && even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};