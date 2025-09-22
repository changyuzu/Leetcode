/*
This problem is quite clearly a monotonic stack problem, so that's my first attempt
We initialize our answer vector ans with the same size as temperatures, with all 0 values, as well as a stack in which we keep the index of each element
Then we start checking from the back
While the stack isn't empty and the top temperature is smaller or equal to the current temperature, we pop from the stack
We exit the for loop either when the stack is empty, or the temperature at the top of the stack is greater than our current temperature
If the stack is empty, no warmer temperature can be found, so the answer remains 0
But if there's any remaining element in the stack, that's the index of the warmer element, so the answer will be the distance between the topmost element and the current element
When that's done, we push the index of the current element to the stack
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans (n, 0);
        for (int i=n-1; i>=0; i--)
        {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) st.pop();
            if (!st.empty()) ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};