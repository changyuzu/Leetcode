/*
This problem can be solved by keeping track of occurrences of a number before AND after a certain index
We can use unordered_maps for this, but I tried using an array and the code runs much faster with less memory
This is doable because nums[i] is limited to 0 <= nums[i] <= 10^5
But I've also included the approach using unordered_map commented out below
Basically, for all num in nums, we check how many times num * 2 appeared before and after that index, and add the product to our answer
We add the product because each prefix (occurrence before num) can be paired will each suffix (occurrence after num)
To do this, I used two arrays, filled with two for loops
The first one fills the suffix array, which will be the original count for the occurrences of each element in nums
The second one does the following:
- Decrement suff[nums[i]] (this needs to be done first to exclude the current index from occurrences of nums[i], which is crucial in case nums[i] == 0)
- Check if the double of nums[i] is within bounds (0 <= nums[i] <= 10^5)
	- If yes, add the product of pref[nums[i] * 2] and suff[nums[i] * 2] to our answer
	- Apply the modulo operator as needed to avoid overflow
	- The result of pref * suff might be too large for int before the modulo operator, so I used long to hold it temporarily
- Increment pref[nums[i]]
Once we've finished the second for loop, return our answer
*/

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int M = 1e5+1, MOD = 1e9+7;
        int ans = 0;
        int suff[M] = {0}, pref[M] = {0};
        for (int &i: nums) suff[i]++;
        for (int &i: nums)
        {
            suff[i]--;
            int x2 = i * 2;
            if (x2 < M)
            {
                // cout << i << endl;
                ans = (ans + ((long) pref[x2] * suff[x2]) % MOD) % MOD;
            }
            pref[i]++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int specialTriplets(vector<int>& nums) {
//         const int n = nums.size(), MOD = 1e9+7;
//         int ans = 0;
//         unordered_map<int, int> suff;
//         unordered_map<int, int> pref;
//         for (int &i: nums) suff[i]++;
//         for (int &i: nums)
//         {
//             suff[i]--;
//             int x2 = i * 2;
//             if (pref[x2] > 0 && suff[x2] > 0)
//             {
//                 // cout << i << endl;
//                 ans = (ans + ((long) pref[x2] * suff[x2]) % MOD) % MOD;
//             }
//             pref[i]++;
//         }
//         return ans;
//     }
// };