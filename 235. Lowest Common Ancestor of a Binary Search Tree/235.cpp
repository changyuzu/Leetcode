/*
This problem is similar to 236. Lowest Common Ancestor of a Binary Tree
But we can utilize the property of a binary search tree, which ensures that all elements on the left side of a node is smaller than the node itself, while all elements on the right side of a node is larger
So, we can simply choose whether to go to the left or right of any given node
Start by getting the minimum and maximum of p and q for the minVal and maxVal
Then, we check our root:
- If root->val is larger than maxVal, only the left side can possibly be our answer, so just go left
- If root->val is smaller than minVal, only the right side can possibly be our answer, so just go right
- Otherwise, we've found a node within the bounds of p and q, which is our answer
I wrote 2 different versions, one with a separately defined dfs function, and another one with a while loop declared inside the main function directly
The performance doesn't differ much, so I just left both in the code
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
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q, int &minVal, int &maxVal)
    {
        if (root == p || root == q || root == nullptr) return root;
        if (root->val > maxVal) return dfs(root->left, p, q, minVal, maxVal);
        if (root->val < minVal) return dfs(root->right, p, q, minVal, maxVal);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minVal = min(p->val, q->val), maxVal = max(p->val, q->val);
        // while (root != nullptr)
        // {
        //     if (root == p || root == q) return root;
        //     if (root->val > maxVal) root = root->left;
        //     else if (root->val < minVal) root = root->right;
        //     else return root;
        // }
        // return nullptr;
        return dfs(root, p, q, minVal, maxVal);
    }
};