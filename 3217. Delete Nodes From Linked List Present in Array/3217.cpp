/*
This problem can be solved by simply checking if the next pointer has a value found in nums
For faster lookup, we can put all the elements of nums in an unordered_set, which provides O(1) search
I created a dummy pointer which points to the original head, just in case head itself has a value contained in nums
I also created a pointer called ptr, which starts at dummy and iterates through the linked list
For each node in the linked list:
- While the next pointer isn't nullptr, and the next pointer's value can be found in the unordered set, skip the next node by adjusting where the next pointer points
- Once the next pointer reaches nullptr, or the value is no longer found in the unordered set, we move ptr forward 1 step
When we've checked all nodes, return dummy->next, which would be the new head of the linked list
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for (int &num: nums) s.insert(num);
        ListNode* dummy = new ListNode(-1, head);
        ListNode* ptr = dummy;
        while (ptr != nullptr && ptr->next != nullptr)
        {
            // int nextVal = ptr->next->val;
            while (ptr->next != nullptr && s.find(ptr->next->val) != s.end()) ptr->next = ptr->next->next;
            ptr = ptr->next;
        }
        return dummy->next;
    }
};