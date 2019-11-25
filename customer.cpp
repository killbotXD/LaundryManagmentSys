
void showcustomerMenu(){
    int x;
   do{
    clrscr();  
    cout<<"*****************CUSTOMER MENU************"<<endl;
    printf("Enter choice...\n");
            printf("1)Update Profile\n");
            printf("2)Display Schedule\n");
            printf("3)Mark Laundry Received\n");
            printf("4)Exit\n");
            cout<<"Enter Any one of the choices: ";
            x=input();
            switch(x){
                case 1:{ ent break;}
                //Enter code here
                case 2: {//take the name of the hostel as input in a string variable and then call viewSchedule_customer             
                           ent         break;}
                case 3: {printf("Mark Laundry Received");ent break;}
                //Enter code here
                case 4: { exit(0);  break;}
            }
   }while(x!=4);
}

void logincustomer(){
    fstream fcustomer;
                    customer b;
                    string tempid,temppwd;
                    is_firsttime_launch_customer();
                    cout<<"enter your ID: ";
                    cin>>tempid;
                    fcustomer.open("customer.dat",ios::in);
                    fcustomer.seekg(0);
                    while(!fcustomer.eof()){
                        fcustomer.read((char*)&b,sizeof(b));
                        //cout<<a.id<<" id "<<tempid<<endl;
                        if(strcmp(b.id,tempid.c_str())==0){cout<<"User Found!!"<<endl;break;}

                    }
                    if(strcmp(b.id,tempid.c_str())!=0){cout<<"User not Found!!"<<endl;return;}
                    fcustomer.close();
                    
                    cout<<"Enter the password: ";
                    cin>>temppwd;
                    if(strcmp(b.password,temppwd.c_str())==0){
                        cout<<"Password match"<<endl<<"Welcome "<<b.username<<"!!"<<endl; 
                        ent
                        showcustomerMenu();
                    }
}