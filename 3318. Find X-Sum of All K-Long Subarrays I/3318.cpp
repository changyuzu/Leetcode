/*
This problem can be solved with sliding window and a minHeap (priority_queue) of pairs of integers
The first element of the pair would be the frequency, while the second one will be the element
I defined a helper function to calculate the x-sum, which takes the frequency of each element
While we push the element and its frequency into the minHeap, we also keep track of how many elements have been added
If the number of elements go beyond x, we pop from the top of the minHeap, which should the element with the least frequency and least value
Once we've checked all values, we start counting the x-sum by taking all elements of the minHeap and multiplying the element and frequency, and adding the product into our answer
Once we've checked everything in the minHeap, return the answer, i.e. the x-sum
Then, in the main body, we start building our frequency table
The problem has defined a limitation of 1 <= nums[i] <= 50, so we can simply use a vector of size 51 to keep track of the frequencies instead of a hash map
We also need a pointer to keep track of the left end of the sliding window, which should be initialized to 0
Then, while r < n:
- Increment the frequency of nums[r]
- If the window size is k:
	- Add the x-sum of the current frequencies to the answer vector
	- Decrement the frequency of nums[l]
	- Move l forward 1 step
Once r reaches the n, we've checked all elements, and return ans
*/

class Solution {
public:
#define pii pair<int,int>
    int XSum(vector<int> &hash, int &x)
    {
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        int c = 0;
        for (int i=1; i<=50; i++)
        {
            if (hash[i] == 0) continue;
            minHeap.push({hash[i], i});
            c++;
            if (c > x) minHeap.pop();
        }
        c = 0;
        while (!minHeap.empty())
        {
            c += minHeap.top().first * minHeap.top().second;
            minHeap.pop();
        }
        return c;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size(), l = 0;
        vector<int> hash(51, 0);
        vector<int> ans;
        for (int r = 0; r < n; r++)
        {
            hash[nums[r]]++;
            if (r - l == k - 1)
            {
                ans.push_back(XSum(hash, x));
                hash[nums[l]]--;
                l++;
            }
        }
        return ans;
    }
};