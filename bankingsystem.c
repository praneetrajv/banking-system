#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Maximum number of accounts
#define MAX_ACCOUNTS 100

// Base structure for bank details
typedef struct 
{
    char accountNumber[100];
    char accountHolderName[100];
    double balance;
    int pin;
} Account;

typedef struct 
{
    double loan_amount;
    int duration;
    double interest;
} Loan;

// Function prototypes
void deposit(Account *account, double amount);
void withdraw(Account *account, double amount);
void display(Account account);
void inputDetails(Loan *loan);
void processLoanGold(Loan *loan);
void processLoanHouse(Loan *loan);
void processLoanVehicle(Loan *loan);
void processLoanEducational(Loan *loan);
void processLoanPersonal(Loan *loan);
void createAccount(Account accounts[], int *accountCount);
void checkBalance(Account accounts[], int accountCount, const char *accNum, int *pinAttempts);
void performOperation(Account accounts[], int accountCount, const char *accNum, int *pinAttempts);
void displayAllAccounts(Account accounts[], int accountCount);

// Function to deposit money
void deposit(Account *account, double amount) 
{
    account->balance += amount;
}

// Function to withdraw money
void withdraw(Account *account, double amount) 
{
    if (account->balance >= amount)
    {
        account->balance -= amount;
    }
    else
    {
        printf("Insufficient funds!\n");
    }
}

// Function to display account details
void display(Account account) 
{
    printf("Account Number: %s, Account Holder Name: %s, Balance: %.2f\n", account.accountNumber, account.accountHolderName, account.balance);
}

// Function to create account dynamically based on user input
void createAccount(Account accounts[], int *accountCount) 
{
    if (*accountCount < MAX_ACCOUNTS) 
    {
        char accNum[100];
        char accHolderName[100];
        double balance;
        int pin;

        printf("Enter account number: ");
        scanf("%s", accNum);

        printf("Enter account holder name: ");
        scanf("%s", accHolderName);

        printf("Enter initial balance: ");
        scanf("%lf", &balance);

        printf("Enter PIN: ");
        scanf("%d", &pin);

        strcpy(accounts[*accountCount].accountNumber, accNum);
        strcpy(accounts[*accountCount].accountHolderName, accHolderName);
        accounts[*accountCount].balance = balance;
        accounts[*accountCount].pin = pin;

        (*accountCount)++;
    } 
    else 
    {
        printf("Maximum number of accounts reached!\n");
    }
}

// Function to check balance
void checkBalance(Account accounts[], int accountCount, const char *accNum, int *pinAttempts) 
{
    int i;
    for (i = 0; i < accountCount; ++i) 
    {
        if (strcmp(accounts[i].accountNumber, accNum) == 0) 
        {
            int pin;
            printf("Enter PIN: ");
            scanf("%d", &pin);
            if (pin == accounts[i].pin) 
            {
                printf("Balance: %.2f\n", accounts[i].balance);
                *pinAttempts = 0;
                return;
            } 
            else 
            {
                (*pinAttempts)++;
                if (*pinAttempts >= 3) 
                {
                    printf("Maximum PIN attempts exceeded. Please reset your PIN.\n");
                    return;
                }
                printf("Incorrect PIN. Please try again.\n");
            }
        }
    }
    printf("Account not found.\n");
}

// Function to perform operation
void performOperation(Account accounts[], int accountCount, const char *accNum, int *pinAttempts) 
{
    int i;
    for (i = 0; i < accountCount; ++i) 
    {
        if (strcmp(accounts[i].accountNumber, accNum) == 0) 
        {
            int pin;
            printf("Enter PIN: ");
            scanf("%d", &pin);
            if (pin == accounts[i].pin) 
            {
                char operation;
                double amount;
                printf("Enter 'w' to withdraw or 'd' to deposit: ");
                scanf(" %c", &operation);
                if (operation == 'w' || operation == 'W') 
                {
                    printf("Enter amount: ");
                    scanf("%lf", &amount);
                    withdraw(&accounts[i], amount);
                } 
                else if (operation == 'd' || operation == 'D') 
                {
                    printf("Enter amount: ");
                    scanf("%lf", &amount);
                    deposit(&accounts[i], amount);
                }
                *pinAttempts = 0;
                return;
            } 
            else 
            {
                (*pinAttempts)++;
                if (*pinAttempts >= 3) 
                {
                    printf("Maximum PIN attempts exceeded. Please reset your PIN.\n");
                    return;
                }
                printf("Incorrect PIN. Please try again.\n");
            }
        }
    }
    printf("Account not found.\n");
}

// Function to display all accounts
void displayAllAccounts(Account accounts[], int accountCount) 
{
    int i;
    for (i = 0; i < accountCount; ++i) 
    {
        display(accounts[i]);
    }
}

// Function to input loan details
void inputDetails(Loan *loan) 
{
    printf("Enter amount for the loan: ");
    scanf("%lf", &loan->loan_amount);
    printf("Enter the duration (in years) in which you can pay the loan: ");
    scanf("%d", &loan->duration);
    printf("Enter the interest rate: ");
    scanf("%lf", &loan->interest);
}

// Function to process gold loan
void processLoanGold(Loan *loan) 
{
    double month_interest = loan->interest / (100 * 12);
    double no_of_payments = loan->duration * 12;
    double payment = (loan->loan_amount * month_interest * pow(1 + month_interest, no_of_payments)) / (pow(1 + month_interest, no_of_payments) - 1);
    printf("Monthly payment for Gold loan is: %.2f\n", payment);

    char accept;
    printf("Will you accept the loan? (Y/N): ");
    scanf(" %c", &accept);
    if (accept == 'Y' || accept == 'y') 
    {
        printf("The balance is %.2f\n", loan->loan_amount); // Assuming balance is a global variable or accessible here
    }
}

