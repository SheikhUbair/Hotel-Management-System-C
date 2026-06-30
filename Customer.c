#include<stdio.h>
struct Customer
{
    char cust_name[50];
    char cust_ID[10];
    char cust_Address[200];
    int cust_Room;
    int cust_NoOfPerson;
    char cust_Purpose[10];
    char cust_arrivalDATE[12];
};


int main()
{
struct Customer cust;
int male, fem, child;

printf("Enter the details of the Customer : \n");

printf("Customer Name : ");
fgets(cust.cust_name,sizeof(cust.cust_name),stdin);

printf("Enter the Customer ID : ");
fgets(cust.cust_ID,sizeof(cust.cust_ID),stdin);

printf("Enter the Customer Adress : ");
fgets(cust.cust_Address,sizeof(cust.cust_Address),stdin);

printf("Enter the Room assigned to Customer : ");
scanf(" %d",&cust.cust_Room);

while(1)
{
printf("Enter the no of Persons with the Customer : ");
scanf(" %d",&cust.cust_NoOfPerson);
printf("No of Male : ");
scanf(" %d",&male);
printf("No of Female : ");
scanf(" %d",&fem);
printf("No of Children : ");
scanf(" %d",&child);
getchar();
if( male + fem + child == cust.cust_NoOfPerson)
{
    break;
}
    printf("Error! Entered data does not match The no of Persons.\n");
}


printf("Enter the Purpose of visit of the Customer : ");
fgets(cust.cust_Purpose,sizeof(cust.cust_Purpose),stdin);

printf("Enter the Date of arrival of the Customer : ");
fgets(cust.cust_arrivalDATE,sizeof(cust.cust_arrivalDATE),stdin);

return 0;
}