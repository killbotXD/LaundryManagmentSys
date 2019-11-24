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
                cout<<"customer";
                break;}
            case 3:{
                cout<<"Laundry Boy";
                break;}

        }
    ent
    }while (inp!=4);
    

}