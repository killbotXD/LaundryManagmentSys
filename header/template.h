#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Users/admin.h"
#include "Others/scheduleItem.h"
#include "Users/lboy.h"
#include "Others/laundry.h"
#include "Users/customer.h"
#include <time.h>
#include <ostream>
namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 92,
        FG_BLUE     = 96,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}
Color::Modifier green(Color::FG_GREEN);
    Color::Modifier def(Color::FG_DEFAULT);
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier blueblack(Color::BG_BLUE);
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

#define ent                               \
    {                                     \
        cout << "press enter..." ; \
        getch();                          \
    }
void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}
void clrscr(void)
{
    system("cls");
}
int input()
{
    int i;
    do
    {
        int is;
        fflush(stdin);
        i = scanf("%d", &is);
        if (i < 1)
        {
            printf("please enter a valid value...\nEnter again :");
        }
        else
        {
            return is;
        }
    } while (i == 0);
    return 0;
}
char *inpPassword(int passleng)
{
    cout << "Enter your password : ";
    int n = 0;
    char *p = new char[203];
    char ch;
    while (n < passleng)
    {
        ch = getch();
       cout <<def<<"*";
        p[n] = ch;
        n++;
    }
    fflush(stdin);
    return p;
}
void is_firsttime_launch_admin()
{
    fstream file, fa;
    admin a;
    file.open("admins.dat", ios::in);
    if (file.fail())
    {
        cout << "creating default admin" << endl;
        fa.open("admins.dat", ios::out);
        fa.write((char *)&a, sizeof(admin));
        fa.close();
    }
    else
    {
        file.close();
    }
}
void is_firsttime_launch_lboy()
{
    fstream file, fb;
    lboy b;
    file.open("datab.txt", ios::in);
    if (file.fail())
    {
        fb.open("lboy.dat", ios::out);
        fb.write((char *)&b, sizeof(lboy));
        fb.close();
    }
    else
    {
        file.close();
    }
}
void is_firsttime_launch_customer()
{
    fstream file, fb;
    customer b;
    file.open("customer.dat", ios::in);
    if (file.fail())
    {
        fb.open("customer.dat", ios::out);
        fb.write((char *)&b, sizeof(customer));
        fb.close();
    }
    else
    {
        file.close();
    }
}
void viewSchedule_admin(string inpdayOfWeek)
{
    //limitation considering time and resources
    int items = 0;
    fstream fViewScheduleA;
    scheduleitem viewItemA;
    scheduleitem *listOfItems = new scheduleitem[10];
    fViewScheduleA.open("schedule.dat", ios::in);
    fViewScheduleA.seekg(0);
    clrscr();
    cout << "CURRENT SCHEDULE FOR " << inpdayOfWeek << " IS:" << endl;
    cout << "Address          - Laundry Boy Id" << endl;
    while ( fViewScheduleA.read((char *)&viewItemA, sizeof(viewItemA)))
    {
        if (fViewScheduleA.eof())
        {
            fViewScheduleA.close();
            break;
        }
       
        if (strcmp(viewItemA.dayOfWeek, inpdayOfWeek.c_str()) == 0 && items != 10)
        {
            listOfItems[items - 1] = viewItemA;
            gotoxy(0, items + 3);
            cout << viewItemA.add;
            gotoxy(19, items + 3);
            for (int i = 0; i < sizeof(viewItemA.lboyId) / sizeof(string); i++)
                cout << viewItemA.lboyId[i] << " ";
            cout << endl;
            items++;
        }
        else if (items == 10)
        {
            fViewScheduleA.close();
            break;
        }
    }
}
void viewSchedule_customer(string Hostel)
{
    fstream fViewScheduleC;
    scheduleitem viewItemC;
    fViewScheduleC.open("schedule.dat", ios::in);
    fViewScheduleC.seekg(0);
    clrscr();
    cout << "CURRENT SCHEDULE FOR " << Hostel << " HOSTEL IS:" << endl;
    while (!fViewScheduleC.eof())
    {
        if (fViewScheduleC.eof())
            break;
        fViewScheduleC.read((char *)&viewItemC, sizeof(viewItemC));
        if (strcmp(viewItemC.add, Hostel.c_str()) == 0)
            cout << viewItemC.dayOfWeek << endl;
    }
    ent
}
char itemsOfLList[9][10] = {"Shirt", "T-Shirt", "Jeans", "Trousers", "Bed Sheet", "Towel", "Suit", "Lower", "Shorts"};

void showSlip(laundry &templaundryitem)
{
    cout << "Item";
    gotoxy(15, 1);
    cout << "-";
    gotoxy(40, 1);
    cout << "Qty" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << itemsOfLList[i];
        gotoxy(15, i + 2);
        cout << "-";
        gotoxy(40, i + 2);
        cout << templaundryitem.lItemQty[i] << endl;
    }
}
void viewSchedule_lboy(string templboyId)
{
    fstream fViewScheduleL;
    scheduleitem viewItemL;
    fViewScheduleL.open("schedule.dat", ios::in);
    fViewScheduleL.seekg(0);
    cout << "CURRENT SCHEDULE FOR YOU IS:" << endl;
    cout << "Day     -   Address" << endl;
    while (!fViewScheduleL.eof())
    {
        if (fViewScheduleL.eof())
            break;
        fViewScheduleL.read((char *)&viewItemL, sizeof(viewItemL));
        for (int i = 0; i < sizeof(viewItemL.lboyId) / sizeof(string); i++)
            if (strcmp(viewItemL.lboyId[i], templboyId.c_str()) == 0)
                cout << viewItemL.dayOfWeek << "     " << viewItemL.add << endl;
    }
}
