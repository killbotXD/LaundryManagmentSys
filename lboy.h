#include<iostream>
#include<string.h>
#include<stdio.h>
//#include "user.h"
using namespace std;

class lboy: public user{
    public:
    
    lboy(){
        strcpy(id,"lboy");
       // id="admin";
        strcpy(username,"lboy");
         strcpy(password,"lboy");
          
        // username="admin";
        // password="admin";
        // mobile="1234567890";
    }
};
