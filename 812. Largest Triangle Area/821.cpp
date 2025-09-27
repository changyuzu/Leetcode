/*
This problem is basically solved with brute-force
We know that for 3 given points (x1, y1), (x2, y2), and (x3, y3), we can get the coordinates with the Shoelace formula:
	A = 0.5 * | x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) |
I defined a function that calculates the area, taking parameters from 3 points from the vector points, and updates the maxArea with each calculation
Use 3 for loops to get 3 different points in each iteration
*/

class Solution {
public:
    double area(vector<int> &p1, vector<int> &p2, vector<int> &p3)
    {
        return 0.5 * abs((p1[0] * (p2[1] - p3[1])) + (p2[0] * (p3[1] - p1[1])) + (p3[0] * (p1[1] - p2[1])));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
        int n = points.size();
        for (int i=0; i<n-2; i++)
        {
            for (int j=i+1; j<n-1; j++)
            {
                for (int k=j+1; k<n; k++)
                {
                    maxArea = max(maxArea, area(points[i], points[j], points[k]));
                }
            }
        }
        return maxArea;
    }
};