#include <iostream>
#include "new_lib_bst.h"
using namespace std;



int main(){

    
    Node *root=new Node(56);
    cout << "Nodo:" << root << endl;
    cin >> root;
    cout << "Valore del nodo:" << root << endl;


    root=root->InsertR(30);
    root=root->InsertR(10);
    root=root->InsertR(23);
    root = root-> InsertR(19);

    root->InOrder();
  
    return 0;
}