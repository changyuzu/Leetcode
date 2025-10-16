/*
This problem can be solved using hash table
To save memory, I used a vector of size (value + 1) instead of an unordered_map
But first, let's look at some important test cases, since the examples provided in the problem don't really explain the requirements well:
nums = [3,0,3,2,4,2,1,1,0,4], value = 5 -> Expected: 10
nums = [0,0,0,0,1,0,0,1,0,0,1,1,0,1,0,1,1], value = 2 -> Expected: 15
The problem wants us to get the MAXIMUM SMALLEST MISSING NON-NEGATIVE INTEGER after adding or subtracting value from elements of nums
We can start by breaking down the problem into 2 parts:
- Find the smallest missing non-negative integer, or MEX
- Maximize the MEX
Starting from the first subproblem, we can see that to get MEX with regard to the given `value`, we can start by finding the smallest positive integer we can achieve using each element `num` of `nums`
Why? Let's say we have nums = [5,6,7], value = 5
If we subtract 5 from each element, we get nums = [0,1,2]
It's apparent that the answer is 3, and this is the maximum MEX we can get, because if we keep subtracting 5 from the elements of nums, or we add 5 to the elements of nums, MEX will become 0
So to get MEX, we need to replace each element of nums with the result of that element mod value, i.e. nums[i] = nums[i] % value
But this only applies when all elements in nums are UNIQUE
If there are duplicates, we can actually add value to the element
Let's look at this example:
nums = 		[3,0,3,2,4,2,1,1,0,4], value = 5
updated =	[3,0,8,2,4,7,1,6,5,9]
With that, we can see that MEX is now 10
Now look at this example:
nums = 		[0,0,0,0,1,0,0,1], value = 2
updated =	[0,2,4,6,1,8,10,3]
With this, we can see that the MEX is now 5
So how do we do on this? We check the frequency of each value of nums[i] % value and store it in our hash table
Then, starting from index 0 (frequency of nums[i] % value == 0), we check for the element with the minimum frequency
Using the example [0,0,0,0,1,0,0,1], value = 2, it should be clear that the answer will be related to the element with the least frequency
So how do we get our answer? We simply need to get the frequency of that element, multiply it with value, and add that element to the result
Using example [0,0,0,0,1,0,0,1], value = 2, the hash table would be like this:
hash = {{0,6}, {1,2}}
So our answer is obtained through the element with the lowest frequency, 1
The answer then becomes ans = (2 * value) + 1 = (2 * 2) + 1 = 5
*/

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size(), ans = 0;
        vector<int> hash(value+1, 0);
        for (int &num: nums)
        {
            if (num >= 0) num %= value;
            else num = (num % value) + value;
            hash[num]++;
        }
        hash[0] += hash[value];
        int freq = INT_MAX;
        for (int i=0; i<value; i++)
        {
            if (hash[i] >= freq) continue;
            freq = hash[i];
            ans = (value * freq) + i;
        }
        return ans;
    }
};