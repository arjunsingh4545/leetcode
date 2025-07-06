class Bank {
    vector<long long> balances;

    // Helper function to check if an account is valid
    bool isValid(int account) {
        return account >= 1 && account <= balances.size();
    }

public:
    Bank(vector<long long>& balance) {
        balances = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (!isValid(account1) || !isValid(account2)) return false;
        if (balances[account1 - 1] < money) return false;

        balances[account1 - 1] -= money;
        balances[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!isValid(account)) return false;

        balances[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!isValid(account)) return false;
        if (balances[account - 1] < money) return false;

        balances[account - 1] -= money;
        return true;
    }
};
