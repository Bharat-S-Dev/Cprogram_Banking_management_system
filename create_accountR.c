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

void createAccount();

int main()
{
    createAccount();
    return 0;
}

void createAccount()
{
    if (count >=5)
    {
        printf("Maximum Account limit(5) Reached.\n");
        return;
    }
    printf("\n Creating Account %d\n",count +1);
    id[count] = count + 123; //auto generated
    printf("Generated Id: %d\n", id[count]);

    printf("Enter Name: ");
    scanf(" %[^\n]", name[count]);

    printf("Enter Father's Name: ");
    scanf(" %[^\n]", father[count]);

    printf("enter age: ");
    while(scanf("%d", &age[count]) !=1)
    {
        printf("Invalid Input, Please Enter Numeric age: ");
        while(getchar() != '\n');
    }

    //Account number validation
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


    // Aadhar number validation
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
                printf("Invalid! Aadhar Number must be exactly 12 digits.\n");
            }
        }
        else
        {
            printf("Invalid input! Please enter only numbers.\n");
            while (getchar() != '\n');
        }
    }
    printf("Enter Opening Balance(Min 500): ");
    scanf("%d", &balance[count]);
    if(balance[count] < 500)
    {
        printf("Error: Opening Balance must be at least 500. \n");
        return;
    }
    count ++;
    printf("congratulations! Account created successfully\n");
}