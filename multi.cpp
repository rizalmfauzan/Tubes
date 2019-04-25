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
    } else {
        cout<<"Duplicate ID"<<endl;
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

void deleteRole (listRole &LR) {
    int X;
    cout<<"Masukkan ID Role yang akan dihapus: "; cin>>X;
    adrR R = searchIDrole(LR,X);
    if (R != NULL) {
        while (R->Relate.firstRelate != NULL) {
            adrE E = R->Relate.firstRelate;
            deleteFirstRelation(R->Relate,E);
            deallocateRelation(E);
        }
        if (R == LR.firstRole) {
            deleteFirstRole(LR,R);
        } else if (R == LR.lastRole) {
            deleteLastRole(LR,R);
        } else {
            adrR P = LR.firstRole;
            while (P->nextRole != R) {
                P = P->nextRole;
            }
            deleteAfterRole(LR,P,R);
        }
    } else {
        cout<<"Role not found"<<endl;
    }
}


/** INSERT HERO */
void insertFirstHero (listHero &LH, adrH H) {
    if (LH.firstHero == NULL) {
        LH.firstHero = H;
        LH.lastHero = H;
    } else {
        H->nextHero = LH.firstHero;
        LH.firstHero = H;
    }
}

void insertLastHero (listHero &LH, adrH H) {
    if (LH.firstHero == NULL) {
        insertFirstHero(LH,H);
    } else {
        LH.lastHero->nextHero = H;
        LH.lastHero = H;
    }
}

void insertAfterHero (listHero &LH, adrH precH, adrH H) {
    if (precH == LH.lastHero) {
        insertLastHero(LH,H);
    } else {
        H->nextHero = precH->nextHero;
        precH->nextHero = H;
    }
}

void insertHero (listHero &LH) {
    int X;
    string nama;
    cout<<"Masukkan ID: "; cin>>X;
    cout<<"Masukkan nama Hero: "; cin>>nama;
    adrH H = heroAllocation(X,nama);
    if (!duplicateCheckHero(LH,H)) {
        if (LH.firstHero == NULL) {
            insertFirstHero(LH,H);
        } else {
            adrH P = LH.firstHero;
            while (P!= NULL && H->IDh > P->IDh) {
                P = P->nextHero;
            }
            if (P == LH.firstHero) {
                insertFirstHero(LH,H);
            } else if (P == NULL) {
                insertLastHero(LH,H);
            } else {
                adrH Q = LH.firstHero;
                while (Q->nextHero != P) {
                    Q = Q->nextHero;
                }
                insertAfterHero(LH,Q,H);
            }
        }
    } else {
        cout<<"Duplicate ID"<<endl;
    }
}


/** DELETE HERO */
void deleteFirstHero (listHero &LH, adrH &H) {
    if (LH.firstHero != NULL) {
        H = LH.firstHero;
        if (LH.firstHero == LH.lastHero) {
            LH.firstHero = NULL;
            LH.lastHero = NULL;
        } else {
            LH.firstHero = H->nextHero;
            H->nextHero = NULL;
        }
    }
}

void deleteLastHero (listHero &LH, adrH &H) {
    if (LH.firstHero != NULL) {
        H = LH.lastHero;
        if (LH.firstHero == LH.lastHero) {
            deleteFirstHero(LH,H);
        } else {
            adrH P = LH.firstHero;
            while (P->nextHero != LH.lastHero) {
                P = P->nextHero;
            }
            LH.lastHero = P;
            LH.lastHero->nextHero = NULL;
        }
    }
}

void deleteAfterHero (listHero &LH, adrH precH, adrH &H) {
    if (LH.firstHero != NULL && precH != LH.lastHero) {
        H = precH->nextHero;
        if (H == LH.lastHero) {
            deleteLastHero(LH,H);
        } else {
            precH->nextHero = H->nextHero;
            H->nextHero = NULL;
        }
    }
}

void deleteHero (listRole &LR, listHero &LH) {
    int X;
    cout<<"Masukkan ID Hero yang akan dihapus: "; cin>>X;
    cleanRelation(LR,X);
    adrH H = searchIDhero(LH,X);
    if (H != NULL) {
        if (H == LH.firstHero) {
            deleteFirstHero(LH,H);
        } else if (H == LH.lastHero) {
            deleteLastHero(LH,H);
        } else {
            adrH P = LH.firstHero;
            while (P->nextHero != H) {
                P = P->nextHero;
            }
            deleteAfterHero(LH,P,H);
        }
    } else {
        cout<<"Hero not found"<<endl;
    }
}

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

adrE searchRelation (adrR R, int IDhero) {
    adrE E = R->Relate.firstRelate;
    while (E != NULL) {
        adrH H = E->toHero;
        if (H->IDh == IDhero) {
            return E;
        }
        E = E->nextRelate;
    }
    return NULL;
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

void insertRelation (adrR &R, adrE E) {
    insertFirstRelation(R->Relate, E);
}


/** DELETE RELATION*/
void deleteFirstRelation (listRelation &LE, adrE &E) {
    if (LE.firstRelate != NULL) {
        E = LE.firstRelate;
        if (LE.firstRelate == LE.lastRelate) {
            LE.firstRelate = NULL;
            LE.lastRelate = NULL;
        } else {
            LE.firstRelate = E->nextRelate;
            E->nextRelate = NULL;
        }
    }
}

void deleteLastRelation (listRelation &LE, adrE &E) {
    if (LE.firstRelate != NULL) {
        E = LE.lastRelate;
        if (LE.firstRelate == LE.lastRelate) {
            deleteFirstRelation(LE,E);
        } else {
            adrE P = LE.firstRelate;
            while (P->nextRelate != LE.lastRelate) {
                P = P->nextRelate;
            }
            LE.lastRelate = P;
            LE.lastRelate->nextRelate = NULL;
        }
    }
}

void deleteAfterRelation (listRelation &LE, adrE precE, adrE &E) {
    if (LE.firstRelate != NULL && precE != LE.lastRelate) {
        E = precE->nextRelate;
        if (E == LE.lastRelate) {
            deleteLastRelation(LE,E);
        } else {
            precE->nextRelate = E->nextRelate;
            E->nextRelate = NULL;
        }
    }
}

void deleteRelation (adrR &R, adrE &E) {
    if (E == R->Relate.firstRelate) {
        deleteFirstRelation(R->Relate,E);
    } else if (E == R->Relate.lastRelate) {
        deleteLastRelation(R->Relate,E);
    } else {
        adrE P = R->Relate.firstRelate;
        while (P->nextRelate != E) {
            P = P->nextRelate;
        }
        deleteAfterRelation(R->Relate,P,E);
    }
}


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

void displayAllHero (listHero LH) {
    adrH H = LH.firstHero;
    cout<<"Hero List: "<<endl<<endl;
    while (H != NULL) {
        displayHero(H);
        H = H->nextHero;
    }
    cout<<endl;
}

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
void connection (listRole &LR, listHero LH) {
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

bool checkConnect (listRole LR) {
    int X, Y;
    cout<<"Masukkan ID Role: "; cin>>X;
    cout<<"Masukkan ID Hero: "; cin>>Y;
    adrR R = searchIDrole(LR,X);
    adrE E = searchRelation(R,Y);
    if (E != NULL) {
        return true;
    }
    return false;
}

void disConnect (listRole &LR) {
    int X, Y;
    cout<<"Masukkan ID Role: "; cin>>X;
    cout<<"Masukkan ID Hero: "; cin>>Y;
    adrR R = searchIDrole(LR,X);
    adrE E = searchRelation(R,Y);
    if (E != NULL) {
        deleteRelation(R,E);
        deallocateRelation(E);
    } else {
        cout<<"Relation not found"<<endl;
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
    return false;
}

bool duplicateCheckHero (listHero LH, adrH H) {
    adrH P = LH.firstHero;
    while (P != NULL) {
        if (P->IDh == H->IDh) {
            return true;
        }
        P = P->nextHero;
    }
    return false;
}

void cleanRelation (listRole &LR, int ID) {
    adrR R = LR.firstRole;
    while (R != NULL) {
        adrE E = R->Relate.firstRelate;
        while (E != NULL) {
            adrH H = E->toHero;
            if (H->IDh == ID) {
                deleteRelation(R,E);
                deallocateRelation(E);
            }
            E = E->nextRelate;
        }
        R = R->nextRole;
    }
}
