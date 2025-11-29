/*
This problem can be solved by simply keeping track of the mod k values at each step along the way
The "operation" mentioned in the problem statement is just decrementing any element in nums
So, to get the minimum number of operations to make the sum of the array divisible by k, we just need to know the value of sum % k
Notice that we don't need to know the actual value of the sum, so we can simply keep track of the mod k values
We can cast these values directy to our answer, which we initialize to 0
Then, for each num in nums, we update ans with the formula ans = (ans + num) % k
This only keeps track of the mod k value of the sum up to the current element
Once we've checked all elements, return ans
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for (int &num: nums) ans = (ans + num) % k;
        return ans;
    }
};