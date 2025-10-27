/*
This problem can be solved by keeping track of 3 pointers:
- fast: The pointer that goes first, k steps in front of slow
- slow: The pointer that goes later, which will become the new end of the linked list
- newHead: The pointer that goes 1 step in front of slow, which will become the new head
First, start by defining the conditions where we simply return head: head == nullptr OR k == 0
Because there's nothing to rotate if there are no nodes, and there is no rotation when k is 0
Once we've checked those conditions, we define our head pointer and a counter for how many nodes are in the linked list
We need the counter because the problem statement doesn't specify that k must be within the range of the number of nodes
Keeping count of the number of nodes allows us to avoid having to rerun the loop multiple times by simply counting k % count to get the actual rotation steps
So, while fast != nullptr and k gets decremented, fast goes forward and count increments
If fast reaches nullptr, we calculate the actual rotation steps with k %= count
If k == 0, no rotation is needed, so return head
Otherwise, we put fast to head again, and move fast k steps forward
Initiate slow to head, and newHead to slow->next
Then, while fast != nullptr and fast->next != nullptr, we move all pointers forward
Once fast has reached the node before nullptr, we rearrange the pointers
- slow becomes the new end of the linked list, so put slow->next = fast->next (nullptr)
- fast will point to the original head of the linked list, so fast->next = head
- newHead is the new head of the rotated linked list, which we return
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;
        int count = 0;
        ListNode* fast = head;
        while (fast != nullptr && k--)
        {
            fast = fast->next;
            count++;
        }
        // cout << count << " " << k << endl;
        if (fast == nullptr)
        {
            k %= count;
            // cout << k << endl;
            if (k == 0) return head;
            fast = head;
            while (k--) fast = fast->next;
        }
        ListNode* slow = head;
        ListNode* newHead = slow->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
            newHead = newHead->next;
        }
        slow->next = fast->next;
        fast->next = head;
        return newHead;
    }
};