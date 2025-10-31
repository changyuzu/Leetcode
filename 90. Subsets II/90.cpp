/*
This problem is similar to 78. Subsets
The solution set still  must not contain duplicate subsets, but the vector `nums` may contain duplicates
We can still apply the same concept to avoid duplicate subsets by calling the backtracking function on index i+1
But we also need to avoid calling the function on the same value
To do this, we can sort the nums vector
Then, every time we finish the backtracking iteration for a certain value, we move the index i 1 step forward
Then, while nums[i-1] == nums[i], we keep moving i forward
This allows us to avoid calling the backtracking function on the same values, which would result in duplicate subsets
*/

class Solution {
public:
    void backtrack(vector<int> &nums, vector<int> &row, vector<vector<int>> &ans, int idx, int &n)
    {
        ans.push_back(row);
        int i=idx+1;
        while (i < n)
        {
            row.push_back(nums[i]);
            backtrack(nums, row, ans, i, n);
            row.pop_back();
            i++;
            while (i < n && nums[i-1] == nums[i]) i++;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> row;
        vector<vector<int>> ans;
        ans.push_back(row);
        int n = nums.size(), i = 0;
        while (i < n)
        {
            row.push_back(nums[i]);
            backtrack(nums, row, ans, i, n); // index i
            i++;
            row.pop_back();
            while (i < n && nums[i-1] == nums[i]) i++; // prevent backtracking on the same value
        }
        return ans;
    }
};