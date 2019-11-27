#include <iostream>
#include <string.h>
#include <stdio.h>
//#include "user.h"
using namespace std;

class lboy : public user
{
public:
    lboy()
    {
        strcpy(id, "lboy");
        strcpy(username, "lboy");
        strcpy(password, "lboy");
    }
};
