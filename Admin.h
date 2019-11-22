#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include "User.h"
using namespace std;
class Admin:public User{
    private:
    string mobile;
    public:
    void registerLaundryAttendant(){
        fstream f;
       // f.open("Users.dat",ios::out|ios::app);

        
        //f.close();
    }
    void assignLaundryAttendant();
    void deassignLaundryAttendant();
    void addAdmin(string newId){
        addUser(newId);
        cout<<endl<<"Enter your mobile number";
        cin>>mobile;
             
    }

};