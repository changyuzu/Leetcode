/*
My solution for this problem is inspired by 236. Lowest Common Ancestor of a Binary Tree
Basically, we perform a DFS to each leaf node, keeping track of each node's depth
The DFS function returns a pair of TreeNode and int, where the int represents the depth of the node
Once we reach nullptr, we know that the node before it could be a leaf node
I mark the depth of nullptr as -1 for easier identification
So we check the left and right nodes for each current node
If both left and right have depth of -1, then the current node is a leaf node, so we return the current node and its depth
Otherwise, if left and right have the same depth, then the current node's subtree contains nodes with the same depth, so we return the current node and the depth of the left or right nodes, as it's a lowest common ancestor
Otherwise, if the right node is a nullptr, or the left node's depth is larger than the right node, we return the left node and its depth
Otherwise, we return the right node and its depth
In the main function, we call the DFS function and cast the result into [ans, depth]
We just need to return ans, the lowest node which has all the deepest nodes in its subtree
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
#define pri pair<TreeNode*, int>
    pri check(TreeNode* root, int depth)
    {
        if (root == nullptr) return {root, -1};
        auto [left, dl] = check(root->left, depth+1);
        auto [right, dr] = check(root->right, depth+1);
        // cout << root->val << " " << depth << " " << dl << " " << dr << endl;
        if (dl < 0 && dr < 0) return {root, depth};
        else if (dl == dr) return {root, dl};
        else if (dr < 0 || dl > dr) return {left, dl};
        else return {right, dr};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto [ans, depth] = check(root, 0);
        // cout << depth << endl;
        return ans;
    }
};