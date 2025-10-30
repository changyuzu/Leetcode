/*
This problem is classified as hard, but it's actually quite simple
The hint mentioned Range minimum query and Segment trees, but you don't need those
You just need to keep in mind that when you're checking values in the same subarray, the number of increments required is simply the maximum value in that group
How to we define the subarrays? We can define them as "mountains"
Each dip separates the subarrays, and for each subarray, we need to increment as many times as the highest value in that subarray
So, we can implement a one-pass algorithm:
- If the current array value is larger than the previous value, we need to increment more than the previous value, so add the difference between the two values
- Otherwise, the previous increment operation covers the current value
Once we've checked all values, return our answer
*/

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size(), ans = target[0];
        for (int i=1; i<n; i++) if (target[i] > target[i-1]) ans += target[i] - target[i-1];
        return ans;
    }
};