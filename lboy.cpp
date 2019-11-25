void addCustomer(){
    is_firsttime_launch_customer();
                cout<<"**************Sign UP**************"<<endl;
                fstream fnewcustomer;
                customer newcustomer;
                string temppwd,tmpusername,tmpid, temphostel, temproomnumber;
                cout<<"Enter new Id: ";
                cin>>tmpid;
                fnewcustomer.open("customer.dat",ios::in);
                fnewcustomer.seekg(0);
                while(!fnewcustomer.eof()){
                    fnewcustomer.read((char*)&newcustomer,sizeof(customer));

                    if(strcmp(newcustomer.id,tmpid.c_str())==0){cout<<"Customer already exists... Try another Id!!"<<endl;
                    break;}

                }
                fnewcustomer.close();
                if(strcmp(newcustomer.id,tmpid.c_str())!=0){
                    strcpy(newcustomer.id,tmpid.c_str());
                    cout<<"Enter Username: ";
                    cin>>tmpusername;
                    strcpy(newcustomer.username,tmpusername.c_str());
                    cout<<"Enter Password:";
                    cin>>temppwd;
                    strcpy(newcustomer.password,temppwd.c_str());
                    cout<<"Enter Hostel: ";
                    cin>>temphostel;
                    strcpy(newcustomer.hostel,temphostel.c_str());
                    cout<<"Enter Room Number: ";
                    cin>>temproomnumber;
                    strcpy(newcustomer.roomnumber,temproomnumber.c_str());
                    fnewcustomer.open("customer.dat",ios::out|ios::app);
                    fnewcustomer.write((char*)&newcustomer,sizeof(customer));
                    fnewcustomer.close();
                }
}
void addItem()
{
    t:
    clrscr();
                                    
    printf("Choose Item to added\n");
    printf("1)Shrit\n"); 
    printf("2)T-Shrit\n");
    printf("3)Jeans\n");
    printf("4)Trouser\n");
    printf("5)Bed sheet\n");
    printf("6)Towel\n");
    printf("7)Suit\n");
    printf("8)Lower\n");
    printf("9)Shorts\n");
    cout<<"10)none"<<endl;
    int z=input();
    switch(z){
        case 1:{cout<<"Enter Quantity"<<endl; ent break;}
        case 2:{cout<<"Enter Quantity"<<endl; ent break;}
        case 3:{cout<<"Enter Quantity"<<endl; ent break;}
        case 4:{cout<<"Enter Quantity"<<endl; ent break;}
        case 5:{cout<<"Enter Quantity"<<endl; ent break;}
        case 6:{cout<<"Enter Quantity"<<endl; ent break;}
        case 7:{cout<<"Enter Quantity"<<endl; ent break;}
        case 8:{cout<<"Enter Quantity"<<endl; ent break;}
        case 9:{cout<<"Enter Quantity"<<endl; ent break;}
                                     
    }
    cout<<"do you want to add again?";
    char ans;
    cin>>ans;
    if(ans=='y')goto t;
}
void showlboyMenu(){
    int x;
   do{
    clrscr();  
    cout<<"*****************LAUNDRY MENU************"<<endl;
    printf("Enter choice...\n");
            printf("1)Display Schedule\n");
            printf("2)Add Laundry\n");
            printf("3)Update Profile\n");
            cout<<"4)Register Customer"<<endl;
            printf("5)Exit\n");
            cout<<"Enter Any one of the choices: ";
            x=input();
            switch(x){
                case 1:{ printf("Present Schedule is as follows :");ent break;}
                //displaySchedule();
                case 2: {
                    int y;
                    do{
                        clrscr();
                        printf("Current laundry slip contains\n");
                        //showSlip();
                        cout<<"what do you want to do?"<<endl;
                        printf("1)Add Items\n");
                        cout<<"2)Edit Item"<<endl;
                        cout<<"3)Delete Item"<<endl;
                        cout<<"4)Place laundry"<<endl;
                        printf("5)Exit \n");
                        cout<<"Enter any one of the choices: ";
                        y=input();
                        switch(y){
                            case 1:{ addItem(); break;}
                            case 2:{cout<<"Edit Item";break;}
                            case 3:{cout<<"Delete Item"<<endl; ent break;}
                            case 4:{cout<<"Place Laundry"<<endl; ent break;}
                            case 5:{cout<<"exit"; break;}
                            }   
                        }while(y!=5);
                break;}   
                case 3: {printf("Update\n"); ent break;}
                case 4: {printf("Add customer\n");
                //Enter code here
                addCustomer();
                ent break;}  
                case 5: {exit(0); break;}
            }
   }while(x!=5);
}
void loginlboy(){
fstream flboy;
                lboy b;
                string tempid,temppwd;
                is_firsttime_launch_lboy();
                cout<<"enter your ID: ";
                cin>>tempid;
                flboy.open("lboy.dat",ios::in);
                flboy.seekg(0);
                while(!flboy.eof()){
                    flboy.read((char*)&b,sizeof(b));
                    //cout<<a.id<<" id "<<tempid<<endl;
                    if(strcmp(b.id,tempid.c_str())==0){cout<<"User Found!!"<<endl;break;}

                }
                if(strcmp(b.id,tempid.c_str())!=0){cout<<"User not Found!!"<<endl;return;}
                flboy.close();
                
                cout<<"Enter the password: ";
                cin>>temppwd;
                if(strcmp(b.password,temppwd.c_str())==0){
                    cout<<"Password match"<<endl<<"Welcome "<<b.username<<"!!"<<endl; 
                    ent
                    showlboyMenu();
                }
                //cout<<"admin"<<" "<<a.password<<endl;
}
