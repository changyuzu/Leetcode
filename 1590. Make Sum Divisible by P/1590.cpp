/*
This problem can be solved using prefix sum and hash table
First, we check whether the original sum of the vector is divisible by p
We can do this by simply keeping track of the mod value as we go, since we don't need the actual sum
Start with mod = 0
For each int num in nums, mod = (mod + num) % p
Only keeping track of the mod allows us to avoid overflow, since the sum can get very large
If the total mod is 0, the sum of the vector is already divisible by p, so we don't need to remove any subarrays and return 0
Otherwise, we need to find whether it's possible to remove any subarray to the sum divisible by p
We use another prefix sum to keep track of the current mod value, and a hash map to keep track of where we last saw each mod value
The key of the hash map will be the mod value, and the value of the hash map will be the index of that mod's most recent occurrence
We also initialize our ans to the size of nums
Then, starting from index i = 0 to n in the nums:
- Update the current prefix mod with the formula pref = (pref + nums[i]) % p
- Find the difference between the current prefix mod and the target, which will be the left side of our prefix sum formula
- Check with our hash map to see if we've seen the "diff" value
	- If yes, the window between the current index and the index of "diff" will be a valid window
	- Update our answer with the formula ans = min(ans, i - hash[diff])
- Set hash[pref] = i, to mark that we've seen this mod value last at index i
Once we've gone through all the values, check if our answer is stil the size of nums
If yes, there is no valid subarray that can be removed to obtain a sum divisible by p, so return -1
Otherwise, return ans
*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int mod = 0;
        for (int &num: nums) mod = (mod + num) % p; // just need to keep track of the mod, to avoid overflow
        if (mod == 0) return 0;
        // cout << mod << endl;
        const int n = nums.size();
        int pref = 0, ans = n;
        unordered_map<int, int> hash;
        hash[0] = -1; // in case the first element is included in the smallest subarray
        for (int i=0; i<n; i++)
        {
            pref = (pref + nums[i]) % p; // just need to keep track of the mod, to avoid overflow
            int diff = (pref - mod + p) % p; // prefix sum required to obtain the mod for the answer
            if (hash.find(diff) != hash.end()) ans = min(ans, i - hash[diff]);
            hash[pref] = i;
            // cout << pref << " " << diff << " " << ans << endl;
        }
        return (ans == n) ? -1 : ans;
    }
};