/*
This problem can be solved with a minHeap, which stores the k largest elements, with the smallest always at the top of the heap
So, we initialize a priority_queue as our minHeap
For all num in nums:
- If the size of the minHeap is still smaller than k, we simply push num into the minHeap
- Otherwise, we check num against the top of the minHeap
	- If the top element is smaller than num, then num should be among the k largest elements
	- So we pop from the minHeap and push num into it
Once we've checked all elements, return the top of the minHeap
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int &num: nums)
        {
            if (minHeap.size() < k) minHeap.push(num);
            else if (minHeap.top() < num)
            {
                minHeap.pop();
                minHeap.push(num);
            }
        }
        return minHeap.top();
    }
};