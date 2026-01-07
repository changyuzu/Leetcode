/*
This problem can be solved by keeping track of the sum of each subtree and comparing against the total sum to maximize the product
I defined a DFS function called subtreeSum, which calculates the sum of a subtree that starts at a given node
The sum of a node's subtree is given by (sum of its left node's subtree) + (sum of its right node's subtree) + (value of the node)
To get the sum of all the nodes, we just check the sum of the root node's subtree, which is the tree in its entirety
We can store this answer as our totalSum
Now that we have the totalSum, we can calculate the product from taking away a subtree
If we split a subtree with subtree sum n, then the product of this subtree and the rest of the original tree would be (sum - n) * n
To get the subtree's sum, I used two different approaches:
- Perform the DFS twice (no extra space, first code snippet)
- Store the sum we already calculated in a vector (requires extra space, second code snippet)
I put both approaches below, both versions can get 0ms runtime
Remember that we need to maximize the answer before taking the mod, so we store the answer as a long long
Update the answer as we check each subtree sum against the totalSum, and return the answer mod 1e9 + 7 when we're done
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
    int subtreeSum(TreeNode* root, int &totalSum, long long &ans)
    {
        if (root == nullptr) return 0;
        int sum = subtreeSum(root->left, totalSum, ans) + subtreeSum(root->right, totalSum, ans) + root->val;
        if (totalSum != INT_MIN) ans = max(ans, (long long) (totalSum - sum) * sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        const int MOD = 1e9 + 7;
        int sum = INT_MIN;
        long long ans = LLONG_MIN;
        sum = subtreeSum(root, sum, ans);
        subtreeSum(root, sum, ans);
        return ans % MOD;
    }
};

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
    int subtreeSum(TreeNode* root, vector<int> &sums)
    {
        if (root == nullptr) return 0;
        int sum = subtreeSum(root->left, sums) + subtreeSum(root->right, sums) + root->val;
        sums.push_back(sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        const int MOD = 1e9 + 7;
        vector<int> sums;
        int sum = subtreeSum(root, sums);
        long long ans = LLONG_MIN;
        for (auto &n: sums) ans = max(ans, (long long) (sum - n) * n);
        return ans % MOD;
    }
};