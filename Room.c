#include<stdio.h>
#include<string.h>
#include"Customer.h"
#include"Room.h"

struct Customer cust;
struct Checkout checkout;

void view_room();
void Hut_room();
void Exe_room();
void Family_room();
void Delux_room();
void checkout_cust();
void checkout_file();
void read_checkout();
void view_bills();

void view_room()
{
    int choice;
    printf("\n-----------Choose Your Room------------\n");
    while(1)
    {
    printf("1. Special Huts :\n");
    printf("2. Executive Rooms :\n");
    printf("3. Family Rooms :\n");
    printf("4. Delux Rooms :\n");
    printf("5. Exit\n");
    printf("Enter Your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        {
            Hut_room();
            break;
        }
        case 2:
        {
            Exe_room();
            break;
        }
        case 3:
        {
            Family_room();
            break;
        }
        case 4:
        {
            Delux_room();
            break;
        }
        case 5:
        {
            printf("Exiting!!!\n");
            return;
        }
        default:
        {
            printf("Invalid Choice! Please choose the correct option!!\n");
            break;
        }

    }
    }
}

void Hut_room()
{
    int choose;

    printf("The Room No. of Specail Huts is from 101 to 108 \n");
    
    while(1)
    {
    printf("Please Enter Your Choice (Enter 0 to go back) : ");
    scanf("%d",&choose);

    if(choose==0)
    {
        return;
    }
    else if(choose<101 || choose>108)
    {
        printf("Please Enter the correct Room No.!!!!\n");
    }
    else if(roomOccupied(choose))
    {
        printf("The Room is already Occupied. Please choose another Room !\n");
    }
    else
    {
        printf("Room is Avaliable!\n");
        break;
    }
    }
}

void Exe_room()
{
    int choose;

    printf("The Room No. of Executive Rooms is from 201 to 204 \n");

    while(1)
    {
        printf("Please Enter Your Choice (Enter 0 to go back) : ");
        scanf("%d",&choose);

        if(choose==0)
        {
            return;
        }
        else if(choose<201 || choose>204)
        {
            printf("Please Enter the Correct Room No.!\n");
        }
        else if(roomOccupied(choose))
        {
            printf("The Room is already Occupied ! Please choose another Room !\n");
        }
        else
        {
            printf("Room is Avaliable!\n");
            break;
        }
    }
}

void Family_room()
{
    int choose;

    printf("The Room No. of Family Rooms is from 301 to 303  \n");

    while(1)
    {
        printf("Please Enter Your Choice (Enter 0 to go back) : ");
        scanf("%d",&choose);

        if(choose==0)
        {
            return;
        }
        else if(choose<301 || choose>303)
        {
            printf("Please Enter the correct Room No.!!\n");
        }
        else if(roomOccupied(choose))
        {
            printf("The Room is already Occupied ! Please Choose another room ! \n");
        }
        else
        {
            printf("Room is Avaliable!\n");
            break;
        }
    }
}

void Delux_room()
{
    int choose;

    printf("The Room No. of Delux Rooms is from 401 to 404 \n");

    while(1)
    {
        printf("Please Enter Your Choice (Enter 0 to go back) : ");
        scanf("%d",&choose);

        if(choose==0)
        {
            return;
        }
        else if(choose<401 || choose>404)
        {
            printf("Please enter the Correct Room No.!!\n");
        }
        else if(roomOccupied(choose))
        {
            printf("The Room is already Occupied ! Please choose another Room ! \n");
        }
        else 
        {
            printf("Room is Avaliable!\n");
            break;
        }
    }
}

