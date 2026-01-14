/*
Since this problem is the same as 865. Smallest Subtree with all the Deepest Nodes, I just reused the same approach
I performed DFS while keeping track of the depth of nodes
To do this, I defined a DFS function called check, which returns a pair of TreeNode* and int, where the int is the depth
So, when we reach nullptr, we return -1
Otherwise, we call the check function on the current node's left and right nodes, casting the results into two separate pairs
If both the left and right nodes are nullptrs, the current node is a leaf node, so we return the current node and its depth
Otherwise, we compare the maximum depth of the left and right nodes
If the depth is equal on both sides, return the current node and the depth of the left/right nodes, to mark that the current node is the LCA of the deepest nodes seen so far
If the left side is deeper than the right, return the left node and its depth, as the left node is deeper
Otherwise, return the right node and its depth
Once we've finished the DFS function on all nodes, just return the TreeNode from the function call
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
        else if (dl > dr) return {left, dl};
        else return {right, dr};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // auto [ans, _] = check(root, 0);
        return check(root, 0).first;
    }
};