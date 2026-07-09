#ifndef ROOM_H
#define ROOM_H

struct Checkout
{
    char cust_name[50];
    char cust_address[100];
    char cust_purpose[50];
    int cust_noofpersons;
    char arrival_date[12];
    int room_no;
    char checkout_date [12];
    int days;
    char room[10];
    int price;
    int total;
    float G_total;
    float GST;
 };

void view_room();
void Hut_room();
void Exe_room();
void Family_room();
void Delux_room ();
void checkout_cust();
void checkout_file();
void read_checkout();
void view_bills();


#endif