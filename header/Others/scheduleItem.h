#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
class scheduleitem
{
public:
    char add[50];
    char dayOfWeek[10];
    char lboyId[20][20];
    void cpscheduleitem(scheduleitem s)
    {
        strcpy(add, s.add);
        strcpy(dayOfWeek, s.dayOfWeek);
        for (int i = 0; i < sizeof(s.lboyId) / sizeof(string); i++)
        {
            strcpy(lboyId[i], s.lboyId[i]);
        }
    }
    int match(scheduleitem s){
        if(strcmp(add,s.add)==0){
            if(strcmp(dayOfWeek,s.dayOfWeek)==0){
                 for (int i = 0; i < sizeof(s.lboyId) / sizeof(string); i++){
                    if(strcmp(lboyId[i],s.lboyId[i])==0){}
                    else{
                        return 0;
                    }
                }
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
        return 1;
            
               
                    


    }
};