// Function to process house loan
void processLoanHouse(Loan *loan) 
{
    double month_interest = loan->interest / (100 * 12);
    double no_of_payments = loan->duration * 12;
    double payment = (loan->loan_amount * month_interest * pow(1 + month_interest, no_of_payments)) / (pow(1 + month_interest, no_of_payments) - 1);
    printf("Monthly payment for House loan is: %.2f\n", payment);

    char accept;
    printf("Will you accept the loan? (Y/N): ");
    scanf(" %c", &accept);
    if (accept == 'Y' || accept == 'y') 
    {
        printf("The balance is %.2f\n", loan->loan_amount); // Assuming balance is a global variable or accessible here
    }
}

// Function to process vehicle loan
void processLoanVehicle(Loan *loan) 
{
    double month_interest = loan->interest / (100 * 12);
    double no_of_payments = loan->duration * 12;
    double payment = (loan->loan_amount * month_interest * pow(1 + month_interest, no_of_payments)) / (pow(1 + month_interest, no_of_payments) - 1);
    printf("Monthly payment for Vehicle loan is: %.2f\n", payment);

    char accept;
    printf("Will you accept the loan? (Y/N): ");
    scanf(" %c", &accept);
    if (accept == 'Y' || accept == 'y') 
    {
        printf("The balance is %.2f\n", loan->loan_amount); // Assuming balance is a global variable or accessible here
    }
}

// Function to process educational loan
void processLoanEducational(Loan *loan) 
{
    double month_interest = loan->interest / (100 * 12);
    double no_of_payments = loan->duration * 12;
    double payment = (loan->loan_amount * month_interest * pow(1 + month_interest, no_of_payments)) / (pow(1 + month_interest, no_of_payments) - 1);
    printf("Monthly payment for Educational loan is: %.2f\n", payment);

    char accept;
    printf("Will you accept the loan? (Y/N): ");
    scanf(" %c", &accept);
    if (accept == 'Y' || accept == 'y') 
    {
        printf("The balance is %.2f\n", loan->loan_amount); // Assuming balance is a global variable or accessible here
    }
}

// Function to process personal loan
void processLoanPersonal(Loan *loan) 
{
    double month_interest = loan->interest / (100 * 12);
    double no_of_payments = loan->duration * 12;
    double payment = (loan->loan_amount * month_interest * pow(1 + month_interest, no_of_payments)) / (pow(1 + month_interest, no_of_payments) - 1);
    printf("Monthly payment for Personal loan is: %.2f\n", payment);

    char accept;
    printf("Will you accept the loan? (Y/N): ");
    scanf(" %c", &accept);
    if (accept == 'Y' || accept == 'y') 
    {
        printf("The balance is %.2f\n", loan->loan_amount); // Assuming balance is a global variable or accessible here
    }
}

int main() 
{
    Account accounts[MAX_ACCOUNTS]; // Array to store accounts
    char choice;
    char accNum[100];
    int accountCount = 0;
    int pinAttempts = 0;
    printf("\n===================== WELCOME TO ALPHA BANK OF C ====================\n");
    do 
    {
        printf("\n1. Create Account\n");
        printf("2. Check Balance\n");
        printf("3. Perform Operation\n");
        printf("4. Display All Accounts\n");
        printf("5. Loan Options\n");
        printf("6. EXIT\n");
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice) 
        {
            case '1': 
                createAccount(accounts, &accountCount);
                break;
            case '2': 
                printf("Enter account number: ");
                scanf("%s", accNum);
                checkBalance(accounts, accountCount, accNum, &pinAttempts);
                break;
            case '3': 
                printf("Enter account number: ");
                scanf("%s", accNum);
                performOperation(accounts, accountCount, accNum, &pinAttempts);
                break;
            case '4': 
                displayAllAccounts(accounts, accountCount);
                break;
            case '5': 
            {
                int k;
                printf("1. House Loan\n2. Educational Loan\n3. Personal Loan\n4. Gold Loan\n5. Vehicle Loan\n");
                printf("Enter your Loan Choice: ");
                scanf("%d", &k);
                switch (k) 
                {
                    case 1: 
                    {
                        Loan houseLoan;
                        printf("Enter house loan details\n");
                        inputDetails(&houseLoan);
                        processLoanHouse(&houseLoan);
                        break;
                    }
                    case 2: 
                    {
                        Loan educationalLoan;
                        printf("Enter educational loan details\n");
                        inputDetails(&educationalLoan);
                        processLoanEducational(&educationalLoan);
                        break;
                    }
                    case 3: 
                    {
                        Loan personalLoan;
                        printf("Enter personal loan details\n");
                        inputDetails(&personalLoan);
                        processLoanPersonal(&personalLoan);
                        break;
                    }
                    case 4: 
                    {
                        Loan goldLoan;
                        printf("Enter gold loan details\n");
                        inputDetails(&goldLoan);
                        processLoanGold(&goldLoan);
                        break;
                    }
                    case 5: 
                    {
                        Loan vehicleLoan;
                        printf("Enter vehicle loan details\n");
                        inputDetails(&vehicleLoan);
                        processLoanVehicle(&vehicleLoan);
                        break;
                    }
                    default: 
                        printf("This loan is not available here!\n");
                }
                break;
            }
            case '6':
                printf("Exiting...!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != '6');

    return 0;
}