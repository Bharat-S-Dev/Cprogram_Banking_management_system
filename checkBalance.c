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

void checkBalance();

int main()
{
    checkBalance();
    return 0;
}

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
