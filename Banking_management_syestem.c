#include <stdio.h>
#include <string.h>

int choice;
int id[5];
char name[5][30];
char father[5][30];
int age[5];
long long int accountNo[5];
long long int aadharNo[5];
int balance[5];
int count = 0;

// Function declarations
void displayMenu();
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void displayAccountDetails();
void verifyTaskNo();

int main()
{
    displayMenu();
    return 0;
}

// Function to display the menu and handle choices
void displayMenu()
{
    do {
        printf("\n--- Banking System Menu ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Display Account Details\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: displayAccountDetails(); break;
            case 0: printf("Thank you for using our banking system!\n"); break;
            default: verifyTaskNo(); break;
        }

    } while (choice != 0);
}

// Function to create a new account
void createAccount()
{
    if (count >= 5)
    {
        printf("Maximum Account limit (5) reached.\n");
        return;
    }

    printf("\nCreating Account %d\n", count + 1);
    id[count] = count + 123; // Auto-generated ID
    printf("Generated ID: %d\n", id[count]);

    printf("Enter Name: ");
    scanf(" %[^\n]", name[count]);

    printf("Enter Father's Name: ");
    scanf(" %[^\n]", father[count]);

    printf("Enter Age: ");
    while (scanf("%d", &age[count]) != 1)
    {
        printf("Invalid Input. Please enter numeric age: ");
        while (getchar() != '\n');
    }

    // Account Number Validation
    long long int tempAcc;
    while (1)
    {
        printf("Enter 11-digit Account Number: ");
        if (scanf("%lld", &tempAcc) == 1)
        {
            if (tempAcc >= 10000000000 && tempAcc <= 99999999999)
            {
                accountNo[count] = tempAcc;
                break;
            }
            else
            {
                printf("Invalid! Account Number must be 11 digits.\n");
            }
        }
        else
        {
            printf("Invalid input! Please enter only numbers.\n");
            while (getchar() != '\n');
        }
    }

    // Aadhar Number Validation
    long long int tempAadhar;
    while (1)
    {
        printf("Enter 12-digit Aadhar Number: ");
        if (scanf("%lld", &tempAadhar) == 1)
        {
            if (tempAadhar >= 100000000000 && tempAadhar <= 999999999999)
            {
                aadharNo[count] = tempAadhar;
                break;
            }
            else
            {
                printf("Invalid! Aadhar Number must be 12 digits.\n");
            }
        }
        else
        {
            printf("Invalid input! Please enter only numbers.\n");
            while (getchar() != '\n');
        }
    }

    printf("Enter Opening Balance (Min ₹500): ");
    scanf("%d", &balance[count]);
    if (balance[count] < 500)
    {
        printf("Invalid Amount: Opening Balance must be at least 500.\n");
        return;
    }

    count++;
    printf("Congratulations! Account created successfully!\n");
}

// Function to deposit money
void deposit()
{
    if (count == 0)
    {
        printf("No account found. Please create an account first.\n");
        return;
    }

    int accId, i, found = 0, amount;
    printf("Enter your ID to deposit: ");
    scanf("%d", &accId);

    for (i = 0; i < count; i++)
    {
        if (id[i] == accId)
        {
            found = 1;
            printf("Enter amount to deposit (min 100): ");
            scanf("%d", &amount);
            if (amount >= 100)
            {
                balance[i] += amount;
                printf("Amount deposited successfully. New Balance: %d\n", balance[i]);
            }
            else
            {
                printf("Minimum deposit amount should be 100.\n");
            }
            break;
        }
    }

    if (!found)
    {
        printf("Invalid ID! Account not found.\n");
    }
}

// Function to withdraw money
void withdraw()
{
    if (count == 0)
    {
        printf("No account found. Please create an account first.\n");
        return;
    }

    int accId, i, found = 0; 
    int amount;
    printf("Enter your ID to withdraw: ");
    scanf("%d", &accId);

    for (i = 0; i < count; i++)
    {
        if (id[i] == accId)
        {
            found = 1;
            printf("Enter amount to withdraw: ");
            scanf("%d", &amount);
            if (amount > 0 && amount <= balance[i])
            {
                balance[i] -= amount;
                printf("Withdrawal successful. New Balance: %d\n", balance[i]);
            }
            else
            {
                printf("Invalid amount! Not enough balance or invalid input.\n");
            }
            break;
        }
    }

    if (!found)
    {
        printf("Invalid ID! Account not found.\n");
    }
}

// Function to check balance
void checkBalance()
{
    if (count == 0)
    {
        printf("No account found. Please create an account first.\n");
        return;
    }

    int accId, i, found = 0;
    printf("Enter your ID to check balance: ");
    scanf("%d", &accId);

    for (i = 0; i < count; i++)
    {
        if (id[i] == accId)
        {
            found = 1;
            printf("Your current balance is: %d\n", balance[i]);
            break;
        }
    }

    if (!found)
    {
        printf("Invalid ID! Account not found.\n");
    }
}

// Function to display full account details
void displayAccountDetails()
{
    if (count == 0)
    {
        printf("No account found. Please create an account first.\n");
        return;
    }

    int accId, i, found = 0;
    printf("Enter your ID to display details: ");
    scanf("%d", &accId);

    for (i = 0; i < count; i++)
    {
        if (id[i] == accId)
        {
            found = 1;
            printf("\n--- Account Details ---\n");
            printf("ID: %d\n", id[i]);
            printf("Name: %s\n", name[i]);
            printf("Father's Name: %s\n", father[i]);
            printf("Age: %d\n", age[i]);
            printf("Account Number: %lld\n", accountNo[i]);
            printf("Aadhar Number: %lld\n", aadharNo[i]);
            printf("Balance: ₹%d\n", balance[i]);
            break;
        }
    }

    if (!found)
    {
        printf("Invalid ID! Account not found.\n");
    }
}

// Function to handle invalid menu choice
void verifyTaskNo()
{
    printf("Invalid choice! Please enter a valid option from the menu.\n");
}
