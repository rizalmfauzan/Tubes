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

adrE relateAllocation (adrH H) {
    adrE E = new Relation;
    E->nextRelate = NULL;
    E->toHero = H;
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
void deleteFirstRole (listRole &LR, adrR &R) {
    if (LR.firstRole != NULL) {
        R = LR.firstRole;
        if (LR.firstRole == LR.lastRole) {
            LR.firstRole = NULL;
            LR.lastRole = NULL;
        } else {
            LR.firstRole = R->nextRole;
            R->nextRole = NULL;
        }
    }
}

void deleteLastRole (listRole &LR, adrR &R) {
    if (LR.firstRole != NULL) {
        R = LR.lastRole;
        if (LR.firstRole == LR.lastRole) {
            deleteFirstRole(LR,R);
        } else {
            adrR P = LR.firstRole;
            while (P->nextRole != LR.lastRole) {
                P = P->nextRole;
            }
            LR.lastRole = P;
            LR.lastRole->nextRole = NULL;
        }
    }
}

void deleteAfterRole (listRole &LR, adrR precR, adrR &R) {
    if (LR.firstRole != NULL && precR != LR.lastRole) {
        R = precR->nextRole;
        if (R == LR.lastRole) {
            deleteLastRole(LR,R);
        } else {
            precR->nextRole = R->nextRole;
            R->nextRole = NULL;
        }
    }
}

/** INSERT HERO */
void insertFirstHero (listHero &LH, adrH H);
void insertLastHero (listHero &LH, adrH H);
void insertAfterHero (listHero &LH, adrH precH, adrH H);

/** DELETE HERO */
void deleteFirstHero (listHero &LH, adrH &H);
void deleteLastHero (listHero &LH, adrH &H);
void deleteAfterHero (listHero &LH, adrH precH, adrH &H);

/** SEARCH BY ID*/
adrR searchIDrole (listRole LR, int ID) {
    adrR R = LR.firstRole;
    while (R != NULL && R->IDr != ID) {
        R = R->nextRole;
    }
    return R;
}

adrH searchIDhero (listHero LH, int ID) {
    adrH H = LH.firstHero;
    while (H != NULL && H->IDh != ID) {
        H = H->nextHero;
    }
    return H;
}

/** INSERT RELATION*/
void insertFirstRelation (listRelation &LE, adrE E) {
    if (LE.firstRelate == NULL) {
        LE.firstRelate = E;
        LE.lastRelate = E;
    } else {
        E->nextRelate = LE.firstRelate;
        LE.firstRelate = E;
    }
}

void insertLastRelation (listRelation &LE, adrE E);     //Do we need this?
void insertAfterRelation (listRelation &LE, adrE precE, adrE E);    //Do we need this?

void insertRelation (adrR R, adrE E) {
    insertFirstRelation(R->Relate, E);
}

/** DELETE RELATION*/
void deleteFirstRelation (listRelation &LE, adrE &E);
void deleteLastRelation (listRelation &LE, adrE &E);
void deleteAfterRelation (listRelation &LE, adrE precE, adrE &E);
void deleteRelation (adrR R);

/** PRINT INFO*/
void displayRole (listRole LR) {
    adrR R = LR.firstRole;
    cout<<"Role List: "<<endl;
    cout<<"==============================================="<<endl;
    while (R != NULL) {
        cout<<"ID Role:\t"<<R->IDr<<endl;
        cout<<"Role name:\t"<<R->roleName<<endl;
        cout<<"==============================================="<<endl;
        R = R->nextRole;
    }
}

void displayHero (listHero LH);

/** CONNECTION */
void connection (listRole LR, listHero LH) {
    int IDr, IDh;
    cout<<"Input Role ID: "; cin >> IDr;
    cout<<"Input Hero ID: "; cin >> IDh;
    adrR R = searchIDrole(LR,IDr);
    adrH H = searchIDhero(LH,IDh);
    if (R != NULL && H != NULL) {
        adrE E = relateAllocation(H);
        insertRelation(R,E);
    } else {
        cout<<"Role or Hero not found"<<endl;
    }
}
