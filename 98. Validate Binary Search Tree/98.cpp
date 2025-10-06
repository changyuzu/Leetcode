/*
For this problem, we need to check all nodes to ensure that it is strictly less than nodes on its right AND strictly greater than nodes on its left
This comparison applies to each node's child node, parent node, and *any ancestor nodes*
For this reason, we need to keep updating the MIN and MAX values as we go deeper in our tree nodes
Note that the possible node value includes the INT_MAX and INT_MIN values, so we can't use INT_MAX and INT_MIN for our default range assignment

I first declared our answer variable, which defaults to true
I defined a helper function called check, which checks if our root value is strictly greater than the min value AND strictly less than the max value
If not, simply return false
If our answer is still true and the left pointer isn't a nullptr, we check the left node and update ans with the AND operator
If our answer is still true and the right pointer isn't a nullptr, we check the right node and update ans with the AND operator
Any time our answer becomes false, we stop checking further
When we've finished checking all nodes, we return ans
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
    bool check(TreeNode* root, long min, long max, bool &ans)
    {
        // cout << root->val << " " << min << " " << max << endl;
        if (root->val <= min || root->val >= max) return false;
        if (ans && root->left != nullptr) ans &= check(root->left, min, root->val, ans);
        if (ans && root->right != nullptr) ans &= check(root->right, root->val, max, ans);
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        return check(root, LONG_MIN, LONG_MAX, ans);
    }
};