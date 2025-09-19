/*
For this problem, we utilize a hashmap and a custom priority queue
The hash map is used to store the frequency of each word
The priority queue is basically a minHeap, with an additional condition of sorting the elements by the lexicographical order of the string for elements with the same frequency
We first start by filling the hash map
Then we fill the minHeap using pairs of integer and string, which represent the frequency and the corresponding string
If the size of the minHeap goes above k, we pop the topmost element, which would the elements with the smallest frequency, or elements with larger lexicographical order
Last, we declare our answer array of size k, and start filling the array from the back, since the topmost element has the smallest frequency / larger lexicographical order
*/

#define psi pair<int, string>

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto compare = [](psi &a, psi &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        };
        priority_queue<psi, vector<psi>, decltype(compare)> minHeap(compare);
        unordered_map<string, int> hash;
        for (string s: words) hash[s]++;
        for (auto [key, val]: hash)
        {
            minHeap.push({val, key});
            if (minHeap.size() > k) minHeap.pop();
        }
        vector<string> ans (k);
        int idx = k-1;
        while (!minHeap.empty())
        {
            // cout << minHeap.top().first << " " << minHeap.top().second << endl;
            ans[idx--] = minHeap.top().second;
            minHeap.pop();
        }
        return ans;
    }
};