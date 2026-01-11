/*
This problem can be solved using monotonic stack
We keep track of the histogram heights in a strictly increasing monotonic stack so we can calculate rectangles that span multiple bars in one go
The idea behind this approach is, the rectangle of height n can be extended across a longer length as long as the next bar is taller than height n
So, before we push the index of the current bar, we check the elements in the stack to ensure that the previous elements are strictly smaller
If the previous elements aren't strictly smaller, we start checking the area of the rectangles that can be formed with those elements
Starting from the topmost element, the height of the rectangle will be the height of the topmost element
Then, we pop from the stack, and the length of our rectangle will be the distance between the current index and the new topmost element - 1
We need to pop from the stack, because the length of the rectangle is defined from how long a rectangle of this height can be extended
So the length is where we encounter a shorter height
Once we've ensured that the topmost element of the stack is strictly smaller than the current element, we push the index to our stack
Once we've reached the end of our vector, we still need to check the remaining items in the stack
We still use the same concept, checking the topmost height with the length given by the index of the next smaller element
I pushed -1 into the stack in the very beginning so it's easier to calculate the index
Once we've popped all elements besides -1, return the largest area seen so far
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i=0; i<n; i++)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                int height = heights[st.top()];
                st.pop();
                int len = i - st.top() - 1;
                // cout << i << " " << height << " " << len << endl;
                ans = max(ans, height * len);
            }
            st.push(i);
        }
        while (st.top() != -1)
        {
            int height = heights[st.top()];
            st.pop();
            int len = n - st.top() - 1;
            // cout << height << " " << len << endl;
            ans = max(ans, height * len);
        }
        return ans;
    }
};