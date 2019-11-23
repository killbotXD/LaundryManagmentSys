#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;
class User{
    private:
string username;
string password;
string id;
public:
User(){
    username="Username";
    password="password";
    id="NULL";
}

string returnId(){
    return id;
}
string returnName(){
    return username;
}
int authenticate(string temp){
    if(temp==password){return 1;}
    return 0;
}
//you need to authenticate in the function that you are going to call befoe you pass a new name
// or password to this method
/* char *pa=new char[203];    int access2;

                      pa=t.enterpass();
                      access2=t.access(pa);
                      if(access2==1){gotoxy(15,18);cout<<"access granted.....press enter..... ";getch();
gotoxy(15,19);        t.changepass();}*/
void changePassword(string newPwd){
    password=newPwd;
}
void changeName(string newName){
    username=newName;
}
void changeId(string newId){
    id=newId;
}
void getSchedule(){
    cout<<"Need to add this shit";
}
void addUser(string newId){
    id=newId;
    string tempUsername,tempPwd;
    cout<<"Enter Username: ";
    cin>>tempUsername;
    changeName(tempUsername);
    cout<<"Enter Password(note: default password is\"password\"): ";
    cin>>tempPwd;
    changePassword(tempPwd);
    
}

};
