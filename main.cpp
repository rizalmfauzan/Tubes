#include "multi.h"
#include <iostream>

using namespace std;
listRole LR;
listHero LH;
Hero IDh, H;
Role IDr, R;
string role, hero;
int main() {
    createListRole(LR);
    insertRole(roleAllocation(1, "support"));
    insertRole(roleAllocation(2, "initiator"));
    insertRole(roleAllocation(3, "carry"));
    insertRole(roleAllocation(4, "disabler"));
    insertRole(roleAllocation(5, "melee"));
    int choice;
    do {
        cout<<"==============================================="<<endl;
        cout<<endl;
        cout<< "1. Insert Role" << endl;
        cout<< "2. List Hero" << endl;
        cout<< "3. Print Role" << endl;
        cout<< "4. Print Hero" << endl;
        cout<< "0. Udahan";
        cout<<endl;
        cout<<"==============================================="<<endl;
        cout<< "Choice : ";
        cin >> choice;
        switch(choice) {
            case 1 :
                insertRole(roleAllocation(IDr, role));
                break;
            case 2 :
                createListHero(LH);
                insertHero(heroAllocation(IDh, hero));
                break;
            case 3 :
                displayAll(LR);
                break;
            case 4 :
                displayAllHero(LH);
                break;
        }
    }while (choice != 0);

    return 0;
}
