/*
This problem can be solved by sorting the intervals by their endpoint, and checking the beginning of each interval against the previous non-overlapping interval's endpoint
We sort by the endpoint because we want to minimize the number of intervals that we remove
To do that, we need to ensure that each endpoint needs to end as early as possible before the next interval starts
So, if the current interval's starting point overlaps with the previous valid interval's endpoint, we need to remove it, and increment our answer
Otherwise, we update the valid interval's endpoint with the current interval's
Once we've checked all intervals, return our answer
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (auto &a, auto &b) {
            return a[1] < b[1];
        });
        // for (auto &a: intervals) cout << a[0] << " " << a[1] << endl;
        const int n = intervals.size();
        int curr = intervals[0][1], ans = 0;
        for (int i=1; i<n; i++)
        {
            if (intervals[i][0] < curr) ans++;
            else curr = intervals[i][1];
        }
        return ans;
    }
};