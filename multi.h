#ifndef MULTI_H_INCLUDED
#define MULTI_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct Parent *adrP;
typedef struct Child *adrC;
typedef struct Relation *adrR;

struct Parent {
    int ID;
    string tagName;
    adrP nextP;
    listRelation Relate;
};

struct Child {
    int IDc;
    string bookName;
    adrC nextC;
};

struct Relation {
    adrR nextR;
    adrC book;
};

struct listRelation {
    adrR firstR;
};

#endif // MULTI_H_INCLUDED
