#ifndef MULTI_H_INCLUDED
#define MULTI_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct Role *adrR;
typedef struct Hero *adrH;
typedef struct Relation *adrE;

struct listRole {               /** LIST PARENT */
    adrR firstRole;
};

struct listHero {               /** LIST CHILD */
    adrH firstHero;
};

struct listRelation {           /** LIST RELATION */
    adrE firstRelate;
};

struct Role {                   /** PARENT */
    int IDr;
    string roleName;
    adrR nextRole;
    listRelation Relate;
};

struct Hero {                   /** CHILD */
    int IDh;
    string heroName;
    adrH nextHero;
};

struct Relation {               /** RELATION*/
    adrE nextRelate;
    adrH toHero;
};

/** CREATE LIST */
void createListRole (listRole &LR);
void createListHero (listHero &LH);
void createListRelation (listRelation &LE);

/** ALLOCATION */
adrR roleAllocation (int ID, string roleName);
adrH heroAllocation (int ID, string heroName);
adrE relateAllocation (int ID);

/** DEALLOCATION*/
void deallocateRole (adrR &R);
void deallocateHero (adrH &H);
void deallocateRelation (adrE &E);

/** INSERT ROLE */
void insertFirstRole (listRole &LR, adrR R);
void insertLastRole (listRole &LR, adrR R);
void insertAfterRole (listRole &LR, adrR R);

/** DELETE ROLE */
void deleteFirstRole (listRole &LR, adrR &R);
void deleteLastRole (listRole &LR, adrR &R);
void deleteAfterRole (listRole &LR, adrR &R);

/** INSERT HERO */
void insertFirstHero (listHero &LH, adrH H);
void insertLastHero (listHero &LH, adrH H);
void insertAfterHero (listHero &LH, adrH H);

/** DELETE HERO */
void deleteFirstHero (listHero &LH, adrH &H);
void deleteLastHero (listHero &LH, adrH &H);
void deleteAfterHero (listHero &LH, adrH &H);

/** SEARCH BY ID*/
adrR searchIDrole (listRole LR);
adrH searchIDhero (listHero LH);

/** INSERT RELATION*/
void insertFirstRelation (listRelation &LE, adrE E);
void insertLastRelation (listRelation &LE, adrE E);     //Do we need this?
void insertAfterRelation (listRelation &LE, adrE E);    //Do we need this?
void insertRelation (adrR R);

/** DELETE RELATION*/
void deleteFirstRelation (listRelation &LE, adrE &E);
void deleteLastRelation (listRelation &LE, adrE &E);
void deleteAfterRelation (listRelation &LE, adrE &E);
void deleteRelation (adrR R);

/** PRINT INFO*/
void displayRole (listRole LR);
void displayHero (listHero LH);

#endif // MULTI_H_INCLUDED
