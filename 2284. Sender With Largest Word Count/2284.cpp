/*
For this problem, just keep track of how many words are in each message, then add it to the sender's word count
Use a hash table to keep track of each sender's word count
You can get the word count by counting the spaces, since the constraints specifically mentioned that the messages do not have leading or trailing spaces, and all words are separated by a single space
So the word count is 1 + space count
Remember to add 1 to each messages' word count, since if a sender has send messages multiple times, not adding 1 will make you miss the first word of the rest of the messages, causing inaccurate calculation
Once you've got the word count for the current message, add it to the hash table for the current sender
If the total word count for the current sender is higher than the original answer, or if the total word count is the same and the current sender name has higher lexicographical order, set the current sender as our new answer
Once we've checked all messages, return ans
*/

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> hash;
        string ans = senders[0];
        int n = senders.size();
        for (int i=0; i<n; i++)
        {
            int c = 1;
            for (char &ch: messages[i])
            {
                if (ch == ' ') c++;
            }
            hash[senders[i]] += c;
            if (hash[senders[i]] > hash[ans] || (hash[senders[i]] == hash[ans] && senders[i] > ans))
            {
                ans = senders[i];
            }
        }
        return ans;
    }
};