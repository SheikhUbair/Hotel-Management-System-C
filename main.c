#include<stdio.h>
#include "Customer.h"
int main ()
{
    int choice;
printf("\n_____________________________________\n");
printf("        Hotel Management System        ");
printf("\n_____________________________________\n");

while(1)
{
    printf("\n1. Add Customer\n");
    printf("2. View all customers\n");
    printf("3. Search Customer\n");
    printf("4. Update Customer Details\n");
    printf("5. Delete a customer\n");
    printf("6. Book room\n");
    printf("7. View Room status\n");
    printf("8. Checkout Customer\n");
    printf("9. Generate Bill\n");
    printf("10. Exit\n");
    printf("Enter your Choice : ");
    scanf("%d",&choice);
    getchar();
    
    switch(choice)
    {
        case 1: 
        {
            add_Customer();
            break;
        }
        case 2:
        {
            view_cust();
            break;
        }
    }
}

}
