#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class User{
    private:
string username;
string password;
string id;
public:
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
void changePassword(string newPwd){
    password=newPwd;
}
void changeName(string newName){
    username=newName;
}
void getSchedule(){
    cout<<"Need to add this shit";
}


};
