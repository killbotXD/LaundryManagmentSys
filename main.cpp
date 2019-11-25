#include "template.h"
#include "admin.cpp"
#include "customer.cpp"
#include "lboy.cpp"
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
                loginadmin();
                break;}
            case 2: {
                logincustomer();
                break;}
            case 3:{
                loginlboy();
                break;}
            case 4:{
                cout<<"Thanks for visiting .... :)";
                break;
            }
        }
    ent
    }while (inp!=4);
}
