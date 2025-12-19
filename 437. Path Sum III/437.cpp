/*
This problem can be solved by utilizing the concept of prefix sum along each DFS path
So we keep a hash map to keep track of how many times a certain sum has appeared along the route
This is important because negative values are allowed, so subtraction can happen to make a value happen multiple times, and all instances would be valid for the prefix sum
Since at the very beginning, the prefix sum is 0, we initiate the hash map with value 1 for key 0
We also initiate our answer, integer 0, and the prefix sum (running sum), long int 0 because summing the values might cause overflow
Then, we start the DFS, for which I've declared a function
If root == nullptr, we simply return
Otherwise, we add the current root's value to our sum
Then, we apply the prefix sum:
- If we've encountered the value of (sum - targetSum) before, there are valid ways to get the targetSum from the current sum in the path
	- In this case, all instances of (sum - targetSum) are valid, and we add the number of instances to our answer
We increment the hash value for the current sum to mark that we've seen this value at this point
Then, we call the DFS function again on the left and right nodes using the current sum
To avoid affecting the routes of different branches, we need to decrement the hash value and subtract the current root's value after we've finished checking its left and right nodes
Once we've finished the DFS on all nodes, we just return the answer
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
    void dfs(TreeNode* root, int &targetSum, unordered_map<long, int> &check, int &ans, long &sum)
    {
        if (root == nullptr) return;
        int curr = root->val;
        sum += curr;
        if (check.find(sum - targetSum) != check.end()) ans += check[sum - targetSum];
        check[sum]++;
        dfs(root->left, targetSum, check, ans, sum);
        dfs(root->right, targetSum, check, ans, sum);
        check[sum]--;
        sum -= curr;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> check;
        check[0] = 1;
        int ans = 0;
        long sum = 0;
        dfs(root, targetSum, check, ans, sum);
        return ans;
    }
};