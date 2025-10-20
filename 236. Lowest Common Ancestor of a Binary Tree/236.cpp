/*
This problem can be solved using DFS
So, we need to search for the lowest root that has both p and q as descendants
We can start by searching each root until we either reach p, q, or nullptr
When we do, we return that root
So for each node, there are 4 possible outcomes:
- None of the roots are found from either sides of its roots, return null
- p is found, return p
- q is found, return q
- p and q are found, 1 on each side, return root
Setting this condition takes care of situations where the lowest common ancestor is one of the nodes itself, like in Example 2
So, we continue calling the function on the left and right roots, and return the side which isn't a nullptr, or the root itself if both sides aren't nullptr
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == nullptr) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q); //root->left
        TreeNode* right = lowestCommonAncestor(root->right, p, q); // root->right
        // cout << left << " " << root->val << " " << right << endl;
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }
};