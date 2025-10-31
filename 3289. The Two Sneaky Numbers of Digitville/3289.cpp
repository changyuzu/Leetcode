/*
My approach is simply keeping track of the difference between the current element and it's supposed index
There are n numbers, with 2 duplicates, so the lengh of nums is n+2
If we sort nums, there will be 2 elements which will cause the the index and the element at that index to be misaligned
By keeping track of the difference between the element and its index, we can easily find our answer
Start with diff = 0, meaning there is no difference at first
Whenever we encounter nums[i] != i-diff, that means nums[i] appeared more than once
So increment diff and push nums[i] to our answer vector
Since we know there are exactly two repeated elements, when diff == 2, we can stop checking the elements and simply return our answer vector
*/

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size(), diff = 0;
        for (int i=0; i<n; i++)
        {
            if (nums[i] != i-diff)
            {
                diff++;
                ans.push_back(nums[i]);
                if (diff == 2) break;
            }
        }
        return ans;
    }
};