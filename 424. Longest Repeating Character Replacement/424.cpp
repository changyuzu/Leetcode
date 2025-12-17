/*
This problem can be solved using sliding window
Basically, we just need to keep track of the char with the highest frequency, left and right pointers for the window, and check if the size of the window becomes bigger than the maxCount + k
Say that for a certain substring, there are n instances of the majority element
In order to turn all elements in this substring into the majority element, we'd need to convert (total number of characters - n) elements
The total number of characters would be the size of the sliding window, and the result of the subtraction can't be greater than k
So, we just need a hash map to keep track of the frequency of each element, check the frequency against the maxCount, move the right pointer forward, and if the sliding window becomes bigger than maxCount + k, move the left pointer
At the end, the size of the sliding window will be the length of the longest substring
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int left = 0, right = 0, maxCount = 0;
        for (char &ch: s)
        {
            int c = ch - 'A';
            freq[c]++;
            maxCount = max(maxCount, freq[c]);
            right++;
            if (maxCount + k < right - left)
            {
                freq[s[left] - 'A']--;
                left++;
            }
        }
        return right - left;
    }
};