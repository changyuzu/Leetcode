/*
This problem can be solved by keeping track of the location of the last UNMATCHED PARENTHESIS
What do we mean by unmatched parenthesis? There are 2 possibilities:
- An open parenthesis which hasn't been closed
- A close parenthesis which doesn't have a matching open parenthesis preceding it
By keeping track of the last unmatched parenthesis, we can keep track of the length of the substring with valid parentheses
When we encounter a match, we remove the last unmatched parenthesis we had, which is a LIFO operation
Thus, we can use a stack to keep track of the index
We start our operation with an empty stack, and push -1 into the stack
This is important to ensure smooth operation
Then we start checking each element of the string
- If it's an open parenthesis, we push the index to signal that there's an unmatched parenthesis at this index
- If it's a close parenthesis, we pop the stack
	- If the stack is empty, the current element is an unmatched parenthesis, so we push this index to the stack
	- If the stack isn't empty, the element we just popped is matched to the close parenthesis from the current index
		- The next top element of the stack is the PREVIOUS unmatched parenthesis
		- The distance between the current index and the previous unmatched parenthesis is the length of the current valid parentheses substring
		- Check it against our current answer for each iteration
Why do we use the index of the previous unmatched parenthesis, instead of the index of the parenthesis matching the current element? Consider this example:
	s = ")()())"
You can see that if you match to the current element's matching parenthesis, when you get to the ')' at index 4, you'd only get length 2
But we know that the answer is 2, because the previous 2 elements are also matching parentheses
That's why we need to keep track of the PREVIOUS unmatched parenthesis
What if it's a close parenthesis with no preceding open parenthesis? Look at index 0 of the same example
At this point, we only have (-1) in the stack
We enter the for loop by popping the stack, making it empty, signaling that there is no matching open parenthesis for this close parenthesis
Therefore, we know this index is the most recent unmatched parenthesis, and push this index into the stack
Then we go through index 1-4 without touching on the index 0 in the stack, since the elements of this range are matched parentheses
When we reach 5, however, we pop index 0 from the stack, making it an empty stack
Therefore, we see that index 5 is the most recent unmatched parenthesis, and push 5 into the stack
If the string had other elements after it, the stack elements will keep being updated this way
Once we've checked all elements of the string, return the longest answer we've seen thus far
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, n = s.size();
        stack<int> st;
        st.push(-1);
        for (int i=0; i<n; i++)
        {
            if (s[i] == '(') st.push(i);
            else
            {
                st.pop();
                if (st.empty()) st.push(i);
                else ans = max(ans, i - st.top());
            }
        }
        return ans;
    }
};