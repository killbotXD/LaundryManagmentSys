#include<iostream>
#include<fstream>
//#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include "admin.h"
#include "scheduleItem.h"
#include "lboy.h"
#include "laundry.h"
#include "customer.h"
using namespace std;

#define ent {cout<<"press enter..."<<endl; getchar();}
void gotoxy(int x,int y)	
{
	printf("%c[%d;%df",0x1B,y,x);
}
void clrscr(void)
{
	system("cls");
}
int input(){
int i;
do{
int is;      
fflush(stdin);
i=scanf("%d",&is);
if(i<1)
{
    printf("please enter a valid value...\nEnter again :");
}
else
{
    return is;
}
}while(i==0);
   return 0;
}
void is_firsttime_launch_admin(){
    fstream file,fa;
    admin a;
    file.open("admins.dat",ios::in);
    if(file.fail()){
        cout<<"creating default admin"<<endl;
        fa.open("admins.dat",ios::out);
        fa.write((char*)&a,sizeof(admin));
        fa.close();
    }
    else
    {
        file.close();
    }
    
}
void is_firsttime_launch_lboy(){
    fstream file,fb;
    lboy b;
    file.open("datab.txt",ios::in);
    if(file.fail()){
        fb.open("lboy.dat",ios::out);
        fb.write((char*)&b,sizeof(lboy));
        fb.close();
    }else{
        file.close();
    }
}
void is_firsttime_launch_customer(){
    fstream file,fb;
    customer b;
    file.open("customer.dat",ios::in);
    if(file.fail()){
        fb.open("customer.dat",ios::out);
        fb.write((char*)&b,sizeof(customer));
        fb.close();
    }else{
        file.close();
    }
}

