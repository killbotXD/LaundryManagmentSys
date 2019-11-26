#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "admin.h"
#include "scheduleItem.h"
#include "lboy.h"
#include "laundry.h"
#include "customer.h"
#include <time.h> 
using namespace std;

#define ent {cout<<"press enter..."<<endl; getch();}
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
scheduleitem* viewSchedule_admin(string inpdayOfWeek){
    //limitation considering time and resources
    int items=0;
    fstream fViewScheduleA;
    scheduleitem viewItemA;
    scheduleitem listOfItems[10];
    fViewScheduleA.open("schedule.dat",ios::in);
    fViewScheduleA.seekg(0);
    clrscr();
    cout<<"CURRENT SCHEDULE FOR "<<inpdayOfWeek<<" IS:"<<endl;
    cout<<"Address          - Laundry Boy Id"<<endl;
    while(!fViewScheduleA.eof()){
        if(fViewScheduleA.eof()){fViewSchedule.close();break;}
        fViewScheduleA.read((char*)&viewItemA,sizeof(viewItemA));
        if(strcmp(viewItemA.dayOfWeek,inpdayOfWeek.c_str())==0&&items!=10){
            listOfItems[items-1]=viewItemA;
            gotoxy(0,items+2);cout<<viewItemA.add;
            gotoxy(19,items+2);for(int i=0;i<sizeof(viewItemA.lboyId)/sizeof(string);i++)cout<<viewItemA.lboyId[i]<<" ";
            items++;
        }
        else if(items==10){fViewSchedule.close();break;}
    }
retutn listOfItems;
    
}
void viewSchedule_customer(string Hostel){
    fstream fViewScheduleC;
    scheduleitem viewItemC;
    fViewScheduleC.open("schedule.dat",ios::in);
    fViewScheduleC.seekg(0);
    clrscr();
    cout<<"CURRENT SCHEDULE FOR YOUR HOSTEL IS:"<<endl;
    while(!fViewScheduleC.eof()){
        if(fViewScheduleC.eof())break;
        fViewScheduleC.read((char*)&viewItemC,sizeof(viewItemC));
        if(strcmp(viewItemC.add,Hostel.c_str())==0)cout<<viewItemC.dayOfWeek<<endl;
    }
ent
}
void viewSchedule_lboy(string templboyId){
    fstream fViewScheduleL;
    scheduleitem viewItemL;
    fViewScheduleL.open("schedule.dat",ios::in);
    fViewScheduleL.seekg(0);
    cout<<"CURRENT SCHEDULE FOR YOU IS:"<<endl;
    cout<<"Day     -   Address"<<endl;
    while(!fViewScheduleL.eof()){
        if(fViewScheduleL.eof())break;
        fViewScheduleL.read((char*)&viewItemL,sizeof(viewItemL));
        for(int i=0;i<sizeof(viewItemL.lboyId)/sizeof(string);i++)if(strcmp(viewItemL.lboyId[i],templboyId.c_str())==0)cout<<viewItemL.dayOfWeek<<"     "<<viewItemL.add<<endl;
        
    }

}
