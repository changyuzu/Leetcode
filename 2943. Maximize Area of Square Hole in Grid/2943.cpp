/*
This problem can be solved by keeping track of the longest line that can be obtained by removing bars, both horizontally and vertically
We can get those two values separately, using the same approach
Start by sorting the hBars and vBars vectors
Then, we start checking the longest undivided line
I used this by keeping track of starting and ending points
Initialize the starting point at 1 and ending point at 2, since it's possible that the first bar can't be removed
Then, we start checking all the removable bars in vBars and hBars
- If the removable bar is the same as our ending point, then we can extend the end point
- If the removable isn't the same as the original ending point, we can't extend the current line
	Check the length of the current line against the longest line we've seen so far
		Length of the current line = ending point - starting point
	Then we set a new starting point, which is the bar before the current removable bar
For both cases, we will set the ending point as the bar after the current one
Once we've gone through all the removable bar, do one last check for the last ending and starting point
	It's possible that the longest line ends at the last bar
Repeat the same thing on the other vector, and we should have the longest line vertically and horizontally
Since the hole needs to be a square, we can only take the shorter one of the two
Return the area of the square, which is just multiplying the shorter side with itself
*/

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int maxH = 1, maxV = 1, start = 1, last = 2;
        for (auto &h: hBars)
        {
            if (h != last)
            {
                maxH = max(maxH, last - start);
                start = h-1;
            }
            last = h+1;
            // cout << h << " " << start << " " << last << " " << maxH << endl;
        }
        // cout << last << " " << start << endl;
        maxH = max(maxH, last - start);
        start = 1, last = 2;
        for (auto &v: vBars)
        {
            if (v != last)
            {
                maxV = max(maxV, last - start);
                start = v-1;
            }
            last = v+1;
            // cout << v << " " << start << " " << last << " " << maxH << endl;
        }
        // cout << last << " " << start << endl;
        maxV = max(maxV, last - start);
        // cout << maxV << " " << maxH << endl;
        int side = min(maxV, maxH);
        return side * side;
    }
};