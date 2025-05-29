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

void withdraw();

int main()
{
    withdraw();
    return 0;
}

void withdraw()
{
    if (count == 0)
    {
        printf("No account found. Please create an account first.\n");
        return;
    }

    int accId, i, found = 0, amount;
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
