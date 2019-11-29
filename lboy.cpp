void addCustomer()
{
    is_firsttime_launch_customer();
   cout <<blue<<"**************Sign UP**************" << endl;
    fstream fnewcustomer;
    customer newcustomer;
    string temppwd, tmpusername, tmpid, temphostel, temproomnumber;
    cout << "Enter new Id: ";
    cin >> tmpid;
    fnewcustomer.open("customer.dat", ios::in);
    fnewcustomer.seekg(0);
    while (!fnewcustomer.eof())
    {
        fnewcustomer.read((char *)&newcustomer, sizeof(customer));

        if (strcmp(newcustomer.id, tmpid.c_str()) == 0)
        {
            cout << "Customer already exists... Try another Id!!" << endl;
            break;
        }
    }
    fnewcustomer.close();
    if (strcmp(newcustomer.id, tmpid.c_str()) != 0)
    {
        strcpy(newcustomer.id, tmpid.c_str());
        cout << "Enter Username: ";
        cin >> tmpusername;
        strcpy(newcustomer.username, tmpusername.c_str());
        cout << "Enter Password:";
        cin >> temppwd;
        strcpy(newcustomer.password, temppwd.c_str());
        cout << "Enter Hostel: ";
        cin >> temphostel;
        strcpy(newcustomer.hostel, temphostel.c_str());
        cout << "Enter Room Number: ";
        cin >> temproomnumber;
        strcpy(newcustomer.roomnumber, temproomnumber.c_str());
        fnewcustomer.open("customer.dat", ios::out | ios::app);
        fnewcustomer.write((char *)&newcustomer, sizeof(customer));
        fnewcustomer.close();
    }
}

void addItem(laundry &launItem)
{
//laundry launItem;
t:
    clrscr();

    printf("Choose Item to be added\n");
    printf("1)Shrit\n");
    printf("2)T-Shrit\n");
    printf("3)Jeans\n");
    printf("4)Trouser\n");
    printf("5)Bed sheet\n");
    printf("6)Towel\n");
    printf("7)Suit\n");
    printf("8)Lower\n");
    printf("9)Shorts\n");
    cout << "10)none" << endl;
    int z = input();
    int quan;
    cout << "Enter the Quantity to be added" << endl;
    cin >> quan;

    if (z != 10)
        launItem.lItemQty[z - 1] = quan;
    cout << "do you want to add again?";
    char ans;
    cin >> ans;
    //cout<<launItem.lItemQty[z];
    if (ans == 'y' || ans == 'Y')
        goto t;
}

void deleteItem(laundry &launItem)
{
//laundry launItem;
t:
    clrscr();

    printf("Choose Item to be deleted\n");
    printf("1)Shrit\n");
    printf("2)T-Shrit\n");
    printf("3)Jeans\n");
    printf("4)Trouser\n");
    printf("5)Bed sheet\n");
    printf("6)Towel\n");
    printf("7)Suit\n");
    printf("8)Lower\n");
    printf("9)Shorts\n");
    cout << "10)none" << endl;
    int z = input();
    if (z != 10)
        launItem.lItemQty[z - 1] = 0;
    cout << "do you want to delete more?";
    char ans;
    cin >> ans;
    //cout<<launItem.lItemQty[z];
    if (ans == 'y' || ans == 'Y')
        goto t;
}

void editItem(laundry &launItem)
{
//laundry launItem;
t:
    clrscr();
    printf("Choose Item whose quantity is to be changed\n");
    printf("1)Shrit\n");
    printf("2)T-Shrit\n");
    printf("3)Jeans\n");
    printf("4)Trouser\n");
    printf("5)Bed sheet\n");
    printf("6)Towel\n");
    printf("7)Suit\n");
    printf("8)Lower\n");
    printf("9)Shorts\n");
    cout << "10)none" << endl;
    int z = input();
    int newQuan;
    cout << "Enter the new quantity to be added";
    cin >> newQuan;
    if (z != 10)
        launItem.lItemQty[z - 1] = newQuan;
    cout << "do you want to edit more?";
    char ans;
    cin >> ans;
    if (ans == 'y' || ans == 'Y')
        goto t;
}

