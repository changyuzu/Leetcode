/*
For this problem, we can make use of the properties of prefix sum and hash maps
Remember the property of prefix sum: sum[i,j] = sum[0,j] - sum[0,i] where sum[x,y] represents the sum of all elements from index x to index y
So we know that for a subarray from index [0,j] with sum x, if there exists a subarray [0,i] with sum (x - k), then the sum of the subarray in the index [i,j] has sum k
Since we don't actually care about the indexes of the subarray for our answer, we can just store the frequency of the sums in a hash map, which I named sum_freq in the code
The hash map key refers to the sum, while the value is how many times we've seen that sum appear
Remember to put sum_freq[0] = 1, because we can get sum 0 by not selecting any elements
Declare another variable to keep track of the sum of all elements up to the current index (I named the variable `sum` in the code)
Then, for all elements num in nums:
- Add num to sum
- If we could find (sum - k) in the keys of sub_freq, we have at least 1 subarray which can form sum, so add sum_freq to our answer counter
- Increment sum_freq[sum]
Once we've finished iterating over all the elements, return ans
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int, int> sum_freq;
        sum_freq[0] = 1;
        for (int &num: nums)
        {
            sum += num;
            if (sum_freq.find(sum - k) != sum_freq.end()) ans += sum_freq[sum - k];
            sum_freq[sum]++;
        }
        return ans;
    }
};