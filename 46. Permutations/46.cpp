/*
This problem can be solved by backtracking
I first declared the backtracking function, which takes these parameters:
- The nums vector
- The row vector to store the current permutation
- The answer vector
- The visited vector to keep track of whether an element at a certain index has been added
- The length of the vector nums, which is also the length of our permutation
- The index of the element we're trying to add to the row
- The length of the current row
First off, if the length of the current row is already longer than n, or the current index has been visited, we simply return
Otherwise, the current index can be added to our row, so we push it to the back of the row and mark it as visited
Then, for all indexes of nums, we call the backtrack function again, this time with length len+1
By calling the function with len+1 and putting the condition of len > n at the beginning of the function, when the length goes beyond n, the function simply exits and doesn't try to add more elements
When we've finished that iteration, we pop from the back of the row, and mark the index as unvisited for the next iteration
Then, in the main body of the function, we simply call backtrack for all elements of the array, initialized with len = 1
Once we've finished checking all elements, simply return ans
*/

class Solution {
public:
    void backtrack(vector<int> &nums, vector<int> &row, vector<vector<int>> &ans, vector<bool> &visited, int &n, int idx, int len)
    {
        if (len > n || visited[idx]) return;
        visited[idx] = true;
        row.push_back(nums[idx]);
        if (len == n) ans.push_back(row);
        for (int i=0; i<n; i++) backtrack(nums, row, ans, visited, n, i, len+1);
        row.pop_back();
        visited[idx] = false;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> row;
        vector<vector<int>> ans;
        for (int i=0; i<n; i++) backtrack(nums, row, ans, visited, n, i, 1);
        return ans;
    }
};