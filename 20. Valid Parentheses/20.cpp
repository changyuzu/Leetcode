/*
This problem can be solved by utilizing a stack to keep track of the last opening parentheses in the order that they last appeared
Remember that open brackets must be closed in the correct order by the same type of bracket
So when we evaluate closing brackets, we evaluate the opening brackets from the back
The LIFO structure of a stack is best suited for this operation
Before we start evaluating the brackets, we can first check the size of the string
Valid parentheses need to appear in pairs, so the size of the string must be even
So, if the size of the string is odd, we can return false immediately, because there's guaranteed to be one parenthesis with no pair
Then, we start checking the string
For each character ch in string s:
- If ch is an opening parenthesis ('(', '{', '['), push it into the stack
- Else, ch must be a closing parenthesis. If the stack is empty, there is nothing to pair with it, so return false immediately
- Otherwise, check whether the top of the stack matches ch
	- If yes, simply pop from the stack
	- If not, return false
Once we've gone through all the parentheses, return whether the stack is empty
Remember that in order for all the parentheses to be valid, all the opening parentheses need to be closed, so the stack should be empty in that case
*/

class Solution {
public:
    bool isValid(string s) {
        const int n = s.size();
        if (n % 2 != 0) return false;
        stack<char> st;
        for (auto &ch: s)
        {
            if (ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else if (st.empty()) return false;
            else if ((ch == ')' && st.top() == '(') || (ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[')) st.pop();
            else return false;
        }
        return st.empty();
    }
};