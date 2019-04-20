#include "multi.h"

/** CREATE LIST */
void createListRole (listRole &LR) {
    LR.firstRole = NULL;
    LR.lastRole = NULL;
}

void createListHero (listHero &LH) {
    LH.firstHero = NULL;
    LH.lastHero = NULL;
}

void createListRelation (listRelation &LE) {
    LE.firstRelate = NULL;
    LE.lastRelate = NULL;
}

/** ALLOCATION */
adrR roleAllocation (int ID, string role) {
    adrR R = new Role;
    R->IDr = ID;
    R->roleName = role;
    R->nextRole = NULL;
    listRelation LE;
    createListRelation(LE);
    R->Relate = LE;
    return R;
}

adrH heroAllocation (int ID, string hero) {
    adrH H = new Hero;
    H->IDh = ID;
    H->heroName = hero;
    H->nextHero = NULL;
    return H;
}

adrE relateAllocation (int ID) {
    adrE E = new Relation;
    E->nextRelate = NULL;
    E->toHero = NULL;
    return E;
}

/** DEALLOCATION*/
void deallocateRole (adrR &R) {
    delete R;
}

void deallocateHero (adrH &H) {
    delete H;
}

void deallocateRelation (adrE &E) {
    delete E;
}

/** INSERT ROLE */
void insertFirstRole (listRole &LR, adrR R) {
    if (LR.firstRole == NULL) {
        LR.firstRole = R;
        LR.lastRole = R;
    } else {
        R->nextRole = LR.firstRole;
        LR.firstRole = R;
    }
}

void insertLastRole (listRole &LR, adrR R) {
    if (LR.firstRole == NULL) {
        insertFirstRole(LR,R);
    } else {
        LR.lastRole->nextRole = R;
        LR.lastRole = R;
    }
}

void insertAfterRole (listRole &LR, adrR precR, adrR R) {
    if (precR == LR.lastRole) {
        insertLastRole(LR,R);
    } else {
        R->nextRole = precR->nextRole;
        precR->nextRole = R;
    }
}

/** DELETE ROLE */
void deleteFirstRole (listRole &LR, adrR &R);
void deleteLastRole (listRole &LR, adrR &R);
void deleteAfterRole (listRole &LR, adrR precR, adrR &R);

/** INSERT HERO */
void insertFirstHero (listHero &LH, adrH H);
void insertLastHero (listHero &LH, adrH H);
void insertAfterHero (listHero &LH, adrH precH, adrH H);

/** DELETE HERO */
void deleteFirstHero (listHero &LH, adrH &H);
void deleteLastHero (listHero &LH, adrH &H);
void deleteAfterHero (listHero &LH, adrH precH, adrH &H);

/** SEARCH BY ID*/
adrR searchIDrole (listRole LR, int ID);
adrH searchIDhero (listHero LH, int ID);

/** INSERT RELATION*/
void insertFirstRelation (listRelation &LE, adrE E);
void insertLastRelation (listRelation &LE, adrE E);     //Do we need this?
void insertAfterRelation (listRelation &LE, adrE precE, adrE E);    //Do we need this?
void insertRelation (adrR R);

/** DELETE RELATION*/
void deleteFirstRelation (listRelation &LE, adrE &E);
void deleteLastRelation (listRelation &LE, adrE &E);
void deleteAfterRelation (listRelation &LE, adrE precE, adrE &E);
void deleteRelation (adrR R);

/** PRINT INFO*/
void displayRole (listRole LR);
void displayHero (listHero LH);
