/*
This problem can be solved by simply reversing the vector three times
The first time, we reverse the entire vector
The second time, we reverse the first k elements
The third time, we reverse the elements from index k to the end
This works because reversing a vector (or part of it) maintains its original ordering
And by only reversing the vector partially, we place the elements to new positions
The only thing left to note is, k isn't guaranteed to be the size of nums, so to handle cases where k is very large, we need to update k with k & nums.size()
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};