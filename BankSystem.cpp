#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Bank {
public:
    Bank(vector<long long>& balance) {
        this->Account = balance;
    }

    bool transfer(int account1, int account2, long long money) {
        if (isValidAccount(account1) && isValidAccount(account2) && money <= Account[account1 - 1]) {
            Account[account1 - 1] -= money;
            Account[account2 - 1] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (isValidAccount(account)) {
            Account[account - 1] += money;
            return true;
        }
        return false;
    }

    bool withdraw(int account, long long money) {
        if (isValidAccount(account) && money <= Account[account - 1]) {
            Account[account - 1] -= money;
            return true;
        }
        return false;
    }

private:
    vector<long long> Account;

    bool isValidAccount(int account) {
        return account >= 1 && account <= Account.size();
    }
};

int main() {
    vector<long long> balance = {10, 20, 30, 40, 50};
    Bank bank(balance);

    cout << "Transfer result: " << bank.transfer(1, 2, 5) << endl;  // Transfer $5 from account 1 to account 2
    cout << "Deposit result: " << bank.deposit(3, 15) << endl;     // Deposit $15 to account 3
    cout << "Withdraw result: " << bank.withdraw(4, 25) << endl;   // Withdraw $25 from account 4

    for (int i = 0; i < balance.size(); i++) {
        std::cout << "Balance of account " << i + 1 << ": " << balance[i] <<endl;
    }

    return 0;
}   