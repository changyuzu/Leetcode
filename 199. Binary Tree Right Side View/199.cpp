/*
This problem can be solved with BFS
First, take care of the case of an empty tree, in which we return an empty vector
Otherwise, we just need to keep track of the rightmost node of each level and put the value in our answer vector
For all nodes in the binary tree, if the current node's left pointer isn't nullptr, push it to the queue
Same for the right pointer
Do note that we can't only push the right side, because there might be cases that the depth of the right subtree is less than the left subtree
In this case, the rightmost node would be on the left subtree, so we must always push non-null left and right child nodes
Once we've traversed all the levels of the tree, we return our answer vector
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if (s == 0) ans.push_back(curr->val);
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
        }
        return ans;
    }
};