/*
This problem can be solved by simply utilizing a stack to store the numbers
Then, whenever we encounter an operator, we get the top 2 numbers from the stack, and push the result from the operation into the stack again
Remember to convert the numbers from string to int, either during the stack pushing, or popping, to ensure correct calculation
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string &s: tokens)
        {
            if (s == "+")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a+b);
            }
            else if (s == "-")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a-b);
            }
            else if (s == "*")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a*b);
            }
            else if (s == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a/b);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};