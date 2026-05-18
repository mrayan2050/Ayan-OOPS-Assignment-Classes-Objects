class BankAccount {

    private final int accountNumber;
    private double balance;
    private String ownerName;

    BankAccount(int accountNumber, String ownerName, double balance) {
        this.accountNumber = accountNumber;
        this.ownerName = ownerName;
        this.balance = balance;
    }

    double balance() {
        return balance;
    }

    void add(double amount) {
        balance += amount;
    }

    void subtract(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            System.out.println("Insufficient Balance in Account " + accountNumber);
        }
    }

    int getAccountNumber() {
        return accountNumber;
    }

    String getOwnerName() {
        return ownerName;
    }

    void display() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Owner Name: " + ownerName);
        System.out.println("Balance: " + balance);
        System.out.println();
    }
}

class AccountManager {

    BankAccount accounts[] = new BankAccount[10];
    int count = 0;

    void createAccount(BankAccount account) {
        accounts[count] = account;
        count++;
    }

    void deleteAccount(int accountNumber) {
        for (int i = 0; i < count; i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                for (int j = i; j < count - 1; j++) {
                    accounts[j] = accounts[j + 1];
                }
                count--;
                System.out.println("Account Deleted");
                return;
            }
        }
    }

    void credit(int accountNumber, double amount) {
        for (int i = 0; i < count; i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                accounts[i].add(amount);
            }
        }
    }

    void debit(int accountNumber, double amount) {
        for (int i = 0; i < count; i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                accounts[i].subtract(amount);
            }
        }
    }

    void displayAccounts() {
        for (int i = 0; i < count; i++) {
            accounts[i].display();
        }
    }
}

public class Bank {

    public static void main(String[] args) {

        AccountManager manager = new AccountManager();

        manager.createAccount(new BankAccount(1001, "Ayan", 5000));
        manager.createAccount(new BankAccount(1002, "Rahul", 7000));
        manager.createAccount(new BankAccount(1003, "Priya", 6500));
        manager.createAccount(new BankAccount(1004, "Sneha", 8000));
        manager.createAccount(new BankAccount(1005, "Arjun", 9000));

        manager.credit(1001, 1000);
        manager.debit(1002, 500);

        System.out.println("Bank Account Details:");
        manager.displayAccounts();
    }
}