#ifndef MULTI_H_INCLUDED
#define MULTI_H_INCLUDED

#define firstRole(LR)   LR.firstRole
#define lastRole(LR)    LR.lastRole
#define firstHero(LH)   LH.firstHero
#define lastHero(LH)    LH.lastHero
#define firstRelate(LE) LE.firstRelate
#define lastRelate(LE)  LE.lastRelate
#define IDr(R)          R->IDr
#define roleName(R)     R->roleName
#define nextRole(R)     R->nextRole
#define Relate(R)       R->Relate
#define IDh(H)          H->IDh
#define heroName(H)     H->heroName
#define nextHero(H)     H->nextHero
#define nextRelate(E)   E->nextRelate
#define toHero(E)       E->toHero

#include <iostream>
#include <conio.h>
using namespace std;

typedef struct Role *adrR;
typedef struct Hero *adrH;
typedef struct Relation *adrE;

struct listRole {               /** LIST PARENT */
    adrR firstRole;
    adrR lastRole;
};

struct listHero {               /** LIST CHILD */
    adrH firstHero;
    adrH lastHero;
};

struct listRelation {           /** LIST RELATION */
    adrE firstRelate;
    adrE lastRelate;
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
adrR roleAllocation (int ID, string role);
adrH heroAllocation (int ID, string hero);
adrE relateAllocation (adrH H);

/** DEALLOCATION*/
void deallocateRole (adrR &R);
void deallocateHero (adrH &H);
void deallocateRelation (adrE &E);

/** INSERT ROLE */
void insertFirstRole (listRole &LR, adrR R);
void insertLastRole (listRole &LR, adrR R);
void insertAfterRole (listRole &LR, adrR precR, adrR R);
void insertRole (listRole &LR);

/** DELETE ROLE */
void deleteFirstRole (listRole &LR, adrR &R);
void deleteLastRole (listRole &LR, adrR &R);
void deleteAfterRole (listRole &LR, adrR precR, adrR &R);
void deleteRole (listRole &LR);

/** INSERT HERO */
void insertFirstHero (listHero &LH, adrH H);
void insertLastHero (listHero &LH, adrH H);
void insertAfterHero (listHero &LH, adrH precH, adrH H);
void insertHero (listHero &LH);

/** DELETE HERO */
void deleteFirstHero (listHero &LH, adrH &H);
void deleteLastHero (listHero &LH, adrH &H);
void deleteAfterHero (listHero &LH, adrH precH, adrH &H);
void deleteHero (listRole &LR, listHero &LH);

/** SEARCH*/
adrR searchIDrole (listRole LR, int ID);
adrH searchIDhero (listHero LH, int ID);
adrE searchRelation (adrR R, int IDhero);

/** INSERT RELATION*/
void insertFirstRelation (listRelation &LE, adrE E);
void insertRelation (adrR &R, adrE E);

/** DELETE RELATION*/
void deleteFirstRelation (listRelation &LE, adrE &E);
void deleteLastRelation (listRelation &LE, adrE &E);
void deleteAfterRelation (listRelation &LE, adrE precE, adrE &E);
void deleteRelation (adrR &R, adrE &E);

/** PRINT INFO*/
void displayRole (adrR R);
void displayAllRole (listRole LR);
void displayHero (adrH H);
void displayAllHero (listHero LH);
void heroOfRole (adrR R);
void displayHeroOfRole (listRole LR);
void displayAll (listRole LR);

/** CONNECTION */
void connection (listRole LR, listHero LH);
bool checkConnect (listRole LR);
void disConnect (listRole &LR);

/** MISC */
bool duplicateCheckRole (listRole LR, adrR R);
bool duplicateCheckHero (listHero LH, adrH H);
void cleanRelation (listRole &LR, int ID);

#endif // MULTI_H_INCLUDED
