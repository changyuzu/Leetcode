/*
This problem can be solved using backtracking
One key point that needs to be kept in mind is, the solution must not contain duplicate subsets
From the examples, [1,2] and [2,1] are considered the same subset
This actually makes things easier for us, because now we can simply apply the backtracking on indexes after the current index
In other words, for the iteration of index i, we only need to call the backtracking function starting from elements at index i+1
This way, we don't need to check for duplicates since all elements of the original nums vector are guaranteed to be unique
*/

class Solution {
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &ans, vector<int> &row, int idx, int &n)
    {
        row.push_back(nums[idx]);
        ans.push_back(row);        
        for (int i=idx+1; i<n; i++)
        {
            backtrack(nums, ans, row, i, n);
        }
        row.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> row;
        vector<vector<int>> ans;
        ans.push_back({});
        for (int i=0; i<n; i++) backtrack(nums, ans, row, i, n);
        return ans;
    }
};