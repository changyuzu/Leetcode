/*
For now, I can only solve this problem using O(n) extra space in the form of a minHeap
First, check whether head or head->next are nullptr, in which case we simply return head
Otherwise, we do our sorting
I first defined a comparator function for the minHeap, which compares the values of two nodes
Then, push all elements of the linked list into the priority queue
Declare a new dummy list node called dummy, which will point to the head of the new linked list, and a node called prev to keep track of the previous node
While minHeap isn't empty, do the following:
- Point the next pointer of prev to the topmost element of the minHeap and pop from it
- Mpve prev 1 step forward
Once minHeap is empty, remember to point the next pointer of prev to nullptr, to mark the end of the linked list
Lastly, we return the next pointer of the dummy pointer
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto compare = [] (ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap (compare);
        ListNode* dummy = new ListNode(-1, head);
        while (head != nullptr)
        {
            // cout << head->val << endl;
            minHeap.push(head);
            head = head->next;
        }
        ListNode* prev = dummy;
        // cout << minHeap.size() << endl;
        while (!minHeap.empty())
        {
            prev->next = minHeap.top();
            minHeap.pop();
            // cout << minHeap.empty() << endl;
            prev = prev->next;
            // cout << prev->val << endl;
        }
        prev->next = nullptr;
        return dummy->next;
    }
};