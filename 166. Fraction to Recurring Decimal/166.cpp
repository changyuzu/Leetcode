/*
For this problem, we mostly need to be careful of extremely large numbers and extremely small numbers, like -2147483648
-2147483648 is extra tricky because you can't just use the abs function directly, you need to cast it as a long long first
Then, when we get to the decimal values, we need to keep track of whether we've seen the remainder, and stop our operations once we see the same remainder appearing again
We can use a hash map to do this, keep track of the remainder value we've seen as well as its position in the answer string
So we start from the simpler cases:
- If numerator == 0, simply return 0
- If either denominator or numerator is negative (but not both), our answer is negative, so we put '-' at the beginning of the answer string
- Calculate the result of numerator / denominator and add to the answer string. If numerator % denominator == 0, return our answer string directly
- While remainder is larger than 0:
	- If we encounter a remainder value that we've seen before, we put a '(' in front of its first occurrence, append a ')' to the end of our answer string, and break out of the loop
	- Otherwise, we keep track of the position of the current remainder (we can use the string's current size for this), and update the remainder & answer string according to the long division concept
We exit the loop when remainder becomes 0 OR we see a remainder that has appeared before, signaling a loop, and then we have our answer
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string s = "";
        if ((denominator < 0) ^ (numerator < 0)) s.push_back('-');
        
        long long d = abs((long long)denominator);
        long long n = abs((long long)numerator);
        s += to_string(n / d);
        long long rem = (n % d);
        if (rem == 0) return s;

        s.push_back('.');
        unordered_map<long long, int> hash;
        while (rem > 0)
        {
            if (hash.find(rem) != hash.end())
            {
                s.insert(hash[rem], "(");
                s.push_back(')');
                break;
            }
            int pos = s.size();
            hash[rem] = pos;
            rem *= 10;
            s.push_back(rem / d + '0');
            rem %= d;
        }
        return s;
    }
};