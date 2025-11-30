/*
For this problem, we can utilize the property of a Binary Search Tree:
All nodes on the left side of a node are guaranteed to be strictly smaller, and all nodes on the right side of a node are guaranteed to be strictly larger
In other words, the inorder traversal of a BST is always sorted
So, we can simply do an inorder traversal of the BST, while keeping count of the number of nodes we've seen along the way
Once we've reached k, set our answer to the current node's value and stop traversing, then return the answer
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
    void inorder(TreeNode* root, int &count, int &ans, int &k)
    {
        if (root == nullptr || count >= k) return;
        inorder(root->left, count, ans, k);
        count++;
        if (count == k) ans = root->val;
        inorder(root->right, count, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0, ans = -1;
        inorder(root, count, ans, k);
        return ans;
    }
};