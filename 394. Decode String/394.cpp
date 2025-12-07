/*
This problem can be solved using 2 stacks
The first stack keeps track of k, or the frequency of the string that follows in the bracket
The second stack keeps track of the current string BEFORE encountering the brackets
There will be a few things to keep track of:
- Current substring (curr): the string read so far
- Frequency (num): the number being read before the opening bracket, which is the frequency of the following substring
- The answer string (ans): the string we return
Whenever we encounter a character which isn't a number or brackets, we append it to the string curr
If the character is a digit, we calculate the corresponding number for the frequency
If it's an opening bracket, we need to push the current substring (curr) and frequency (num) into their corresponding stacks, then reset curr to an empty string and num to 0
We will then read another substring, which will be stored in curr, until we reach the closing bracket
When we reach the closing bracket, we get the frequency of this substring and the previous substring, to which we will attach the current substring
Let's look at this testcase: s = "3[a2[c]]"
Without taking the 3 into account, let's just start with the a2[c] part
We know that we need to attach 2 c's to the a
So, when we encounter the opening bracket, we need to keep track of the frequency of the bracket string (2, in this case) and the string curr that we're attaching it to (a, in this case)
Then, when we reach the closing bracket, we get the frequency of the string in the bracket (2), the string to be attached (a), and put the bracket string as many times as needed
The next step depends on whether there's anything else in the frequency stack
If the frequency stack is empty (Which would be the case if s = "a2[c]"), then we just add this string to our answer
But if the frequency stack isn't empty (Which would be the case if s = "3[a2[c]]"), then we need to set the attached substring as our current substring (curr)
Once we've gone through the entire string, return ans + curr
We need to add curr to the end of ans, because there are testcases where the encoded string ends with characters not in a bracket
Check using this testcase to ensure that the solution is working correctly: s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef"
*/

class Solution {
public:
    string decodeString(string s) {
        stack<int> freq;
        stack<string> sub;
        int num = 0;
        string curr = "", ans = "";
        for (char &ch: s)
        {
            if (isdigit(ch)) num = (num * 10) + (ch - '0');
            else if (ch == '[')
            {
                freq.push(num);
                num = 0;
                sub.push(curr);
                curr = "";
            }
            else if (ch == ']')
            {
                int f = freq.top();
                freq.pop();
                string tmp = sub.top();
                sub.pop();
                while (f--) tmp += curr;
                if (freq.empty())
                {
                    ans += tmp;
                    curr = "";
                }
                else curr = tmp;
            }
            else curr += ch;
        }
        return ans + curr;
    }
};