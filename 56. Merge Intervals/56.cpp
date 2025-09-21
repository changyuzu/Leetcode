/*
For this problem, we check each interval to see if they overlap with any other interval, and merge those intervals if they overlap
To do this more easily, we start by sorting the vector in non-decreasing order
Assign one vector called curr for the current interval
Then, starting from the next interval, we check whether the start of the next interval is larger than the current interval
If yes, we know that the next interval doesn't overlap with the current interval, so we push curr to our answer vector, and assign the next interval as curr
Otherwise, there's an overlap, so we update the end of the current interval with whichever is greater between the current and next interval's end
After we've finished checking all intervals, remember to push curr into the answer vector
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> curr = intervals[0];
        for (int i=1; i<intervals.size(); i++)
        {
            if (intervals[i][0] > curr[1])
            {
                ans.push_back(curr);
                curr = intervals[i];
            }
            else curr[1] = max(curr[1], intervals[i][1]);
        }
        ans.push_back(curr);
        return ans;
    }
};