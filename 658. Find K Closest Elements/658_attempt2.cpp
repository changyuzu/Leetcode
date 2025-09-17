/*
My second attempt uses 2 pointers so we don't need any extra space
We start with the left and right pointers on the first and last element of the array
Look back on the condition that defines a as closer to x than b:
- |a - x| < |b - x|, or
- |a - x| == |b - x| and a < b
From this definition, we can derive that unless |a - x| > |b - x|, we move r to the left, because the smaller element takes precedence over the larger element in the case where the absolute difference is the same
Once we've got a window of size k, we start adding the elements in the window to our answer vector, and return it
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0, r = arr.size() - 1;
        while (r - l >= k)
        {
            // cout << l << " " << r << " " << arr[l] << " " << arr[r] << endl;
            if (x - arr[l] > arr[r] - x) l++;
            else r--;
        }
        vector<int> ans;
        for (int i=l; i<=r; i++) ans.push_back(arr[i]);
        return ans;
    }
};