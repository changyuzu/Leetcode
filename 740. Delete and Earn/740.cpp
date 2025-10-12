/*
For this problem, we use dynamic programming and hash table
Basically we need to decide which elements we need to take, since we can't take elements with adjacent values (nums[i] = nums[i+1] - 1 or nums[i+1] + 1)
Start by counting the frequency of each element of nums using the hash table
Then get the unique keys into a separate vector and sort it
Sorting the keys makes it easier to keep track of which elements to take, since this allows us to only check the previous element
Next, we initialize a dp array of size (n+1), with index 0 initialized to 0, and index 1 initialized to key[0] * freq of key[0]
Then we start checking from index i = 1 (based on the index of key, instead of dp):
- Check the points you get by taking the current key: keys[i] * freq of keys[i]
- Check whether the previous element is smaller than nums[i] - 1
	- If yes, take the previous element
	- If not, take the element before it, since the difference only needs to be greater than 1
- Update dp[i+1] with whichever is greater, dp[i] or the sum of taking the current key and the dp value of the previous element
Once we've checked all elements, the answer will be dp[n], where n is the number of unique keys in nums
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int &n: nums) hash[n]++;
        vector<int> keys;
        for (auto &[key, _]: hash) keys.push_back(key);
        sort(keys.begin(), keys.end());
        int n = keys.size();
        int dp[n+1];
        dp[0] = 0; dp[1] = keys[0] * hash[keys[0]];
        for (int i=1; i<n; i++)
        {
            int curr = keys[i] * hash[keys[i]];
            int prev = (keys[i-1] < keys[i] - 1) ? i-1 : i-2;
            dp[i+1] = max(curr + dp[prev+1], dp[i]);
        }
        return dp[n];
    }
};