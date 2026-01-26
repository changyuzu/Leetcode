/*
This problem can be solved by sorting the array and keeping track of the smallest difference between each consecutive element
Know that the minimum absolute difference for any single element has to be between that element and the next or previous element in a sorted array
Since the array only has distinct integers, there will be no cases of 0 difference
So, we just need to sort the array
Then we initialize an integer to store the smallest difference, which I named diff and initialized to INT_MAX
Then, for each index i in range [1..n-1], where n is the size of the array:
- Check the difference between arr[i+1] and arr[i]
- If the difference is equal to the value of diff, append this pair into our answer array
	- Since the pairs need to be sorted with the first element being smaller, we need to append {arr[i], arr[i+1]}
- But if the difference is smaller than the value of diff, the previous answer vector is no longer valid
	- Clear the answer vector
	- Set the current difference as the new value of diff
	- Append {arr[i], arr[i+1]} into the answer vector
Once we've reached the end of the array, return our answer vector
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int diff = INT_MAX;
        for (int i=0; i < arr.size() - 1; i++)
        {
            const int curr = arr[i+1] - arr[i];
            if (curr == diff) ans.push_back({arr[i], arr[i+1]});
            else if (curr < diff)
            {
                ans.clear();
                diff = curr;
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};