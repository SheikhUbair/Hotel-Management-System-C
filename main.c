#include <stdio.h>
#include "Customer.h"
#include "Room.h"
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
    printf("4. Update Room \n");
    printf("5. Delete a customer\n");
    printf("6. View Room status\n");
    printf("7. Checkout Customer\n");
    printf("8. View all Bills\n");
    printf("9. Exit\n");
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
        case 3:
        {
            Search_Customer();
            break;
        }
        case 4:
        {
            Update_Room();
            break;
        }
        case 5:
        {
            Delete_Customer();
            break;
        }
        case 6:
        {
            view_room();
            break;
        }
        case 7:
        {
            checkout_cust();
            break;
        }
        case 8:
        {
            view_bills();
            break;
        }
        case 9:
        {
            printf("Exiting Hotel Management System !\n");
            return 0;
        }
        default:
        {
            printf("Please choose the correct Option!!!!\n");
            break;
        }
    }
}

}
