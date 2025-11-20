/*
The question isn't worded that well, but basically, we need to create a set, in which all intervals have at least two integers in the set, while minimizing the number of elements in the set
We can achieve this by finding the intervals with the most overlaps, since we need to reuse the elements as much as possible
To achieve this more simply, we can start by sorting the intervals in a way that makes checking for overlaps easier
There must be a few different ways to achieve this, but for this solution, I chose to sort by the endpoint (ascending), then the start (descending)
Then we initialize our answer to 2 (since there must be at least 2 elements in the set), and two elements to keep track of the current interval
With the current sorting method, we don't actually need to keep track of the interval itself, we just need to ensure that the current interval can be a subset of the compared interval
For this, we initialize two pointers for the compared interval:
- right: The rightmost point of the interval, initialized to intervals[0][1]
- left: The rightmost allowed starting point for the next intervals to be a subset of this interval, initialized to right - 1
Declaring the left variable this way lets us quickly check the next intervals against the current interval
For all index i starting from 1, if intervals[i][0] <= left, it can be a subset of the current interval
We sorted the intervals with the endpoints ascending, so intervals[i][1] is always guaranteed to at least be equal to the current right variable
In case we encounter an interval which can't be a subset of the interval, we check if there's any overlap between the current interval and the compared interval
Do this with the condition (intervals[i][0] <= right)
If there is any overlap, we add 1 to our answer, otherwise add 2
	- I simplified this by casting (intervals[i][0] <= right) into an int, and putting ans += 2 - overlap
Then, we need to update the compared interval
- If there is any overlap, we set the left pointer to right (to catch other intervals that can be contained with that overlap), otherwise we put it as intervals[i][1] - 1
- right will always be intervals[i][1]
Once we've checked all intervals, return ans
*/

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (vector<int> &a, vector<int> &b)
        {
            return (a[1] == b[1]) ? a[0] > b[0] : a[1] < b[1];
        });
        // for (vector<int> &i: intervals) cout << i[0] << " " << i[1] << endl;
        int ans = 2, right = intervals[0][1], left = right - 1;
        for (int i=1; i<intervals.size(); i++)
        {
            if (intervals[i][0] <= left) continue;
            int overlap = (intervals[i][0] <= right), r = intervals[i][1];
            ans += 2 - overlap;
            left = (overlap) ? right : r-1;
            right = r;
        }
        return ans;
    }
};