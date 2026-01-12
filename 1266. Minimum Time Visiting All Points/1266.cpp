/*
This problem can be solved by simply adding the maximum of the x and y coordinate shifts in each operation
Know that the most efficient way of moving would be to maximize the diagonal shifts, then moving along the x or y axis the rest of the way
For example, if we're moving 10 steps along the x axis and 3 steps along the y axis, the most efficient way to move would be:
	Move 3 steps diagonally, then 7 steps the rest of the way along the x axis
If we switch the x and y axis, the most efficient way of moving would still be the same
So, for each i in the range [1..n] where n is the length of the points vector:
	- Check the steps that we're moving in the x axis, and the steps in the y axis
	- Add the max between those two to our answer
Once we've checked all elements in points, return the answer
*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i=1; i<points.size(); i++)
        {
            ans += max(abs(points[i][0] - points[i-1][0]), abs(points[i][1] - points[i-1][1]));
        }
        return ans;
    }
};