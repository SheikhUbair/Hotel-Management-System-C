#include<stdio.h>
#include"Customer.h"

void book_room();

void book_room()
{
    printf("\n-----------Choose Your choice of Room------------\n");
    while(1)
    {
    printf("1. Special Huts :- Price Rs4500\n");
    printf("2. Executive Rooms :- Price Rs3000\n");
    printf("3. Family Rooms :- Price Rs3500\n");
    printf("4. Delux Rooms :- Price Rs2000\n");
    }
}