/*
This problem is similar to 56. Merge Intervals, but we have a target interval that needs to be inserted
The vector `intervals` is already sorted, so we don't need to sort them this time and can go straight into checking for overlaps
We use a boolean variable named `added` to keep track of whether we've added newInterval to the answer vector `ans`
For each interval in the vector, which we will refer to as `curr`, we do the following:
- If the end point of curr is greater than the starting point of newInterval AND the starting point of curr is less than the end point of newInterval, there is an overlap and we update newInterval according to this logic:
	- newInterval start point: min of the starting point for curr and newInterval
	- newInterval end point: max of the end point for curr and newInterval
- Else if the end point of curr is less than the starting point of newInterval, curr is smaller than newInterval and has no overlap, so we simply push curr into the answer vector
- Else, curr is larger than newInterval
	- If we haven't added newInterval to ans, we push newInterval
	- Push curr to the answer interval
Once we've checked all elements of intervals, we check one last time if we've added newInterval, and add it if we haven't
Then we can return ans
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool added = false;
        for (vector<int> &curr: intervals)
        {
            if (curr[1] >= newInterval[0] && curr[0] <= newInterval[1])
            {
                newInterval[0] = min(curr[0], newInterval[0]);
                newInterval[1] = max(curr[1], newInterval[1]);
            }
            else if (curr[1] < newInterval[0]) ans.push_back(curr);
            else
            {
                if (!added)
                {
                    ans.push_back(newInterval);
                    added = true;
                }
                ans.push_back(curr);
            }
        }
        if (!added) ans.push_back(newInterval);
        return ans;
    }
};