/*
We're using two pointers for this problem
For any two left pointer and right pointer, we know that the maximum height of the water is the lower value of left/right, otherwise it will spill
In other words, height = min(height[l], height[r])
The length of the container will be the distance between the left and right pointer
In other words, len = r-l
Area formula: area = len * height
We keep track of the maximum area that we encounter every time we move any of the pointers
We move the pointer inwards for any lower value
In other words, if the height at the left pointer is lower than the height at the right pointer, we move the left pointer to the right
Conversely, if the height at the right pointer is lower than the left pointer, we move the right pointer to the left
Lastly, we return the maximum area that we encounter
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, l = 0, r = height.size()-1;
        while (l < r)
        {
            int h = min(height[l], height[r]);
            maxArea = max(maxArea, h * (r-l));
            if (height[l] > height[r]) r--;
            else l++;
        }
        return maxArea;
    }
};