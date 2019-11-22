#include <fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h>

using namespace std;

 

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


int main()
{
    fstream f;
     int x,y;
    // travel t;
do{
clrscr();
system("color 3");
gotoxy(4,4);printf("**********************Welcome**********************\n");
//system("color 4");
printf("Enter your type...\n");
printf("1)ADMIN\n");
printf("2)LAUNDRY BOY\n");
printf("3)CUSTOMER\n");
printf("4)EXIT\n");
x=input();
switch(x){
    case 1: //ADMIN
            printf("\n");
            printf("Are you a new User?\n");
            x=input();
            switch(x){
                clrscr();
                case 1: printf("Sign up");
                //enter code here
                case 0: printf("Login");
                //enter code here
            }
    case 2: //Laundry BOY
            printf("Enter choice...\n");
            printf("1)Display Schedule\n");
            printf("2)Add Laundry\n");
            printf("3)Update Profile\n");
            printf("4)Exit\n");
            x=input();
            switch(x){
                case 1: printf("Present Schedule is as follows :");
                //Enter code here
                case 2: printf("Enter choice...\n");
                        printf("1)Add Item\n");
                        printf("2)Exit \n");
                        y=input();
                        switch(y){
                            case 1: printf("Choose Item to added\n");
                                    printf("1)Shrit\n"); 
                                    printf("2)T-Shrit\n");
                                    printf("3)Jeans\n");
                                    printf("4)Trouser\n");
                                    printf("5)Bed sheet\n");
                                    printf("6)Towel\n");
                                    printf("7)Suit\n");
                                    printf("8)Lower\n");
                                    printf("9)Shorts\n");
                                    printf("10)Exit\n");
                                    int z=input();
                                    switch(z){
                                        case 1:
                                        case 2:
                                        case 3:
                                        case 4:
                                        case 5:
                                        case 6:
                                        case 7:
                                        case 8:
                                        case 9:printf("Enter quantity to be added\n");
                                      int  q=input();
                                        printf("%d items of type %d added to laundry",q,z);
                                        printf("Do you want to add more?\n");
                                      int  ch=input();
                                        if(ch==1)
                                        //should go back to outer switch...I don't know how :(
                                        if(ch==0)
                                        break;
                                    }break;
                                
                                }   
                            
                        
                case 3: printf("Update");
                //Enter code here
                case 4: break;
            }
            
    case 3: //CUSTOMER
    default: printf("Thanks for visiting");


}//switch
}while(x!=4);//do


}
