/*
This problem can be solved through DFS / backtracking
While we go through each node in the DFS, we need to keep track of the current sum
When we encounter a leaf node (a node for which its left and right pointers are nullptr), check if the sum up to the current node is equal to targetSum
If yes, push the current path to our answer
While the current node still has child nodes, push the current root into the path and continue the DFS with its left and right pointers
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
    void dfs(TreeNode* root, int &targetSum, vector<int> &path, vector<vector<int>> &ans, int &sum)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            // cout << sum << " " << root->val << endl;
            if (sum + root->val == targetSum)
            {
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        sum += root->val;
        if (root->left != nullptr) dfs(root->left, targetSum, path, ans, sum);
        if (root->right != nullptr) dfs(root->right, targetSum, path, ans, sum);
        sum -= root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        dfs(root, targetSum, path, ans, sum);
        return ans;
    }
};