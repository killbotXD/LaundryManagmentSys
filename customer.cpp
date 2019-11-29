
void showcustomerMenu(customer &b)
{
    fstream flaundry, fnewlaundry;

    int x;
    do
    {
        clrscr();
       cout <<blue<<"*****************CUSTOMER MENU************" << endl;
        printf("Enter choice...\n");
        cout<<green;
        printf("1)Display Schedule\n");
        printf("2)Mark Laundry Received\n");
        printf("3)Exit\n");
        cout << "Enter Any one of the choices: ";
        cout<<def;
        x = input();
        switch (x)
        {
        case 1:
        {
            ent
                string temphostel;
            cout << "Enter Hostel: \n";
            cin >> temphostel;
            if (scheduleExists())
            {
                viewSchedule_customer(temphostel);
            }
            else
            {
                cout << "Schedule Currently Not Available" << endl;
                ent
            }

            break;
        }
        case 2:
        {
            laundry templaundry;
            flaundry.open("laundry.dat", ios::in);
            fnewlaundry.open("temp.dat", ios::out);
            flaundry.seekg(0);
            fnewlaundry.seekg(0);
            while (!flaundry.eof())
            {
                if (flaundry.eof())
                    break;
                flaundry.read((char *)&templaundry, sizeof(templaundry));
                if (strcmp(templaundry.cusId, b.id) == 0)
                {
                    clrscr();
                    showSlip(templaundry);
                    ent

                            cout
                        << "Have you received the laundry";
                    string tempanswer;
                    cin >> tempanswer;
                    if (tempanswer == "Y" || tempanswer == "y")
                    {
                        templaundry.isReceived = 1;
                        fnewlaundry.write((char *)&templaundry, sizeof(templaundry));
                    }
                    else
                    {
                        fnewlaundry.write((char *)&templaundry, sizeof(templaundry));
                    }
                }
                else
                {
                    fnewlaundry.write((char *)&templaundry, sizeof(templaundry));
                }
            }

            // if(val1&&val2){cout<<"success";ent}
            flaundry.close();
            fnewlaundry.close();
            int val1 = remove("laundry.dat");
            int val2 = rename("temp.dat", "laundry.dat");
            ent break;
        }
        case 3:
        {
            exit(0);
            break;
        }
        }
    } while (x != 3);
}

void logincustomer()
{
    fstream fcustomer;
    customer b;
    string tempid,temppwd;
    is_firsttime_launch_customer();
     gotoxy(75,21);cout << "enter your ID: ";
    cin >> tempid;
    fcustomer.open("customer.dat", ios::in);
    fcustomer.seekg(0);
    while (!fcustomer.eof())
    {
        fcustomer.read((char *)&b, sizeof(b));
        if (strcmp(b.id, tempid.c_str()) == 0)
        {
            gotoxy(75,22); cout << "User Found!!" << endl;
            break;
        }
    }
    if (strcmp(b.id, tempid.c_str()) != 0)
    {
        gotoxy(75,22); cout << "User not Found!!" << endl;
        return;
    }
    fcustomer.close();
     gotoxy(75,23);temppwd = inpPassword(strlen(b.password));
    if (!temppwd.empty()) {
		temppwd.resize(strlen(b.password));
	}
    if (strcmp(b.password, temppwd.c_str()) == 0)
    {
       gotoxy(75,24);  cout << "Password match" ;
         gotoxy(75,25); cout    << "Welcome " << b.username << "!!" << endl;
         gotoxy(75,26);ent
            showcustomerMenu(b);
    }
    else
    {
         gotoxy(75,24);cout<< "PASSWORD DID NOT MATCH!!!   TRY AGAIN!!!" << endl;
    }
}