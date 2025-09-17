/*
My first idea utilizes a maxHeap
Since a maxHeap sorts every new input automatically, we can remove the topmost (largest) element whenever the maxHeap size goes beyond k
Each element is a pair of integers: the absolute difference between each element of arr, and the element itself
With the way the maxHeap works, it will sort the elements by the absolute difference, then the value of the element
But this approach is quite slow, as shown from the runtime
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxHeap;
        for (int &i: arr)
        {
            int diff = abs(i - x);
            maxHeap.push({diff, i});
            if (maxHeap.size() > k) maxHeap.pop();
        }
        vector<int> ans;
        while (!maxHeap.empty())
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};