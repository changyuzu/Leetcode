/*
This problem can be solved usign Floyd's Cycle Finding Algorithm, or the Hare-Tortoise Algorithm, which uses fast-slow pointers
First, we check whether there is a cycle in the linked list
Start with both the fast and slow pointers set to head
While fast != nullptr AND fast->next != nullptr, we move slow 1 step forward and fast 2 steps forward
If, at any point, slow == fast, we know there's a cycle in this linked list
So how do we find the node where the cycle begins?
We set slow to head, and move both pointers forward 1 step until they reach the same node again
At this point, we can return fast, or slow, whichever is fine since they're the same node
If we reach the end of the linked list, there is no cycle, and we return -1
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
    ListNode *detectCycle(ListNode *head) {
        // if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};