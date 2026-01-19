/*
This problem can be solved by using a hashmap to keep track of where we saw a number before
With this method, we can solve the problem with one pass
Know that if we have one number fixed, we can obtain target by adding the number with (target - number)
For each index in range [0..n], where n is the size of the vector nums:
- Check if we've seen (target - num) before
- If yes, return the index of (target - num) and the current index
- If not, add the current number and index to the hash map
There's guaranteed to be an answer, so we can just put return {} outside the for loop
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i=0; i<nums.size(); i++)
        {
            if (hash.find(target - nums[i]) != hash.end()) return {hash[target - nums[i]], i};
            hash[nums[i]] = i;
        }
        return {};
    }
};