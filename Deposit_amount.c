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

void deposit();

int main()
{
    deposit();
    return 0;
}

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
