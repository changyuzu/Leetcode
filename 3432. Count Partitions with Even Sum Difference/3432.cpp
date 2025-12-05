/*
This problem can be solved by simply keeping track of the parity of the sum of all numbers in nums
If the sum is even, all partitions will have even differences
- If one side of the partition is even, the other will definitely be even too
	- Then, for any n and m, 2n - 2m will definitely be even
		- n = 1, m = 2	-> 2n - 2m = 2 - 4 = -2
		- n = 4, m = 2	-> 2n - 2m = 8 - 4 = 4
		- n = 5, m = 3	-> 2n - 2m = 10 - 6 = 4
- If one side of the partition is odd, the other will definitely be odd too
	- (2n + 1) + (2m + 1) = 2n + 2m + 2
	- Then, for any n and m, (2n + 1) - (2m + 1) will definintely be even
		(2n + 1) - (2m + 1) = 2n - 2m + 1 - 1 = 2n - 2m -> proven in the previous section
So, we simply need to ensure that the total sum of all numbers in nums is even, in which case all partitions are valid, and we just need to return the size of nums - 1
If the sum of all numbers is odd, then there is no valid partition, and we return 0
Since we don't need the actual sum, just the parity, I just used a boolean variable and XOR-ed it with the result of (nums[i] & 1), which checks whether nums[i] is odd
*/

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        bool even = true;
        for (int &num: nums) even ^= (num & 1);
        return even ? nums.size() - 1 : 0;
    }
};