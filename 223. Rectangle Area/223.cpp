/*
This problem can be solved by checking for intersections and calculating the area accordingly
Know that when the rectangles overlap, we only count the overlapping section once
So, check whether there is any overlap between the rectangles
If yes, when we calculate the total area from both rectangles, we need to subtract the overlapping area
If not, return the sum of the two rectangles' area
*/

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        const int area1 = (ax2 - ax1) * (ay2 - ay1), area2 = (bx2 - bx1) * (by2 - by1), right = min(bx2, ax2), left = max(bx1, ax1), top = min(by2, ay2), bot = max(by1, ay1);
        if (right <= left || top <= bot) return area1 + area2;
        return area1 + area2 - ((right - left) * (top - bot));
    }
};