#include <fstream>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include "Admin.h"

using namespace std;

Admin a;

#define ent {cout<<"press enter..."<<endl; getch();}
#define fr(a) f.read((char*)&a,sizeof(a))
#define skg  f.seekg(0)
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