void checkout_cust()
{
    int found=0;

     
    printf("Enter the Room no in which the Customer stayed in : ");
    scanf("%d",&checkout.room_no);

    FILE *fp;

    fp=fopen("Customer.dat","rb");

    if(fp==NULL)
    {
        printf("File was Unable to open!");
        return;
    }
    while(fread(&cust, sizeof(struct Customer),1,fp))
    {
        if(cust.cust_Room==checkout.room_no)
        {
            strcpy(checkout.cust_name,cust.cust_name);
            strcpy(checkout.cust_address,cust.cust_Address);
            strcpy(checkout.cust_purpose,cust.cust_Purpose);
            strcpy(checkout.arrival_date,cust.cust_arrivalDATE);
            checkout.cust_noofpersons=cust.cust_NoOfPerson;
            checkout.room_no=cust.cust_Room;

            found=1;
            break;
        }
    }
    if(found==0)
    {
        fclose(fp);
        printf("Customer was not found!\n");
        return;
    }
    fclose(fp);

    getchar();
    printf("Enter the Date of Checkout : ");
    fgets(checkout.checkout_date,sizeof(checkout.checkout_date),stdin);
    

    printf("Enter the no of days Till the Customer stayed in the hotel : ");
    scanf("%d", &checkout.days);
    getchar();

    printf("Enter which Category Room did the Customer select : ");
    fgets(checkout.room,sizeof(checkout.room),stdin);
    checkout.room[strcspn(checkout.room, "\n")] = '\0';

    printf("Enter the Price of the %s Rooms : ",checkout.room);
    scanf("%d", &checkout.price);
    getchar();

    checkout.total=checkout.price*checkout.days;

    printf("Total Amount to be Paid without GST : %d\n",checkout.total);

    checkout.GST=checkout.total*5/100;
    checkout.G_total=checkout.total+checkout.GST;

    printf("G.Total after 5 percent GST : %.2f\n",checkout.G_total);

    checkout_file();

    read_checkout();

    update_checkout(checkout.room_no);
}

void checkout_file()
{
    FILE *fp;

    fp=fopen("Checkout.dat", "ab");

    if(fp==NULL)
    {
        printf("File unable to open !");
        return;
    }
    fwrite(&checkout,sizeof(struct Checkout),1,fp);

    fclose(fp);

    printf("Customer checked out Successfully!!!\n");

}

void read_checkout()
{

        printf("\n-------------Generated BILL of Customer-------------\n");
        printf("Name of Customer : %s\n",checkout.cust_name);
        printf("Address of Customer : %s",checkout.cust_address);
        printf("Purpose of visit : %s",checkout.cust_purpose);
        printf("No of Persons with the Customer : %d\n",checkout.cust_noofpersons);
        printf("Category of Room Selected by the Customer : %s\n",checkout.room);
        printf("Room no assigned to the Customer : %d\n",checkout.room_no);
        printf("Date of Arrival at the hotel : %s",checkout.arrival_date);
        printf("No of days Stayed at the hotel : %d\n",checkout.days);
        printf("Date of Checkout : %s",checkout.checkout_date);
        printf("Price of %s Room per night : %d\n",checkout.room,checkout.price);
        printf("Total Amount to be paid without GST : %d\n",checkout.total);
        printf("G.Total After 5 percent GST : %.2f\n",checkout.G_total);
        printf("\n");
        
}

void view_bills()
{
    int count=1;
    FILE *fp;

    fp=fopen("Checkout.dat", "rb");

    if(fp==NULL)
    {
        printf("File Unable to open!\n");
        return;
    }

    while(fread(&checkout ,sizeof(struct Checkout),1,fp)==1)
    {
        printf("\n-------------Generated BILL of Customer %d-------------\n",count);
        printf("Name of Customer %d : %s\n",count,checkout.cust_name);
        printf("Address of Customer %d : %s",count,checkout.cust_address);
        printf("Purpose of visit of Customer %d : %s",count,checkout.cust_purpose);
        printf("No of Persons with the Customer %d : %d\n",count,checkout.cust_noofpersons);
        printf("Category of Room Selected by the Customer %d : %s\n",count,checkout.room);
        printf("Room no assigned to the Customer %d : %d\n",count,checkout.room_no);
        printf("Date of Arrival at the hotel  : %s",checkout.arrival_date);
        printf("No of days Stayed at the hotel  : %d\n",checkout.days);
        printf("Date of Checkout : %s",checkout.checkout_date);
        printf("Price of %s Room per night : %d\n",checkout.room,checkout.price);
        printf("Total Amount to be paid without GST : %d\n",checkout.total);
        printf("G.Total After 5 percent GST : %.2f\n",checkout.G_total);
        printf("\n");
        count++;
    }
}
