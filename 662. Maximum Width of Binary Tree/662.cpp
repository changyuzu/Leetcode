/*
For this question, we do a breadth-first search to check each level before moving on to the next, and updating our answer if we encounter a higher value in any level
If root is a nullptr, we know that we can simply return 0
Otherwise, we start the BFS
We use a queue of pairs, where each pair is a TreeNode and its index in that level
Push the root into the queue, then while the queue isn't empty, we do the following:
- Check the index of the first and the last element, if the distance between the last index and the first index is greater than our answer, it becomes our new answer
- If its left / right pointers aren't NULL, we push into the queue, with the index defined as idx*2 + 1 for left and idx*2 + 2 for right
Note that for the indices, we can simply start over from 0 each time, since we don't actually care about it's true index, so we first define idx as the value stored in the queue - the index of the first element of the queue
If we visualize a tree using only its indices, it would be something like:
Original (Notice that indices 3 and 5 are missing, but still counted in the indexing):
  0
 / \
1   2
 \   \
  4   6
As we iterate through the levels, we can turn it into:
  0
 / \
0   1
 \   \
  0   2
This prevents the index turning into a very large number, which could happen if the tree has many layers
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode*, long long>> q;
        long long ans = 1;
        q.push({root, 0});
        while (!q.empty())
        {
            long long s = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            ans = max(ans, end - start + 1);
            for (int i=0; i<s; i++)
            {
                pair<TreeNode*, int> p = q.front();
                q.pop();
                long long idx = p.second - start;
                if (p.first->left != nullptr) q.push({p.first->left, idx*2 + 1});
                if (p.first->right != nullptr) q.push({p.first->right, idx*2 + 2});
            }
        }
        return ans;
    }
};