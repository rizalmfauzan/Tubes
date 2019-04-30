#include "multi.h"
#include <iostream>

using namespace std;
listRole LR;
listRelation LE;
listHero LH;
Hero IDh, H;
Role IDr, R;
string role, hero;
int main() {
    createListRelation(LE);
    createListRole(LR);
    createListHero(LH);
    int choice;
    do {
        cout<<"==============================================="<<endl;
        cout<<endl;
        cout<< "1. Insert Role" << endl;
        cout<< "2. List Hero" << endl;
        cout<< "3. Print Role" << endl;
        cout<< "4. Print Hero" << endl;
        cout<< "5. Print All" << endl;
        cout<< "6. Jumlah Role"<<endl;
        cout<< "7. Jumlah Hero"<<endl;
        cout<< "0. Udahan";
        cout<<endl;
        cout<<"==============================================="<<endl;
        cout<< "Choice : ";
        cin >> choice;
        switch(choice) {
            case 1 :
                insertRole(LR);
                break;
            case 2 :
                insertHero(LH);
                break;
            case 3 :
                displayAllRole(LR);
                break;
            case 4 :
                displayAllHero(LH);
                break;
            case 5 :
                displayAll(LR);
                break;
            case 6 :
                int total = countRole(LR);
                cout<< "Jumlah Role : "<< total<< endl;
                break;
            case 7 :
                cout<< "Pilih Role : ";
                cin>> role;
                int jumlah = countHero(LH);
                cout<< "Jumlah Hero Pada Role "<< role<< " : "<< jumlah<<endl;
        }
    }while (choice != 0);

    return 0;
}
