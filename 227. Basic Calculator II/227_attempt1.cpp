/*
My first attempt utilizes two stacks: one for the operators, one for the numbers
So, while we iterate over the string, if s[i] is a space, we just continue
But if s[i] is a digit, we add it to the current number with the formula n = n * 10 + (ch - '0')
Otherwise, it's an operator, and we first check if the last seen operator is '*' or '/'
- If yes, we need to do the multiplication / division first
	- I defined a function for this, which takes the top element from the number stack, pops both the number and operator stack, and pushes the result of the calculation into the num stack
- If not, simply push the current number into the stack
- In either case, we need to push the current operator into the stack and reset the current number to 0
Once we've reached the end of the string, check if the last operator is '*' or '/', in which case we multiply / divide first
Then, we start checking the rest of the operations, which will only be additions / subtractions
For each operator, we check if the preceding operator is a '-', in which case the current number is a negative value
I defined a function to handle this case, which turns the current number to its negative value, and replaces the preceding operator's '-' to a '+'
Once we've gone through all the operators, we return the result
*/

class Solution {
public:
    int mult_div(stack<int> &num, stack<char> &op, int b)
    {
        int a = num.top();
        if (op.top() == '*') b = a * b;
        else b = a / b;
        num.pop();
        op.pop();
        return b;
    }
    void min(stack<char> &op, int &a)
    {
        a *= -1;
        op.pop();
        op.push('+');
    }
    int calculate(string s) {
        stack<char> op;
        stack<int> num;
        int n = 0;
        for (char &ch: s)
        {
            if (ch == ' ') continue;
            else if (isdigit(ch))
            {
                n = (n * 10) + (ch - '0');
            }
            else
            {
                // cout << n << endl;
                if (!op.empty() && (op.top() == '*' || op.top() == '/')) num.push(mult_div(num, op, n));
                else
                {
                    num.push(n);
                }
                op.push(ch);
                n = 0;
            }
        }
        int b = n;
        if (!op.empty() && (op.top() == '*' || op.top() == '/')) b = mult_div(num, op, b);
        while (!op.empty())
        {
            int a = num.top();
            num.pop();
            char o = op.top();
            op.pop();
            // cout << a << " " << o << " " << b << endl;
            if (!op.empty() && op.top() == '-') min(op, a);
            if (o == '+') b = a+b;
            else b = a-b;
            // cout << b << endl;
        }
        return b;
    }
};