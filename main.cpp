#include "template.h"
#include "admin.cpp"
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
                if(strcmp(a.id,tempid.c_str())!=0){cout<<"User not Found!!"<<endl;break;}
                fadmin.close();
                
                cout<<"Enter the password: ";
                cin>>temppwd;
                if(strcmp(a.password,temppwd.c_str())==0){
                    cout<<"Password match"<<endl<<"Welcome "<<a.username<<"!!"<<endl; 
                }
                //cout<<"admin"<<" "<<a.password<<endl;
                
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