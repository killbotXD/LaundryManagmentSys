#include <iostream>
#include <string.h>
#include <stdio.h>
#include "user.h"
using namespace std;

class admin : public user
{
public:
    char mobile[10];
    admin()
    {
        strcpy(id, "admin");
        strcpy(username, "admin");
        strcpy(password, "admin");
        strcpy(mobile, "admin");
    }
};