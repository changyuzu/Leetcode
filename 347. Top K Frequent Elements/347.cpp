/*
This problem can be solved using a hash map and a minHeap
FIrst, check if nums only has 1 element, in which case we simply return the first element in a vector
Otherwise, we start by filling up the hash map with the frequency of each element
Once we have the frequency of all elements, we start filling up the priority queue
For all elements in the hash map, push the frequency and element as a pair of two integers into the minHeap
When there have been more than k elements pushed in the minHeap, we pop the topmost element, which should be the element with the least frequency
Once we have the top k elements, we push all the elements into our answer vector and return ans
*/

class Solution {
public:
#define pi pair<int, int>
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 1) return {nums[0]};
        unordered_map<int, int> hash;
        for (int &num: nums) hash[num]++;
        priority_queue<pi, vector<pi>, greater<pi>> minHeap;
        int c = 0;
        for (auto &[num, freq]: hash)
        {
            minHeap.push({freq, num});
            c++;
            if (c > k) minHeap.pop();
        }
        vector<int> ans;
        while (!minHeap.empty())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};