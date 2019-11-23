#include "template.h"
#include "Admin.cpp"
int main()
{
    fstream f;
    //f.open("Users.dat",ios::out|ios::app);f.close();
    int x,y;
    int userType;
    // travel t;
do{
clrscr();
//system("color 3");
gotoxy(4,1);printf("**********************Welcome**********************\n");
//system("color 4");
printf("Enter your type...\n");
printf("1)ADMIN\n");
printf("2)LAUNDRY BOY\n");
printf("3)CUSTOMER\n");
printf("4)EXIT\n");
cout<<"Enter any one of the choices: ";
x=input();
switch(x){
    case 1:{ //ADMIN
           
            f.open("Admins.dat",ios::out|ios::app);f.close();
            char ch;
            printf("\n");
            printf("Are you a new User?\n");
            cin>>ch;
            switch(ch){
                
                case 'y':{clrscr(); printf("********************SIGN UP*******************");
                        cout<<endl<<"enther the Id of the new user :";
                        string newId;
                        cin>>newId;
                        f.open("Admins.dat",ios::in);
                        f.seekg(0);
                        int chk=0;
                        string tempid;
                     while(!(f.eof())){
                      f.read((char*)&a,sizeof(a));
                      if(f.eof())break;
                      tempid=a.returnId();
                      if(tempid==newId){
                          cout<<"The User already exists ..please use another code..";chk++;
                          break;
                          }
                         }
                        f.close();
                        
                        if(chk==0){
                            f.open("Admins.dat",ios::out|ios::app);
                            a.addAdmin(newId);
                            f.write((char*)&a,sizeof(a));
                            cout<<"Registred succesfully!"<<endl;
                            f.close();
                        }
                          cout<<endl<<"press enter...";  
                        char temp=getchar();
                        showAdminMenu();
                        break;}
                
                case 'n': {
                    string tempId,Id,tempPwd;
                    printf("********************Login********************\n");
                        cout<<"Enter your User ID: ";
                        cin>>Id;
                        f.open("Admins.dat",ios::in);
                        skg;
                        int flag=0;
                        while(!f.eof()){
                            fr(a);
                            if(f.eof())break;
                            tempId=a.returnId();   
                            if(tempId==Id){cout<<"User found!!"<<endl;flag++;break;}
                        }
                        int flag2=0;
                         while(1){
                            if(flag==0){
                                cout<<"User Not Found"<<endl;break;
                                }
                            else if(flag!=0&&flag2!=3){
                                cout<<"Enter password: ";
                                cin>>tempPwd;
                                if(a.authenticate(tempPwd)){
                                    cout<<"Welcome "<<a.returnName()<<"!"<<endl;
                                    showAdminMenu();
                                    break;
                                }
                                else{
                                    flag2++;
                                    cout<<"Password is incorrect you have "<<3-flag2<< "chances left!!"<<endl;
                                }
                            }
                            else{
                                break;
                            }       
                         }      
                         cout<<"press enter....";         
                        char temp=getchar();
                 //TODO: need to add the admin method which will be called to show the menu of admin after login
                        break;}
               
            }
            break;
        }
    case 2:{ //Laundry BOY
            printf("Enter choice...\n");
            printf("1)Display Schedule\n");
            printf("2)Add Laundry\n");
            printf("3)Update Profile\n");
            printf("4)Exit\n");
            x=input();
            switch(x){
                case 1:{ printf("Present Schedule is as follows :");break;}
                //Enter code here
                case 2: {printf("Enter choice...\n");
                        printf("1)Add Item\n");
                        printf("2)Exit \n");
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
                break;}
                        
                case 3: {printf("Update"); break;}
                //Enter code here
                case 4: {break;}
            }
            break;
    }
    case 3: {//CUSTOMER
        break;
        }
    default: {printf("Thanks for visiting");break;}


}//switch
}while(x!=4);//do


}
