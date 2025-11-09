/*
This problem is pretty much an introduction to level-order traversal, or breadth first search (BFS)
First, start by checking whether root is a nullptr, in which case we return an empty vector
If not, we start the BFS
Initiate a queue, and a vector of vector of int for our answer
Push the current root into the queue
Then, while the queue isn't empty, we do the following:
- Check the current queue size, to keep track of the iteration that is the current level
- Initialize a row vector to keep track of the current level's elements
- While we go through a loop of the size of the current queue:
	- Get the front element of the queue
	- Push the value of the front element to our row vector
	- If the left element of the front element isn't a nullptr, push it into the queue
	- If the right element of the front element isn't a nullptr, push it into the queue
	- Pop the front element
- Once we've gone through all elements of the current level, append the row to our answer vector
Since we keep pushing the non-null left and right pointers of the nodes in the current level, the queue will continue until all elements are checked
When the queue doesn't have any remaining elements, return the answer vector
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            vector<int> row;
            while (s--)
            {
                TreeNode* front = q.front();
                row.push_back(front->val);
                q.pop();
                if (front->left != nullptr) q.push(front->left);
                if (front->right != nullptr) q.push(front->right);
            }
            ans.push_back(row);
        }
        return ans;
    }
};