int placeLaundry(laundry &launItem)
{
    fstream fplaceLaundry;
    int success = 0;
    cout << "Are you sure you want to place laundry?";
    string sure;
    cin >> sure;
    if (sure == "y" || sure == "yes" || sure == "YES" || sure == "Y")
    {
        laundry rec;
        rec.isPlaced = 1;
        success = 1;
    }
    time_t curtime;
    time(&curtime);
    strcpy(launItem.curTime, ctime(&curtime));
    fplaceLaundry.open("laundry.dat", ios::out | ios::app);

    fplaceLaundry.write((char *)&launItem, sizeof(launItem));
    fplaceLaundry.close();
    return success;
}

void showlboyMenu(lboy &b)
{
    int x;
    laundry *launItem = new laundry;
    for (int i = 0; i < 10; i++)
        launItem->lItemQty[i] = 0;
    strcpy(launItem->lboyId, b.id);
    do
    {
        clrscr();
       cout <<blue<<"*****************LAUNDRY MENU************" << endl;
        printf("Enter choice...\n");
        printf("1)Display Schedule\n");
        printf("2)Add Laundry\n");
        //printf("3)Update Profile\n");
        cout << "3)Register Customer" << endl;
        printf("4)Exit\n");
        cout << "Enter Any one of the choices: ";
        x = input();
        switch (x)
        {
        case 1:
        {
            if (scheduleExists())
            {
                viewSchedule_lboy(b.id);
            }
            else
            {
                cout << "Schedule Currently Not Available" << endl;
            }
            ent break;
        }

        case 2:
        {
            cout << "Enter your customer ID: ";
            string tempCusId;
            cin >> tempCusId;
            if (customerExists(tempCusId))
            {
                strcpy(launItem->cusId, tempCusId.c_str());
            }
            else
            {
                cout << "Customer does not exist." << endl;
                ent break;
            }

            int y;
            do
            {
                clrscr();
                printf("Current laundry slip contains\n");
                showSlip(*launItem);
                cout << "what do you want to do?" << endl;
                printf("1)Add Items\n");
                cout << "2)Edit Item" << endl;
                cout << "3)Delete Item" << endl;
                cout << "4)Place laundry" << endl;
                printf("5)Exit \n");
                cout << "Enter any one of the choices: ";
                y = input();
                switch (y)
                {
                case 1:
                {
                    addItem(*launItem);
                    break;
                }
                case 2:
                {
                    if (sizeof(launItem) > 0)
                        editItem(*launItem);
                    else
                    {
                        cout << "Empty Slip" << endl;
                        ent
                    }
                    break;
                }
                case 3:
                {
                    if (sizeof(launItem) > 0)
                        deleteItem(*launItem);
                    else
                    {
                        cout << "Empty Slip" << endl;
                        ent
                    }

                    break;
                }
                case 4:
                {
                    int succ = placeLaundry(*launItem);
                    if (succ == 0)
                    {
                        cout << "Failure" << endl;
                        ent
                    }

                    else
                    {
                        cout << "Laundry placed successfully" << endl;
                        ent
                    }

                    break;
                }
                case 5:
                {
                    cout << "exit";
                    break;
                }
                }
            } while (y != 5 && y != 4);
            break;
        }
        case 3:
        {
            printf("Add customer\n");
            addCustomer();
            ent break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        }
    } while (x != 4);
}
void loginlboy()
{
    fstream flboy;
    lboy b;
    string tempid, temppwd;
    is_firsttime_launch_lboy();
    cout << "enter your ID: ";
    cin >> tempid;
    flboy.open("lboy.dat", ios::in);
    flboy.seekg(0);
    while (!flboy.eof())
    {
        flboy.read((char *)&b, sizeof(b));
        if (strcmp(b.id, tempid.c_str()) == 0)
        {
            cout << "User Found!!" << endl;
            break;
        }
    }
    if (strcmp(b.id, tempid.c_str()) != 0)
    {
        cout << "User not Found!!" << endl;
        return;
    }
    flboy.close();
    temppwd = inpPassword(strlen(b.password));
    if (strcmp(b.password, temppwd.c_str()) == 0)
    {
        cout << "\nPassword match" << endl
             << "Welcome " << b.username << "!!" << endl;
        ent
            showlboyMenu(b);
    }
    else
    {
        cout << "\nPASSWORD DID NOT MATCH!!!   TRY AGAIN!!!" << endl;
        ent
    }
}
