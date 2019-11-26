#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class customer: public user{
    public:
    char mobile[10];
    char hostel[2];
    char roomnumber[3];
    customer(){
        strcpy(id,"customer");
        strcpy(username,"customer");
        strcpy(password,"customer");
        strcpy(mobile,"0123456789");
        strcpy(hostel,"A0");
        strcpy(roomnumber,"000");
    }
};