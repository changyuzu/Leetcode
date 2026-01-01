/*
This problem can be solved using DFS
Basically, for each node, we check whether the depth of its left and right subtree have a difference of at most 1
To do this more efficiently, we can start our check from the leaf nodes, which would have 0 depth, and move up
I've defined a function called depth, which checks the depth of the current node's subtrees AND the difference between the current node's left and right subtrees
The function will return -1 if the difference between the left and right subtree is larger than 1
Since we need to keep track of whether the lower levels had non-balanced subtrees, we need to keep the value of -1 when we move upward
So the condition becomes, the function will return -1 if the left or right subtree had returned -1, or if the current left and right subtree's difference is greater than 1
Otherwise, we will return the maximum depth of the current node's subtree, which is max(left, right) + 1 (because we need to count the current node too)
Once we've checked all nodes, we just need to return whether the result of the check is -1 or not
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
    int depth(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int left = depth(root->left), right = depth(root->right);
        if (left == -1 || right == -1 || left - right > 1 || left - right < -1) return -1;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        return (depth(root) != -1);
    }
};