#include "header/template.h"
#include "admin.cpp"
#include "customer.cpp"
#include "lboy.cpp"
int main()
{
    int inp;
    do
    {
        clrscr();
       gotoxy(75,15);cout <<blue<<"*******************Welcome*******************" << endl;
       gotoxy(75,16);cout <<green<<"1)Admin" << endl;
        gotoxy(75,17);cout << "2)Customer" << endl;
        gotoxy(75,18);cout << "3)Laundry Boy" << endl;
        gotoxy(75,19);cout << "4)Exit" << endl;
        gotoxy(75,20);cout << "Enter any one of the choices: ";
        inp = input();
        switch (inp)
        {
        case 1:
        {
            loginadmin();
            break;
        }
        case 2:
        {
            logincustomer();
            break;
        }
        case 3:
        {
            loginlboy();
            break;
        }
        case 4:
        {
            gotoxy(75,21);cout << "Thanks for visiting .... :)"<<endl;
            break;
        }
        }
        gotoxy(75,27);ent
    } while (inp != 4);
}
