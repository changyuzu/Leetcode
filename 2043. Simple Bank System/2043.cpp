/*
This problem isn't difficult for those familiar with design problems
Basically, we just need to define the data structures and variables used in the Bank class
There are 2:
- A long long vector for the balance
- An int variable for the size of the vector, i.e. the number of accounts
For the initialization, I used move(balance) to transfer the contents of the vector in the initial call to our own vector without copying the data, which saves memory
Then, for all the functions, we just need to ensure that the transactions are valid
So, if any of the accounts are larger than n, or the balance of that account is less than the transfer or withdraw amount, return false
Otherwise, perform the transactions and return true
*/

class Bank {
public:
    vector<long long> bal;
    int n = 0;
    Bank(vector<long long>& balance) {
        bal = move(balance);
        n = bal.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > n || account2 > n || money > bal[account1 - 1]) return false;
        bal[account1 - 1] -= money;
        bal[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > n) return false;
        bal[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account > n || money > bal[account - 1]) return false;
        bal[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */