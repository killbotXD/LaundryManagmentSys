
void showAdminMenu(){
    int inp;
   do{
     clrscr();  
    cout<<"*****************ADMIN MENU************"<<endl;
    cout<<"1)Update Schedulle"<<endl;
    cout<<"2)Add New Admin"<<endl;
    cout<<"3)View Schedule"<<endl;
    cout<<"4)Register Laundry Personell"<<endl;
    cout<<"5)Settings"<<endl;
    cout<<"6)Exit"<<endl;
    inp=input();
    switch(inp){
        case 1:{cout<<"Update Schedulle"<<endl;ent
            break;
        }
        case 2:{  cout<<"Add New Admin"<<endl;ent
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
   }while(inp!=6);
}