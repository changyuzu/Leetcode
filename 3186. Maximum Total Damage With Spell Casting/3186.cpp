/*
This problem requires a hash table and dynamic programming
We start by counting the frequency of each spell power, and then store each unique power (map key) in a separate vector for easier access
Then we sort this key vector, so we can iterate through the spells more easily
Since we need to avoid using spells whose difference in power to the current spell is less than 2, sorting the key would make things much easier
Then we initialize our dp, with the same size as the number of keys
Declare dp[0] = keys[0] * hash[keys[0]], because we can't check the previous element for the very first element
Then, starting from index 1, we do the following:
- Check the total power from casting all spells with power equal to the current key
- Check whether any previous key has a difference in power greater than 2, compared to the current key
	- If yes, add the dp value for that previous key to the total power of the current key
- Check if casting this spell results in greater power than the previous element and update dp[i] accordingly
Once we've finished checking all elements, we have our answer as the last element of the dp
*/

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> hash;
        for (int &p: power) hash[p]++;
        vector<int> keys;
        for (auto &[key, _]: hash) keys.push_back(key);
        sort(keys.begin(), keys.end());
        int n = keys.size();
        long long dp[n];
        dp[0] = 1LL * keys[0] * hash[keys[0]];
        for (int i=1; i<n; i++)
        {
            long long curr = 1LL * hash[keys[i]] * keys[i];
            int prev = i-1;
            while (prev >= 0)
			{
				if (keys[prev] < (keys[i] - 2)) break;
				prev--;
			}
			if (prev >= 0) curr += dp[prev];
			dp[i] = max(dp[i-1], curr);
        }
        return dp[n-1];
    }
};
