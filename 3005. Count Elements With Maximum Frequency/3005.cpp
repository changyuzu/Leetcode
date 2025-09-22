/*
The wording for the problem statement is quite confusing, but basically, we need to count the total frequency of elements which have the maximum frequency
So basically, we need to know:
- What is the maximum frequency of elements in nums
- How many elements appear that many times
In the case of nums = [1,3,2,2,1,6,6]
- Max frequency = 2
- No. of elements that appear 2 times = 3 (1, 2, 6)
So we return 2 * 3 = 6 because we want the total frequency of elements which have the maximum frequency
We use a hash table to keep track of how many times any element has appeared, a variable maxC to keep track of the maximum frequency, and c to keep track of how many elements have the maximum frequency
If the frequency of the current element is greater than maxC, we update maxC with the current element and reset c to 1
Else if the frequency of the current element is equal to maxC, we increment c
We don't care about elements with lesser frequency, so that's all for the if conditions
Lastly, we return c * maxC to get the total frequency of elements with the maximum frequency

*/

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> hash;
        int maxC = 0, c = 0;
        for (int &num: nums)
        {
            hash[num]++;
            if (hash[num] > maxC)
            {
                maxC = hash[num];
                c = 1;
            }
            else if (hash[num] == maxC) c++;
        }
        return c * maxC;
    }
};
