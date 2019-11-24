#include "template.h"

int main(){
    int inp;
    do{
        clrscr();
        cout<<"*******************Welcome*******************"<<endl;
        cout<<"1)Admin"<<endl;
        cout<<"2)Customer"<<endl;
        cout<<"3)Laundry Boy"<<endl;
        cout<<"4)Exit"<<endl;
        cout<<"Enter any one of the choices: ";
        inp=input();
        switch(inp){
            case 1:{
                cout<<"admin";
                break;}
            case 2: {
                cout<<"customer";
                break;}
            case 3:{
                cout<<"Laundry Boy";
                break;}

        }

    ent
    }while (inp!=4);
    

}