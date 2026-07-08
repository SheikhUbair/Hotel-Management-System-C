#include<stdio.h>
#include "Customer.h"
#include <string.h>
#include "Room.h"


void addcust_file(struct Customer cust);
void view_cust();
void add_Customer();
int roomOccupied(int room);
void Search_Customer();
void Update_Room();
void Delete_Customer();
void update_checkout();


void add_Customer()
{
struct Customer cust;
int male, fem, child;

printf("\n----------Enter the details of the Customer-----------\n");

printf("Customer Name : ");
fgets(cust.cust_name,sizeof(cust.cust_name),stdin);
cust.cust_name[strcspn(cust.cust_name, "\n")]='\0';

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
    printf("\nID of Customer %d : %s",count,cust.cust_ID);
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

void Search_Customer()
{
    struct Customer cust;
    int search_room;
    int found = 0;

    printf("Enter the Room Number to be Searched : ");
    scanf("%d",&search_room);

    FILE *fp;
    fp=fopen("Customer.dat", "rb");

    if(fp==NULL)
    {
        printf("File unable to open !\n");
        return;
    }
    while(fread(&cust,sizeof(struct Customer),1,fp)==1)
    {
        if(cust.cust_Room==search_room)
        {
            printf("\nName of Customer : %s",cust.cust_name);
            printf("\nID of Customer : %s",cust.cust_ID);
            printf("Address of Customer : %s",cust.cust_Address);
            printf("Room assigned to Customer : %d\n",cust.cust_Room);
            printf("No. of persons with The Customer : %d\n",cust.cust_NoOfPerson);
            printf("Purpose of visit of Customer : %s",cust.cust_Purpose);
            printf("Arrival Date of the Customer : %s",cust.cust_arrivalDATE);
            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("Room not found !\n");
    }

    fclose(fp);

}

void Update_Room()
{
    struct Customer cust;
    int new_Room;
    int old_Room;
    int found=0;

    printf("Room no. to be Updated : ");
    scanf("%d",&old_Room);

    while(1)
    {
    printf("Room %d Updated to : ",old_Room);
    scanf("%d",&new_Room);
    if(roomOccupied(new_Room))
    {
        printf("Room already occupied ! Please choose another room\n");
    }
    else
    {
        break;
    }
    }

    FILE *fp;
    FILE *tp;

    fp=fopen("Customer.dat","rb");
    tp=fopen("temp.dat","wb");

    if(fp==NULL)
    {
        printf("Unable to open file ! \n");
        return;
    }
    else if(tp==NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    while(fread(&cust,sizeof(struct Customer),1,fp)==1)
    {
        if(cust.cust_Room!=old_Room)
        {
            fwrite(&cust, sizeof(struct Customer), 1, tp);
        }
        else if(cust.cust_Room==old_Room)
        {
            found=1;
            cust.cust_Room=new_Room;
            fwrite(&cust, sizeof(struct Customer),1,tp);
        }
    }
   
    fclose(fp);
    fclose(tp);

     if(found==0)
    {
        remove("temp.dat");
        printf("Room not found !\n");
    }
    else
    {
        remove("Customer.dat");
        rename("temp.dat", "Customer.dat");
        printf("Room updated Successfully!\n");
    }
}

void Delete_Customer()
{
    struct Customer cust;
    char dele_cust [50];
    int found=0;

    printf("Customer That needs to be deleted : ");
    fgets(dele_cust,sizeof(dele_cust),stdin);
    dele_cust[strcspn(dele_cust,"\n")]='\0'; // gets rid of newline
    
   
    FILE *fp;
    FILE *tp;

    fp=fopen("Customer.dat","rb");
    tp=fopen("temp.dat", "wb");
   

    if(fp==NULL)
    {
        printf("Unable to open file ! \n");
        return;
    }
    else if(tp==NULL)
    {
        printf("Unable to open file ! \n");
        return;
    }

    while(fread(&cust, sizeof(struct Customer),1,fp)==1)
    {
        
        if(strcmp(cust.cust_name,dele_cust)!=0)
        {
            fwrite(&cust, sizeof(struct Customer),1,tp);
        }
        else
        {
            found=1;
        }
    }

    fclose(fp);
    fclose(tp);

    if(found==0)
    {
        remove("temp.dat");
        printf("Customer not found!\n");
    }
    else
    {
        remove("Customer.dat");
        rename("temp.dat","Customer.dat");
        printf("Customer deleted Successfully!\n");
    }
}

    void update_checkout()
{
    struct Customer cust;
    struct Checkout checkout;

    int found=0;
    FILE *fp;
    FILE *tp;

    fp=fopen("Customer.dat","rb");
    tp=fopen("temp.dat", "wb");

    if(fp==NULL)
    {
        printf("Unable to open file ! \n");
        return;
    }
    else if(tp==NULL)
    {
        printf("Unable to open file ! \n");
        return;
    }

    while(fread(&cust, sizeof(struct Customer),1,fp)==1)
    {
        if(cust.cust_Room==checkout.room_no)
        {
            found=1;
        }
        else
        {
            fwrite(&cust, sizeof(struct Customer),1,tp);
        }
    }

    fclose(fp);
    fclose(tp);

    if(found==0)
    {
        remove("temp.dat");
        printf("Customer not found!\n");
    }
    else
    {
        remove("Customer.dat");
        rename("temp.dat","Customer.dat");
    }
}



