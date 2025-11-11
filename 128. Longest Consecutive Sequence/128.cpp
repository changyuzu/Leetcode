/*
This problem can be solved by simply checking for the current number's next and previous values
To avoid repeating the operation on the same number, and to find values more easily, we can cast the vector nums into an unordered_set
Declare a variable maxLen to keep track of the longest sequence, which is initialized to 0 (since the vector nums could be empty)
Then, for all elements of s (which we'll refer to as num), we do the following:
- If we can find (num - 1) in the set, we skip this element, since it will be covered in the iteration of that number
- Otherwise, we declare a counter called i, initialized to 1
- While we can still find (num + i) in the set, keep incrementing i
	- This gives us the length of the longest consecutive subsequence starting at num
- Once we encounter any i for which (num + i) is not found in the set, check maxLen against i and update its value accordingly
When we've checked all elements in the set, return maxLen
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLen = 0;
        for (auto &num: s)
        {
            if (s.find(num - 1) != s.end()) continue;
            int i = 1;
            while (s.find(num+i) != s.end()) i++;
            maxLen = max(maxLen, i);
        }
        return maxLen;
    }
};