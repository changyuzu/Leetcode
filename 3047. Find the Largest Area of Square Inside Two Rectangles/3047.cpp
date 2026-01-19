/*
This problem can be solved by simply keeping track of the intersections between two rectangles
To do this, we can fix one rectangle and check it against the next rectangles in the list
We can start by checking whether any intersection exists between the two rectangles
If there is no intersection, then move onto the next rectangle
Otherwise, we check the intersecting sides of the current rectangle
The area of the intersection can be obtained through the intersection along the x-axis and the y-axis
Since the intersection can only be a square, the answer must be the shorter of the two
Once we have the shorter side, we compare it against the longest side of the intersection we've seen thus far
I only keep track of the longest side instead of the largest area, so we don't need to keep track of large numbers
Once we've checked all the rectangles, return the longest side multiplied with itself, casted into long long
*/

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int ans = 0;
        const int n = bottomLeft.size();
        for (int i=0; i<n-1; i++)
        {
            const int topX = topRight[i][0], topY = topRight[i][1], botX = bottomLeft[i][0], botY = bottomLeft[i][1];
            for (int j=i+1; j<n; j++)
            {
                if (topX <= bottomLeft[j][0] || topY <= bottomLeft[j][1] || botX >= topRight[j][0] || botY >= topRight[j][1]) continue;
                const int ctopX = topRight[j][0], ctopY = topRight[j][1], cbotX = bottomLeft[j][0], cbotY = bottomLeft[j][1];
                const int xint = min(topX, ctopX) - max(botX, cbotX);
                const int yint = min(topY, ctopY) - max(botY, cbotY);
                // cout << topX << " " << topY << " " << botX << " " << botY << " | " << ctopX << " " << ctopY << " " << cbotX << " " << cbotY << endl;
                // const int side = min(xint, yint);
                // cout << i << " " << j << " " << xint << " " << yint << endl;
                ans = max(ans, min(xint, yint));
            }
        }
        return (long long) ans * ans;
    }
};