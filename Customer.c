#include<stdio.h>
#include "Customer.h"


void addcust_file(struct Customer cust);
void view_cust();
void add_Customer();
int roomOccupied(int room);



void add_Customer()
{
struct Customer cust;
int male, fem, child;

printf("\n----------Enter the details of the Customer-----------\n");

printf("Customer Name : ");
fgets(cust.cust_name,sizeof(cust.cust_name),stdin);

printf("Enter the Customer ID : ");
fgets(cust.cust_ID,sizeof(cust.cust_ID),stdin);

printf("Enter the Customer Adress : ");
fgets(cust.cust_Address,sizeof(cust.cust_Address),stdin);

while(1)
{
printf("Enter the Room assigned to Customer : ");
scanf(" %d",&cust.cust_Room);

if(roomOccupied(cust.cust_Room))
{
    printf("Room is already occupied ! Please choose another Room\n");
}
else
{
    break;
}
}

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

addcust_file(cust);
 
}
void addcust_file(struct Customer cust)
{
    FILE *fp; 

fp = fopen("Customer.dat", "ab");

if(fp==NULL)
{
    printf("Unable to open file!\n");
    return;
}
fwrite(&cust, sizeof(struct Customer), 1, fp);

fclose(fp);

printf("Customer saved Successfully.\n");
}
void view_cust()
{
    struct Customer cust;

    FILE *fp;
    fp= fopen("Customer.dat", "rb");

    if(fp==NULL)
    {
        printf("Unable to open the File!");
        return;
    }
      int count=1;
    while(fread(&cust, sizeof(struct Customer),1,fp)==1)
    {
    printf("\n---------------Details of Customer %d------------------\n",count);
    printf("Name of Customer %d : %s",count,cust.cust_name);
    printf("ID of Customer %d : %s",count,cust.cust_ID);
    printf("Address of Customer %d : %s",count,cust.cust_Address);
    printf("Room assigned to customer %d : %d\n",count,cust.cust_Room);
    printf("No of Persons with Customer %d : %d\n",count,cust.cust_NoOfPerson);
    printf("Purpose of visit of Customer %d : %s",count,cust.cust_Purpose);
    printf("Arrival Date of Customer %d at the Hotel : %s",count,cust.cust_arrivalDATE);
    printf("\n");
    count++;
    }
    fclose(fp);
}

int roomOccupied(int room)
{
    struct Customer cust;

    FILE *fp;
    fp=fopen("Customer.dat", "rb");

    if(fp==NULL)
    {
        return 0;
    }
    while(fread(&cust,sizeof(struct Customer),1,fp)==1)
    {
        if(cust.cust_Room==room)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}