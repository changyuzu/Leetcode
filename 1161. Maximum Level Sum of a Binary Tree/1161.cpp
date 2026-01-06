/*
This problem can be solved by performing BFS, counting the sum of the nodes at each level, and comparing against the largest sum seen so far
To do this, we need to keep track of 3 things:
- ans: The level with the largest sum seen thus far, initialized to 0
- level: The current level, initialized to 0
- sum: The largest sum seen thus far, initialized to INT_MIN
We use a queue to keep track of the nodes at the current level, and push the non-null nodes of the next level as we iterate through them
Increment the level as we go and count the sum of the current level starting from 0
If the total sum of this level is higher than `sum`, the largest sum seen thus far, we set the current sum as the new `sum` and update `ans` with the current level
Once we've finished going through all the levels, return our answer
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0, level = 0, sum = INT_MIN;
        while (!q.empty())
        {
            level++;
            int s = q.size(), currSum = 0;
            while (s--)
            {
                TreeNode* curr = q.front();
                q.pop();
                currSum += curr->val;
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
            if (currSum > sum)
            {
                sum = currSum;
                ans = level;
            }
            // cout << currSum << " " << sum << " " << level << " " << ans << endl;
        }
        return ans;
    }
};