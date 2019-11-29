int lboyExists(string id)
{
    fstream flboy;
    lboy b;
    is_firsttime_launch_lboy();
    flboy.open("lboy.dat", ios::in);
    flboy.seekg(0);
    while (!flboy.eof())
    {
        flboy.read((char *)&b, sizeof(b));
        //cout<<a.id<<" id "<<tempid<<endl;
        if (strcmp(b.id, id.c_str()) == 0)
        {
            flboy.close();
            return 1;
        }
    }
    flboy.close();
    return 0;
}
int customerExists(string id)
{
    fstream fcustomer;
    customer c;
    is_firsttime_launch_customer();
    fcustomer.open("customer.dat", ios::in);
    fcustomer.seekg(0);
    while (!fcustomer.eof())
    {
        fcustomer.read((char *)&c, sizeof(c));
        //cout<<a.id<<" id "<<tempid<<endl;
        if (strcmp(c.id, id.c_str()) == 0)
        {
            fcustomer.close();
            return 1;
        }
    }
    fcustomer.close();
    return 0;
}
int scheduleExists()
{
    fstream fsch;
    is_firsttime_launch_lboy();
    fsch.open("schedule.dat", ios::in);
    if (fsch.fail())
    {

        return 0;
    }
    else
    {
        fsch.close();
        return 1;
    }

    return 0;
}
char listOfDays[8][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday","Exit"};
void printScheduleMenu()
{

   cout <<blue<<"*****************Schedule*****************" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout <<green<< i + 1 << ")" << listOfDays[i] << endl;
    }
    //cout <<green<<"1)Monday"<<endl;
    // cout<<"2)Tuesday"<<endl;
    // cout<<"3)Wednesday"<<endl;
    // cout<<"4)Thursday"<<endl;
    // cout<<"5)Friday"<<endl;
    // cout<<"6)Saturday"<<endl;
    // cout<<"7)Sunday"<<endl;
    // cout<<"8)Exit"<<endl;
    cout << "Enter the day: " << endl;
}
void addlboy()
{
    is_firsttime_launch_lboy();
   cout <<blue<<"**************Sign UP**************" << endl;
    fstream fnewlboy;
    lboy newlboy;
    string temppwd, tmpusername, tmpid, temphostel, temproomnumber;
    cout << "Enter new Id: ";
    cin >> tmpid;
    fnewlboy.open("lboy.dat", ios::in);
    fnewlboy.seekg(0);
    while (!fnewlboy.eof())
    {
        fnewlboy.read((char *)&newlboy, sizeof(lboy));

        if (strcmp(newlboy.id, tmpid.c_str()) == 0)
        {
            cout << "Laundry Boy already exists... Try another Id!!" << endl;
            break;
        }
    }
    fnewlboy.close();
    if (strcmp(newlboy.id, tmpid.c_str()) != 0)
    {
        strcpy(newlboy.id, tmpid.c_str());
        cout << "Enter Username: ";
        cin >> tmpusername;
        strcpy(newlboy.username, tmpusername.c_str());
        cout << "Enter Password:";
        cin >> temppwd;
        strcpy(newlboy.password, temppwd.c_str());
        fnewlboy.open("lboy.dat", ios::out | ios::app);
        fnewlboy.write((char *)&newlboy, sizeof(lboy));
        fnewlboy.close();
        cout << "Registration Succesfull!!" << endl;
    }
}

