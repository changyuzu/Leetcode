/*
This problem requires physically keeping track of the elements in nums in ascending order, using a separate vector
We don't actually need to know the subsequence elements themselves, just the length
So, we can still get our answer by using a vector to keep track of the elements of the vector in strictly increasing order
How do we do this? For each index 1 to n, check if nums[i] is larger than the last element of the strictly increasing vector, which I named subs
- If yes: We can simply add the current element to the back of subs, because this vector stays strictly increasing
- If no: Find the leftmost index j in subs where subs[j] >= nums[i], and replace subs[j] with nums[i]
	- This ensures that we're only keeping track of a strictly increasing sequence of numbers
	- We can search for index j using binary search for better efficiency
Once we've checked all the elements of nums, we just need to return the size of subs
*/

class Solution {
public:
    int binarySearch(int &target, vector<int> &subs)
    {
        int l = 0, r = subs.size() - 1;
        while (l <= r)
        {
            const int m = l + (r-l) / 2;
            if (subs[m] == target) return m;
            else if (subs[m] > target) r = m-1;
            else l = m+1;
        }
        // cout << l << endl;
        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subs;
        subs.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] > subs.back()) subs.push_back(nums[i]);
            else subs[binarySearch(nums[i], subs)] = nums[i];
            // for (int &sub: subs) cout << sub << " ";
            // cout << endl;
        }
        // for (int &sub: subs) cout << sub << endl;
        return subs.size();
    }
};