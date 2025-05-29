#include <stdio.h>
#include <string.h>

int choice;
int id[5];
char name[5][30];
char father[5][30];
int age[5];
long long int accountNo[5];
long long int aadharNo[5];
int balance[5] = {500}; // Set initial balance to 500 for all accounts
int count = 0;

void displayAccountDetails();

int main()
{
    displayAccountDetails();
    return 0;
}

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
            printf("Account No: %lld\n", accountNo[i]);
            printf("Aadhar No: %lld\n", aadharNo[i]);
            printf("Balance: %d\n", balance[i]);
            break;
        }
    }

    if (!found)
    {
        printf("Invalid ID! Account not found.\n");
    }
}

// Don't forget to declare these functions at the top of your file:
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void displayAccountDetails();
void verifyTaskNo();
void displayMenu();
