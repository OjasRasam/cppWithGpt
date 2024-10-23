#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account {
    private:
        string accountHolder;
        int accountNumber;
        double balance;
        vector<string> transactionHistory; //To store the transaction history

    public:
        // Constructor
        Account(string holderName, int accNo, double initialBalance) {
            accountHolder = holderName;
            accountNumber = accNo;
            balance = initialBalance;
            transactionHistory.push_back("Account created with balance $" + to_string(initialBalance));
        }

        // Method to display account info
        void displayInfo() {
            cout << "\nAccount Holder: " << accountHolder << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: $" << balance << endl;
        }

        // Method to deposit money
        void deposit(double amount) {
            balance += amount;
            string transaction = "Deposited $" + to_string(amount) + ". New balance: $" + to_string(balance);
            transactionHistory.push_back(transaction);
            cout << transaction << endl;
        }

        // Method to withdraw money
        void withdraw(double amount) {
            if (amount > balance) {
                cout << "Insufficient funds!" << endl;
                transactionHistory.push_back("Failed withdrawal of $" + to_string(amount) + " due to insufficient funds.");
            } else {
                balance -= amount;
                string transaction = "Withdrew $" + to_string(amount) + ". New balance: $" + to_string(balance);
                transactionHistory.push_back(transaction);
                cout << transaction << endl;
            }
        }

        // Method to display transaction history
        void displayTransactionHistory() {
            cout << "\nTransaction History for Account " << accountNumber << ":\n";
            for (const string& transaction : transactionHistory) {
                cout << transaction << endl;
            }
        }
};

int main() {
    // Create a new account
    Account ojasAccount("Ojas Rasam", 19706, 5000000);

    // Perform some transactions
    ojasAccount.deposit(1000001);
    ojasAccount.withdraw(2);
    ojasAccount.withdraw(1000000);

    // Display account info and transaction history
    ojasAccount.displayInfo();
    ojasAccount.displayTransactionHistory();

    return 0;
}