/*
This problem can be easily solved with backtracking
Basically, for each candidate, we keep appending to our holder vector (I named it row in the code) until we get to our target, or beyond it
If the holder sum is equal to our target, we append the row to our answer vector and return
If the holder sum is larger than our target, we simply return
Then the main backtracking function is a for loop starting from the index of our current element, appending to the row, entering the backtracking function, and popping back from the row as we go
Why do we need to make the for loop start from the index of the current element? The problem statement says we need to return a list of unique combinations
For the case of Example 1: candidates = [2,3,6,7], target = 7
The expected output is [[2,2,3],[7]]
Just looking at the expected output, we know that variations of [2,2,3], like [2,3,2] and [3,2,2] aren't allowed
The simplest way to prevent such variations from appearing is by ensuring that we never append elements from previous indexes of candidates
So when the holder vector row becomes [2,3], we can't append elements that appear before 3 in candidates, therefore [2,3,2] won't be added to our answer vector
When we've finished going through all the candidates, we exit the backtracking function and return the answer vector
*/

class Solution {
public:
    void backtrack(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &row, int sum, int idx)
    {
        if (sum == target)
        {
            ans.push_back(row);
            return;
        }
        if (sum > target) return;
        for (int i=idx; i<candidates.size(); i++)
        {
            row.push_back(candidates[i]);
            backtrack(candidates, target, ans, row, sum + candidates[i], i);
            row.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> row;
        backtrack(candidates, target, ans, row, 0, 0);
        return ans;
    }
};