/*
This problem can be solved by simply counting the number of elements that aren't divisible by 3
We can clearly see that for numbers non-divisible by 3, simply adding or subtracting 1 once will make them divisible by 3
Quick proof:
- If (n % 3 == 1) -> subtract 1, so it becomes ((n-1) % 3 == 0)
- If (n % 3 == 2) -> add 1, so it becomes ((n+1) % 3 == 3), which is the same as ((n+1) % 3 == 0)
In case we change 3 to any other number k, we can count the minimum number of operations with the following formula:
	numOps = min(num % k, num - (num % k))
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int &num: nums) if (num % 3 != 0) ans++;
        return ans;
    }
};