#include <iostream>
#include"WorkManager.h"
#include"Worker.h"
using namespace std;


int main(){

    workmanager wm;
    wm.show_menu();

    int option_number;
    cin >> option_number;

    while(true){
        switch(option_number){
            case 0:
                wm.exit_menu();
                break;
            case 1:
                wm.add_person();
                break;
            case 2:
                wm.show_person();
                break;
            default:
                system("cls");
                break;
        }
    }
    return 0;
}

