#ifndef CUSTOMER_H
#define CUSTOMER_H

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


void add_Customer();
void view_cust();
int roomOccupied(int room);
void Search_Customer();
void Update_Room();
void Delete_Customer();
void update_checkout();

#endif