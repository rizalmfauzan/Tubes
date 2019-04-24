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

void insertRole (listRole &LR) {
    int X;
    string nama;
    cout<<"Masukkan ID: "; cin>>X;
    cout<<"Masukkan nama Role: "; cin>>nama;
    adrR R = roleAllocation(X,nama);
    if (!duplicateCheckRole(LR,R)) {
        if (LR.firstRole == NULL) {
            insertFirstRole(LR,R);
        } else {
            adrR P = LR.firstRole;
            while (P!= NULL && R->IDr > P->IDr) {
                P = P->nextRole;
            }
            if (P == LR.firstRole) {
                insertFirstRole(LR,R);
            } else if (P == NULL) {
                insertLastRole(LR,R);
            } else {
                adrR Q = LR.firstRole;
                while (Q->nextRole != P) {
                    Q = Q->nextRole;
                }
                insertAfterRole(LR,Q,R);
            }
        }
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


/** SEARCH*/
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

void insertRelation (adrR R, adrE E) {
    insertFirstRelation(R->Relate, E);
}


/** DELETE RELATION*/
void deleteFirstRelation (listRelation &LE, adrE &E);
void deleteLastRelation (listRelation &LE, adrE &E);
void deleteAfterRelation (listRelation &LE, adrE precE, adrE &E);
void deleteRelation (adrR R);


/** PRINT INFO*/
void displayRole(adrR R) {
    cout<<"ID Role:\t"<<R->IDr<<endl;
    cout<<"Role name:\t"<<R->roleName<<endl;
    cout<<"==============================================="<<endl;
}

void displayAllRole (listRole LR) {
    adrR R = LR.firstRole;
    cout<<"Role List: "<<endl<<endl;
    while (R != NULL) {
        displayRole(R);
        R = R->nextRole;
    }
    cout<<endl;
}

void displayHero(adrH H) {
    cout<<"ID Hero:\t"<<H->IDh<<endl;
    cout<<"Hero name:\t"<<H->heroName<<endl;
    cout<<"==============================================="<<endl;
}

void displayAllHero (listHero LH);

void heroOfRole (adrR R) {
    adrE E = R->Relate.firstRelate;
    while (E != NULL) {
        adrH H = E->toHero;
        displayHero(H);
        E = E->nextRelate;
    }
}

void displayHeroOfRole (listRole LR) {
    int X;
    cout<<"Masukkan ID Role yang akan ditampilkan: "; cin>>X;
    adrR R = searchIDrole(LR,X);
    displayRole(R);
    cout<<"List Hero:"<<endl<<endl;
    heroOfRole(R);
}

void displayAll (listRole LR) {
    adrR R = LR.firstRole;
    while (R != NULL) {
        displayRole(R);
        cout<<"List Hero:"<<endl<<endl;
        heroOfRole(R);
        cout<<endl;
        R = R->nextRole;
    }
}


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


/** MISC */
bool duplicateCheckRole (listRole LR, adrR R) {
    adrR P = LR.firstRole;
    while (P != NULL) {
        if (P->IDr == R->IDr) {
            return true;
        }
        P = P->nextRole;
    }
    return true;
}

bool duplicateCheckHero (listHero LH, adrR H);
