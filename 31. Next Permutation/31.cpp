/*
This solution builds on the following algorithm for generating the next permutation:
1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
2. Find the largest index l greater than k such that a[k] < a[l].
3. Swap the value of a[k] with that of a[l].
4. Reverse the sequence from a[k + 1] up to and including the final element a[n].
So we start checking all elements of nums from the second to last index, and stop once we've found an index which is smaller than the previous element
If there is no such element, we'd have ended up at index -1
This means all elements are arranged in non-increasing order, i.e. we're already at the greatest permutation
In this case, the next permutation is the smallest permutation, which we obtain by simply reversing the entire vector
Otherwise, we start searching again for the element with larger index which is larger than the first element which is smaller than its next element
Swap the value of those 2 elements, then reverse the sequence starting from the index after the first element which is smaller than its next element
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), p = n-2;
        while (p >= 0)
        {
            if (nums[p] < nums[p+1]) break;
            p--;
        }
        if (p == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int r = n-1;
        while (r > p)
        {
            if (nums[r] > nums[p]) break;
            r--;
        }
        // cout << p << " " << r << endl;
        swap(nums[r], nums[p]);
        reverse(nums.begin()+p+1, nums.end());
    }
};