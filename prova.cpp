#include <iostream>
#include "new lib_bst.h"
using namespace std;



int main(){

    int k{20};

    Nodo*root = new Nodo(k);

    root=root->InsertR(30);
    root=root->InsertR(10);
    root=root->InsertR(23);
    root = root-> InsertR(19);

    root->InOrder();

    return 0;
}