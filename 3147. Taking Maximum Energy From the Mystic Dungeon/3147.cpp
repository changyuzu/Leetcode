/*
For this problem, we can use a dynamic programming approach
I modified the energy vector in-place for this, to save memory
We start checking from the back, since we can simply start from the last elements and not touch the magicians in front, in case they have negative energy
If you can jump forward from the current magician, you add the energy of the kth magician after the current magician
For each step, check for the maximum value seen so far using ans, which was initialized to INT_MIN
Once we've reached the first index, return ans
*/

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size(), ans = INT_MIN;
        for (int i=n-1; i>=0; i--)
        {
            if (i+k < n) energy[i] += energy[i+k];
            ans = max(ans, energy[i]);
        }
        return ans;
    }
};