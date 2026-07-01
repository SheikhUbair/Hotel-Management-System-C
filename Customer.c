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
void addcust_file(struct Customer cust);
void view_cust(struct Customer cust);

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
 
addcust_file(cust);

return 0;
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

printf("Customer saved Successfully.");
}
void view_cust(struct Customer cust)
{
    struct Customer cust;

    FILE *fp;
    fp= fopen("Customer.dat", "rb");

    if(fp==NULL)
    {
        printf("Unable to open the File!");
        return;
    }
    while(fread(&cust, sizeof(struct Customer),1,fp)==1)
    {
        int count=1;
    printf("Name of Customer %d : %s\n",count,cust.cust_name);
    printf("ID of Customer %d : %s\n",count,cust.cust_ID);
    printf("Address of Customer %d : %s\n",count,cust.cust_Address);
    printf("Room assigned to customer %d : %d\n",count,cust.cust_Room);
    printf("No of Persons with Customer %d : %d\n",count,cust.cust_NoOfPerson);
    printf("Purpose of visit of Customer %d : %s\n",count,cust.cust_Purpose);
    printf("Arrival Date of Customer %d at the Hotel : %s\n",count,cust.cust_arrivalDATE);

    }
}