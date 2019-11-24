#include "template.h"
void is_firsttime_launch(){
    char c;
    fstream file,fa;
    admin a;
    file.open("data.txt",ios::in);
    file>>c;
    file.close();
    if(c=='y'){
        cout<<"creating default admin"<<endl;
        file.open("data.txt",ios::out);file<<'n';file.close();
        fa.open("admins.dat",ios::out);
        fa.write((char*)&a,sizeof(admin));
        fa.close();
    }
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
        case 1:{cout<<"Update Schedulle"<<endl;ent
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
        case 6: return;
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
    
   do{
    //clrscr();  
    cout<<"*****************LAUNDRY MENU************"<<endl;
    printf("Enter choice...\n");
            printf("1)Display Schedule\n");
            printf("2)Add Laundry\n");
            printf("3)Update Profile\n");
            printf("4)Exit\n");
            int x;
            x=input();
            switch(x){
                case 1:{ printf("Present Schedule is as follows :");break;}
                //Enter code here
                case 2: do{
                        {printf("Enter choice...\n");
                        printf("1)Add Item\n");
                        printf("2)Exit \n");
                        int y;
                        y=input();
                        switch(y){
                            case 1:{ printf("Choose Item to added\n");
                                    printf("1)Shrit\n"); 
                                    printf("2)T-Shrit\n");
                                    printf("3)Jeans\n");
                                    printf("4)Trouser\n");
                                    printf("5)Bed sheet\n");
                                    printf("6)Towel\n");
                                    printf("7)Suit\n");
                                    printf("8)Lower\n");
                                    printf("9)Shorts\n");
                                    printf("10)Exit\n");
                                    int z=input();
                                    switch(z){
                                        case 1:{break;}
                                        case 2:{break;}
                                        case 3:{break;}
                                        case 4:{break;}
                                        case 5:{break;}
                                        case 6:{break;}
                                        case 7:{break;}
                                        case 8:{break;}
                                        case 9:{break;}
                                     
                                    }break;}
                                case 2:{cout<<endl<<"exit";break;}
                                }   
                        }while(y!=2);
                break;}
                        
                case 3: {printf("Update"); break;}
                case 4: {printf("Add customer"); break;}
                //Enter code here
                case 5: {  break;}
            }
   }while(x!=5);
}
void is_firsttime_launch_lboy(){
    char c;
    fstream file,fb;
    lboy b;
    file.open("datab.txt",ios::in);
    file>>c;
    file.close();
    if(c=='y'){
        cout<<"creating default lboy"<<endl;
        file.open("datab.txt",ios::out);file<<'n';file.close();
        fb.open("lboy.dat",ios::out);
        fb.write((char*)&b,sizeof(lboy));
        fb.close();
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

void showcustomerMenu(){
    int x;
   do{
    //clrscr();  
    cout<<"*****************CUSTOMER MENU************"<<endl;
    printf("Enter choice...\n");
            printf("1)Update Profile\n");
            printf("2)Display Schedule\n");
            printf("3)Mark Laundry Received\n");
            printf("4)Exit\n");
            x=input();
            switch(x){
                case 1:{  cout<<"Update Profile";break;}
                //Enter code here
                case 2: {printf("Display Schedule\n");              
                                    break;}
                case 3: {printf("Mark Laundry Received"); break;}
                //Enter code here
                case 4: {  break;}
            }
   }while(x!=4);
}
void is_firsttime_launch_customer(){
    char c;
    fstream file,fb;
    customer b;
    file.open("datac.txt",ios::in);
    file>>c;
    file.close();
    if(c=='y'){
        cout<<"creating default customer"<<endl;
        file.open("datac.txt",ios::out);file<<'n';file.close();
        fb.open("customer.dat",ios::out);
        fb.write((char*)&b,sizeof(customer));
        fb.close();
    }
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
            case 2: {
                cout<<"Customer";
                logincustomer();
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
