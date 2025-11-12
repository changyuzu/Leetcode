/*
This problem can be solved using 2 pointers and a stack
First, we can find the middle point of the linked list with the fast-slow pointers
Then, starting from the middle point to the end of the linked list, we start pushing the nodes into the stack
With this, we don't need to keep track of the number of nodes in the linked list
Once we've pushed all the nodes in the later half of the linked list, reset slow to head and fast to head->next
While the stack isn't empty, do the following:
- Assign slow->next to the top element of the stack and pop from the stack
- Move slow forward, so it becomes the node that was originally on top of the stack
- Assign slow->next to fast
- Move both fast and slow forward
Once we've finished, remember to assign the pointer of the last node to nullptr
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
    void reorderList(ListNode* head) {
        if (head->next == nullptr) return;
        stack<ListNode*> st;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        while (slow != nullptr)
        {
            st.push(slow);
            slow = slow->next;
        }
        slow = head;
        fast = head->next;
        while (!st.empty())
        {
            slow->next = st.top();
            st.pop();
            slow = slow->next;
            slow->next = fast;
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = nullptr;
        // cout << slow->val << " " << fast->val << endl;
    }
};