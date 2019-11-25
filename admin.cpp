int lboyExists(string id){
    fstream flboy;
                lboy b;
                is_firsttime_launch_lboy();
                flboy.open("lboy.dat",ios::in);
                flboy.seekg(0);
                while(!flboy.eof()){
                    flboy.read((char*)&b,sizeof(b));
                    //cout<<a.id<<" id "<<tempid<<endl;
                    if(strcmp(b.id,id.c_str())==0){flboy.close();return 1;}

                }
                flboy.close();
                return 0;
                
}
void addScheduleItem(){
        fstream faddSI;
        scheduleitem schItem;
        string tempDay,tempAdd,tempId;
        string tempLboyId[20];
        cout<<"Enter Day: ";
        cin>>tempDay;
        cout<<"Enter Address of the Scheduled Laundry: ";
        cin>>tempAdd;
        string answer="yes";
        int i=0;
        while(answer=="y"||answer=="yes"||answer=="Y"||answer=="YES"){
            cout<<"Enter Laundry Boy Id to Be assigned: ";
            cin>>tempId;
            if(lboyExists(tempId)){cout<<"Added laundry boy"<<endl;tempLboyId[i]=tempId;i++;}
            else{cout<<"The Laundry boy does not exist!!!"<<endl<<endl;}
            cout<<"Do you want to add another laundry Boy?";
            cin>>answer;
        }

        cout<<endl<<"Confirm add Schedule Item?";
        cin>>answer;
        if(answer=="y"||answer=="yes"||answer=="Y"||answer=="YES"){
            strcpy(schItem.day,tempDay.c_str());
            for(i=0;i<sizeof(tempLboyId)/sizeof(string);i++){
                strcpy(schItem.lboyId[i],tempLboyId[i].c_str());
            }
            strcpy(schItem.add,tempAdd.c_str());
            faddSI.open("schedule.dat",ios::out|ios::app);
            faddSI.write((char*)&schItem,sizeof(schItem));
            faddSI.close();
        }
}
void editScheduleItem(){
    int inpEdit;
    do{clrscr();
    cout<<"*****************Edit Schedule Menu*****************"<<endl;
    cout<<"1)Monday"<<endl;
    cout<<"2)Tuesday"<<endl;
    cout<<"3)Wednesday"<<endl;
    cout<<"4)Thursday"<<endl;
    cout<<"5)Friday"<<endl;
    cout<<"6)Saturday"<<endl;
    cout<<"7)Sunday"<<endl;
    cout<<"8)Exit"<<endl;
    cout<<"Enter the day you want to edit: "<<endl;
    inpEdit=input();
    switch(inpEdit){
        case 1:{cout<<"Monday"<<endl;
        
         ent break;}
        case 2:{cout<<"Tuesday"<<endl; ent break;}
        case 3:{cout<<"Wednesday"<<endl; ent break;}
        case 4:{cout<<"Thursday"<<endl; ent break;}
        case 5:{cout<<"Friday"<<endl; ent break;}
        case 6:{cout<<"Saturday"<<endl; ent break;}
        case 7:{cout<<"Sunday"<<endl; ent break;}
        case 8:{cout<<"Exit"<<endl;  break;}

    }}while(inpEdit!=8);
}

void updateSchedule(){
    int inpUpdateSchedule;
    do{
        clrscr();
        cout<<"***********************Update Schedule Menu***********************"<<endl;
        cout<<"1)Add Schedule Item"<<endl;
        cout<<"2)Edit Schedule Item"<<endl;
        cout<<"3)Delete Schedule Item"<<endl;
        cout<<"4)Exit"<<endl;
        cout<<"Choose an Option:";
        cin>>inpUpdateSchedule;
        switch (inpUpdateSchedule)
        {
        case 1:{cout<<"Add"; 
           addScheduleItem();
        
            ent 
            break;}
        case 2: {cout<<"Edit"; 
            editScheduleItem();
            ent
            break;}
        case 3: {cout<<"Delete"; ent
            break;}
        case 4:{cout<<"Exit"<<endl;}
        }
    }while(inpUpdateSchedule!=4);
}
void showAdminMenu(){
    int inpadmin;
   do{
     clrscr();  
    cout<<"*****************ADMIN MENU************"<<endl;
    cout<<"1)Update Schedulle"<<endl;
    cout<<"2)Add New Admin"<<endl;
    cout<<"3)View Schedule"<<endl;
    cout<<"4)Register Laundry Personell"<<endl;
    cout<<"5)Settings"<<endl;
    cout<<"6)Exit"<<endl;
    cout<<"Enter any one of the choices: ";
    inpadmin=input();
    switch(inpadmin){
        case 1:{updateSchedule();
        
            ent
            break;
        }
        case 2:{  
            clrscr();
            cout<<"**************Sign UP**************"<<endl;
                fstream fnewadmin;
                admin newAdmin;
                string temppwd,tmpusername,tmpid,tmpmobile;
                cout<<"Enter new Id: ";
                cin>>tmpid;
                fnewadmin.open("admins.dat",ios::in);
                fnewadmin.seekg(0);
                while(!fnewadmin.eof()){
                    fnewadmin.read((char*)&newAdmin,sizeof(admin));

                    if(strcmp(newAdmin.id,tmpid.c_str())==0){cout<<"User already exists... Try another Id!!"<<endl;
                    break;}

                }
                fnewadmin.close();
                if(strcmp(newAdmin.id,tmpid.c_str())!=0){
                    strcpy(newAdmin.id,tmpid.c_str());
                    cout<<"Enter Username: ";
                    cin>>tmpusername;
                    strcpy(newAdmin.username,tmpusername.c_str());
                    cout<<"Enter Password:";
                    cin>>temppwd;
                    strcpy(newAdmin.password,temppwd.c_str());
                    cout<<"Enter Mobile Number";
                    cin>>tmpmobile;
                    strcpy(newAdmin.mobile, tmpmobile.c_str());
                    fnewadmin.open("admins.dat",ios::out|ios::app);
                    fnewadmin.write((char*)&newAdmin,sizeof(admin));
                    fnewadmin.close();
                    
                }
        
            ent       
            break;
            }
        case 3:{cout<<"View Schedule"<<endl;ent
            break;
            }
        case 4:{cout<<"Register Laundry Personell"<<endl;ent
            break;
            }
        case 5:{cout<<"Settings"<<endl;ent
            break;
            }
        case 6:{exit(0);return;}
    }
   }while(inpadmin!=6);
}
void loginadmin(){
    fstream fadmin;
                    admin a;
                    string tempid,temppwd;
                    is_firsttime_launch_admin();
                    cout<<"enter your ID: ";
                    cin>>tempid;
                    fadmin.open("admins.dat",ios::in);
                    fadmin.seekg(0);
                    while(!fadmin.eof()){
                        fadmin.read((char*)&a,sizeof(a));
                        if(strcmp(a.id,tempid.c_str())==0){cout<<"User Found!!"<<endl;break;}
                    }
                    if(strcmp(a.id,tempid.c_str())!=0){cout<<"User not Found!!"<<endl;return;}
                    fadmin.close();
                    
                    cout<<"Enter the password: ";
                    cin>>temppwd;
                    if(strcmp(a.password,temppwd.c_str())==0){
                        cout<<"Password match"<<endl<<"Welcome "<<a.username<<"!!"<<endl; 
                        ent
                        showAdminMenu();
                    }                
}