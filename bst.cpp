#include <iostream>
#include "functions.h"
using namespace std;


int main(){
    
    nodo*root = new nodo (50);

    root = Insert_Ricorsivo ( root , 49);
    root = Insert_Ricorsivo ( root , 35);
    root = Insert_Ricorsivo ( root , 94);
    root = Insert_Ricorsivo ( root , 13);
    root = Insert_Ricorsivo ( root , 10);

    cout<<"Inserire il nodo da cercare all'interno dell'BST"<<endl;

    int n;
    cin>>n;

    Search_Ricorsivo(root,n);
    
    cout<<"BST aggiornato."<<endl;

    return 0;
}