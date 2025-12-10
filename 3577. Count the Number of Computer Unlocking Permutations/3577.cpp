/*
This problem can be solved by simply checking whether an element at a certain index is larger than the one at index 0, and multiplying by the index each step
Basically, these are the things to note:
- Index 0 must be at the beginning of all permutations
- Since computers can only be decrypted by computers with lower complexity, if we ever encounter a computer with lower or equal complexity, computer[0] CANNOT decrypt it
	- If there is any computer that can't be decrypted, there is no valid order where all computers can be unlocked
If there is no computer with lower or equal complexity, then we can add the current index to our permutation
The permutation for n elements would be a factorial
We can achieve the factorial by simply multiplying the indexes as we go
Remember to perform the modulo operation to avoid overflow
*/

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int n = complexity.size(), min = complexity[0], MOD = 1e9+7;
        int ans = 1;
        for (int i=1; i<n; i++)
        {
            if (complexity[i] <= min) return 0;
            ans = (ans * (long) i) % MOD;
        }
        return ans;
    }
};