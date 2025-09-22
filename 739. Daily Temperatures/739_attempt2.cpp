/*
My second attempt is something of a dynamic programming approach
With this approach, we don't need to use separate memory for a stack
We still initialize our ans vector with the same size as temperatures and all 0 values
Then we start iterating from the second to last value, because the rightmost value definitely doesn't have a warmer temperature, and will always be 0
The logic goes like this:
- If the next element is warmer than the current element, we return the distance between the next element and the current element
- Else if the next element is cooler than the current element, and the answer for the next element isn't 0, there definitely exists a warmer element for the next element, which may or may not be warmer than our current element
	- We know that all elements between the next element and its warmer element is cooler, so we don't care about those
	- We can skip straight to the warmer element of the next element
	- Repeat until we either reach the end of the vector, or we find a warmer element, or we reach an element with answer 0
- Else if the next element is cooler than the current element, and the answer for the next element is 0, there is no warmer element for both the next element and our current element, so the answer remains 0
Once we've finished going through all elements, we simply return ans
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans (n, 0);
        for (int i=n-2; i>=0; i--)
        {
            int next = i+1;
            while (next < n && temperatures[next] <= temperatures[i])
            {
                if (ans[next] == 0) break;
                next += ans[next];
            }
            if (next < n && temperatures[next] > temperatures[i]) ans[i] = next - i;
        }
        return ans;
    }
};