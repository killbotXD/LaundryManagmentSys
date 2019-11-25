#include "template.h"
void is_firsttime_launch(){
    fstream file,fa;
    admin a;
    file.open("admins.dat",ios::in);
    if(file.fail()){
        cout<<"creating default admin"<<endl;
        fa.open("admins.dat",ios::out);
        fa.write((char*)&a,sizeof(admin));
        fa.close();
    }
    else
    {
        file.close();
    }
    
}
int lboyExists(string id){
    fstream flboy;
                lboy b;
                //is_firsttime_launch_lboy();
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
    if(lboyExists(tempId)){tempLboyId[i]=tempId;i++;}
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
        case 2: {cout<<"Edit"; ent
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
                is_firsttime_launch();
                cout<<"enter your ID: ";
                cin>>tempid;
                fadmin.open("admins.dat",ios::in);
                fadmin.seekg(0);
                while(!fadmin.eof()){
                    fadmin.read((char*)&a,sizeof(a));
                    //cout<<a.id<<" id "<<tempid<<endl;
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
                //cout<<"admin"<<" "<<a.password<<endl;
                
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
            x=input();
            switch(x){
                case 1:{ printf("Present Schedule is as follows :");ent break;}
                //Enter code here
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
                        y=input();
                        switch(y){
                            case 1:{ 
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
                                    
                                    break;}
                                case 2:{cout<<"Edit Item";break;}
                                case 3:{cout<<"Delete Item"<<endl; ent break;}
                                case 4:{cout<<"Place Laundry"<<endl; ent break;}
                                case 5: {cout<<"exit"; break;}
                                }   
                        }while(y!=5);
                break;}   
                case 3: {printf("Update\n"); ent break;}
                case 4: {printf("Add customer\n"); ent break;}
                //Enter code here
                case 5: { exit(0); break;}
            }
   }while(x!=5);
}
void is_firsttime_launch_lboy(){
    fstream file,fb;
    lboy b;
    file.open("datab.txt",ios::in);
    if(file.fail()){
        cout<<"creating default lboy"<<endl;
        fb.open("lboy.dat",ios::out);
        fb.write((char*)&b,sizeof(lboy));
        fb.close();
    }else{
        file.close();
    }
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
            case 2: {cout<<"customer";
                //logincustomer();
                break;}
            case 3:{
                cout<<"Laundry Boy";
                loginlboy();
                break;}

        }
    ent
    }while (inp!=4);
    

}