void addScheduleItem()
{
    fstream faddSI;
    scheduleitem schItem;
    string tempDay, tempAdd, tempId;
    string tempLboyId[20];
    cout << "Enter Day: ";
    cin >> tempDay;
    cout << "Enter Hostel of the Scheduled Laundry: ";
    cin >> tempAdd;
    string answer = "yes";
    int i = 0;
    while (answer == "y" || answer == "yes" || answer == "Y" || answer == "YES"&&sizeof(tempLboyId)>0)
    {
        cout << "Enter Laundry Boy Id to Be assigned: ";
        cin >> tempId;
        if (lboyExists(tempId))
        {
            cout << "Added laundry boy" << endl;
            tempLboyId[i] = tempId;
            i++;
        }
        else
        {
            cout << "The Laundry boy does not exist!!!" << endl
                 << endl;
        }
        cout << "Do you want to add another laundry Boy?";
        cin >> answer;
    }

    cout << endl
         << "Confirm add Schedule Item?";
    cin >> answer;
    if (answer == "y" || answer == "yes" || answer == "Y" || answer == "YES")
    {
        strcpy(schItem.dayOfWeek, tempDay.c_str());
        for (i = 0; i < sizeof(tempLboyId) / sizeof(string); i++)
        {
            strcpy(schItem.lboyId[i], tempLboyId[i].c_str());
        }
        strcpy(schItem.add, tempAdd.c_str());
        faddSI.open("schedule.dat", ios::out | ios::app);
        faddSI.write((char *)&schItem, sizeof(schItem));
        faddSI.close();
    }
}
void editSingleItem(scheduleitem listOfItems[], int number)
{

    int inputHere;
    scheduleitem curr;
    curr.cpscheduleitem(listOfItems[number-2]);

t:
    clrscr();
    gotoxy(30, 0);
    cout << "Current Item Looks Like" << endl<<endl;
    cout << listOfItems[number-2].dayOfWeek << " " << listOfItems[number-2].add << endl;
    cout << "List of Laundry Boys Assigned:";
    for (int i = 0; i < sizeof(listOfItems[number-2].lboyId) / sizeof(string); i++)
    {
        cout << listOfItems[number-2].lboyId[i] << " ";
    }
    cout << endl
         << endl;
    cout << "What do you want to change?" << endl;
   cout <<green<<"1)Day" << endl;
    cout << "2)Address" << endl;
    cout << "3)list of laundry Boys" << endl;
    cout << "4)Confirm and Exit." << endl;
    cout << "5)Exit" << endl;
    inputHere = input();
    switch (inputHere)
    {
    case 1:
    {
        string newday;
        cout << "Enter the new Day: ";
        cin >> newday;
        strcpy(listOfItems[number-2].dayOfWeek, newday.c_str());
        break;
    }
    case 2:
    {
        cout << "Enter the new address: ";
        string newadd;
        cin >> newadd;
        strcpy(listOfItems[number-2].add, newadd.c_str());
        break;
    }
    case 3:
    {
        cout << "Enter Id laundry boy which you want to edit: ";
        string editId;
        cin >> editId;
        for (int i = 0; i < sizeof(listOfItems[number-2].lboyId) / sizeof(string); i++)
        {
            if (strcmp(editId.c_str(), listOfItems[number-2].lboyId[i]) == 0)
            {
                cout << "Enter the new Id(leave blank if you want to relieve the laundry boy): ";
                string newid;
                cin >> newid;
                strcpy(listOfItems[number-2].lboyId[i], newid.c_str());
            }
        }
        break;
    }
    case 4:
    {
        scheduleitem newScha;
        fstream fileEditSch;
        fstream fileOutSch;
        fileOutSch.open("temp2.dat", ios::out | ios::app);
        fileEditSch.open("schedule.dat", ios::in);
        fileEditSch.seekg(0);
        while (fileEditSch.read((char *)&newScha, sizeof(newScha)))
        {
            if (fileEditSch.eof())
                break;
            
            if (curr.match(newScha))
            {
                for (int i = 0; i < sizeof(*listOfItems) / sizeof(scheduleitem); i++)
                {
                    //cout<<listOfItems[i-1].add;ent
                    fileOutSch.write((char *)&listOfItems[i-1], sizeof(listOfItems[i-1]));
                }
            }
            else
            {
                fileOutSch.write((char *)&newScha, sizeof(newScha));
            }
        }
        fileOutSch.close();
        fileEditSch.close();
        remove("schedule.dat");
        rename("temp2.dat", "schedule.dat");
        cout << "Edit Sucesfull" << endl;
        break;
    }
    case 5:
    {
        break;
    }
    }
    if (inputHere != 4 && inputHere != 5)
        goto t;
}
void queryProcessor(string queryDayOfWeek){
    int editNo;
    scheduleitem *listOfItems = new scheduleitem[10];
              {
                int items = 0;
                fstream fViewScheduleA;
                scheduleitem viewItemA;
                fViewScheduleA.open("schedule.dat", ios::in);
                fViewScheduleA.seekg(0);
                clrscr();
                cout << "CURRENT SCHEDULE FOR " << queryDayOfWeek << " IS:" << endl;
                cout << "Address          - Laundry Boy Id" << endl;
                while (fViewScheduleA.read((char *)&viewItemA, sizeof(viewItemA)))
                {
                    if (fViewScheduleA.eof())
                    {
                        fViewScheduleA.close();
                        break;
                    }
                    if (strcmp(viewItemA.dayOfWeek, queryDayOfWeek.c_str()) == 0 && items != 10)
                    {
                        
                        listOfItems[items-1].cpscheduleitem(viewItemA);
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
                }if(items ==0){
                    cout<<"Empty!!!" ;
                    Sleep(1);
                    return;
                }
            }
            // listOfItems=viewSchedule_admin(queryDayOfWeek);
            // cout << listOfItems[0].add;
            // ent
                    cout
                << "enter the entry you want to edit: ";
            editNo = input();
            editSingleItem(listOfItems, editNo);
}
void editScheduleItem()
{
    int inpEdit, editNo;
    string queryDayOfWeek;

    scheduleitem *listOfItems = new scheduleitem[10];
    do
    {
        clrscr();
        printScheduleMenu();
        //cout<<"8)Exit"<<endl;
        inpEdit = input();
        switch (inpEdit)
        {
        case 1:
        {
            queryDayOfWeek = "Monday";
            queryProcessor(queryDayOfWeek);

            ent break;
        }
        case 2:
        {
            queryDayOfWeek = "Tuesday";
           queryProcessor(queryDayOfWeek);

            // listOfItems=viewSchedule_admin(queryDayOfWeek);
            cout << "enter the entry you want to edit: ";
            editNo = input();
            editSingleItem(listOfItems, editNo);
            ent break;
        }
        case 3:
        {
            queryDayOfWeek = "Wednesday";

             queryProcessor(queryDayOfWeek);
            //listOfItems=viewSchedule_admin(queryDayOfWeek);
            cout << "enter the entry you want to edit: ";
            editNo = input();
            editSingleItem(listOfItems, editNo);
            ent break;
        }
        case 4:
        {
            queryDayOfWeek = "Thursday";
           queryProcessor(queryDayOfWeek);
            //listOfItems=viewSchedule_admin(queryDayOfWeek);
            cout << "enter the entry you want to edit: ";
            editNo = input();
            editSingleItem(listOfItems, editNo);
            ent break;
        }
        case 5:
        {
            queryDayOfWeek = "Friday";
           queryProcessor(queryDayOfWeek);
            // listOfItems=viewSchedule_admin(queryDayOfWeek);
            cout << "enter the entry you want to edit: ";
            editNo = input();
            editSingleItem(listOfItems, editNo);
            ent break;
        }
        case 6:
        {
            queryDayOfWeek = "Saturday";
           queryProcessor(queryDayOfWeek);
            //listOfItems=viewSchedule_admin(queryDayOfWeek);
            cout << "enter the entry you want to edit: ";
            editNo = input();
            editSingleItem(listOfItems, editNo);
            ent break;
        }
        case 7:
        {
            queryDayOfWeek = "Sunday";
           queryProcessor(queryDayOfWeek);
            //listOfItems=viewSchedule_admin(queryDayOfWeek);
            cout << "enter the entry you want to edit: ";
            editNo = input();
            editSingleItem(listOfItems, editNo);
            ent break;
        }
        case 8:
        {
            cout << "Exit" << endl;
            return;
        }
        }
    } while (inpEdit != 8);
}

void updateScheduleMenu()
{
    int inpUpdateSchedule;
    do
    {
        clrscr();
       cout <<blue<<"***********************Update Schedule Menu***********************" << endl;
       cout <<green<<"1)Add Schedule Item" << endl;
        cout << "2)Edit Schedule Item" << endl;
        cout << "3)Exit" << endl;
        cout << "Choose an Option:";
        cin >> inpUpdateSchedule;
        switch (inpUpdateSchedule)
        {
        case 1:
        {
            cout << "Add";
            addScheduleItem();

            ent break;
        }
        case 2:
        {
            cout << "Edit" << endl;
            if (scheduleExists())
            {
                editScheduleItem();
            }
            else
            {
                cout << "Schedule Currently Not Available" << endl;
            }

            ent break;
        }
        case 3:
        {
            cout << "exit" << endl;

            break;
        }
        }
    } while (inpUpdateSchedule != 3);
}
void showAdminMenu()
{
    int inpadmin;
    do
    {
        clrscr();
       cout <<blue<<"*****************ADMIN MENU************" << endl;
       cout <<green<<"1)Update Schedule" << endl;
        cout << "2)Add New Admin" << endl;
        cout << "3)View Schedule" << endl;
        cout << "4)Register Laundry Personell" << endl;
        cout << "5)Exit" << endl;
        cout << "Enter any one of the choices: ";
        inpadmin = input();
        switch (inpadmin)
        {
        case 1:
        {
            updateScheduleMenu();

             break;
        }
        case 2:
        {
            clrscr();
           cout <<blue<<"**************Sign UP**************" << endl;
            fstream fnewadmin;
            admin newAdmin;
            string temppwd, tmpusername, tmpid, tmpmobile;
            cout << "Enter new Id: ";
            cin >> tmpid;
            fnewadmin.open("admins.dat", ios::in);
            fnewadmin.seekg(0);
            while (!fnewadmin.eof())
            {
                fnewadmin.read((char *)&newAdmin, sizeof(admin));

                if (strcmp(newAdmin.id, tmpid.c_str()) == 0)
                {
                    cout << "User already exists... Try another Id!!" << endl;
                    break;
                }
            }
            fnewadmin.close();
            if (strcmp(newAdmin.id, tmpid.c_str()) != 0)
            {
                strcpy(newAdmin.id, tmpid.c_str());
                cout << "Enter Username: ";
                cin >> tmpusername;
                strcpy(newAdmin.username, tmpusername.c_str());
                cout << "Enter Password:";
                cin >> temppwd;
                strcpy(newAdmin.password, temppwd.c_str());
                cout << "Enter Mobile number: ";
                cin >> tmpmobile;
                strcpy(newAdmin.mobile, tmpmobile.c_str());
                fnewadmin.open("admins.dat", ios::out | ios::app);
                fnewadmin.write((char *)&newAdmin, sizeof(admin));
                fnewadmin.close();
            }

            ent break;
        }
        case 3:
        {
            int querydayinp;
            clrscr();
            printScheduleMenu();
            //cout<<"8)Exit"<<endl;
            cin >> querydayinp;
            if(querydayinp!=8)
                viewSchedule_admin(listOfDays[querydayinp - 1]);
            cout << endl;
            ent break;
        }
        case 4:
        {
            addlboy();
            ent

                break;
        }

        case 5:
        {
            exit(0);
            return;
        }
        }
    } while (inpadmin != 5);
}
void loginadmin()
{
    fstream fadmin;
    admin a;
    string tempid, temppwd;
    is_firsttime_launch_admin();
    
    cout << green<<"enter your ID: ";
    cin >> tempid;
    fadmin.open("admins.dat", ios::in);
    fadmin.seekg(0);
    while (!fadmin.eof())
    {
        fadmin.read((char *)&a, sizeof(a));
        if (strcmp(a.id, tempid.c_str()) == 0)
        {
            cout << "User Found!!" << endl;
            break;
        }
    }
    if (strcmp(a.id, tempid.c_str()) != 0)
    {
        cout << "User not Found!!" << endl;
        return;
    }
    fadmin.close();

    temppwd = inpPassword(strlen(a.password));
    if (strcmp(a.password, temppwd.c_str()) == 0)
    {
        cout << "\nPassword match" << endl
             << "Welcome " << a.username << "!!" << endl;
        ent
        showAdminMenu();
    }
    else
    {
        cout << "password Incorrect Try again!!!" << endl;
    }
}