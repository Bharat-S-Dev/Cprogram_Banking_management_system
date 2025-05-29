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


void displayMenu();

int main() 
{
    displayMenu();
    return 0;
}

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
            case 1: createAccount();
            break;
            case 2: deposit();
            break;
            case 3: withdraw(); 
            break;
            case 4: checkBalance(); 
            break;
            case 5: displayAccountDetails(); 
            break;
            case 0: printf("Thank you for using our banking system!\n"); 
            break;
            default: verifyTaskNo();
        }

    } while (choice != 0);

    return 0;
}
