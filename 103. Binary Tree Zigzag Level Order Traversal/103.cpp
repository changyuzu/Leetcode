/*
This problem is similar to 102. Binary Tree Level Order Traversal
So, also a BFS problem
The only difference is, every other row needs to be checked starting from the right, instead of the usual left
To do this simply, we can simply use a double-ended queue, or deque, which allows us to push and pop from the front and the back
We also need to keep track of whether the current level starts from the left or right, for which I declared a boolean variable named oddLevel
Push the original root into the deque, and while the deque isn't empty:
- Initialize an empty row
- Get the current size of the deque
- If we're at an odd level (starts from left, or front of the deque)
	- Get the front element as curr
	- If curr->left isn't a nullptr, push it to the back of the deque
	- If curr->right isn't a nullptr, push it to the back of the deque
	- Push curr->val into our row
- If we're at an even level (starts from right, or back of the deque)
	- Get the back element as curr
	- If curr->right isn't a nullptr, push it to the front of the deque
	- If curr->left isn't a nullptr, push it to the front of the deque
	- Push curr->val into our row
- Remember that at the odd levels, we start adding the next level's elements from the LEFT to the BACK, while at the even levels, we start adding from the RIGHT to the FRONT
- Once we've checked all elements at the current level, push the row into our ans vector
- Set oddLevel as its own opposite value (I did this by XOR-ing it with 1)
Once there are no more elements in the deque, return ans
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        deque<TreeNode*> q;
        bool oddLevel = true;
        vector<vector<int>> ans;
        q.push_back(root);
        while (!q.empty())
        {
            // cout << oddLevel << endl;
            vector<int> row;
            int s = q.size();
            if (oddLevel)
            {
                while (s--)
                {
                    TreeNode* curr = q.front();
                    q.pop_front();
                    if (curr->left != nullptr) q.push_back(curr->left);
                    if (curr->right != nullptr) q.push_back(curr->right);
                    row.push_back(curr->val);
                }
            }
            else
            {
                while (s--)
                {
                    TreeNode* curr = q.back();
                    q.pop_back();
                    if (curr->right != nullptr) q.push_front(curr->right);
                    if (curr->left != nullptr) q.push_front(curr->left);
                    row.push_back(curr->val);
                }
            }
            ans.push_back(row);
            oddLevel ^= 1;
        }
        return ans;
    }
};