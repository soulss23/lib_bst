#include <iostream>
using namespace std;


struct nodo{

    int data;
    int weight;
    nodo*right;
    nodo*left;
    
    nodo(int val){
        weight=1;
        data=val;
        right=nullptr;
        left=nullptr;
    }
};



int height(nodo*r){

    if(r==NULL){
        return 0;
    }

    int l=height(r->left);
    int rc=height(r->right);

    return max(l,rc)+1;
}



nodo* InOrderTraversal (nodo*r){

    if(r==NULL){
        cout<<"L'albero è vuoto"<<endl;
    }else{
        
        if(r->left!=NULL){
            InOrderTraversal(r->left );
        }
        cout<<r->data<<" ";
        if(r->right!=NULL){
            InOrderTraversal(r->right );
        }
    }
    
    return r;
}




nodo* postOrder(nodo* r) {
    if (r == NULL) {
        return r;
    }

    postOrder(r->left);
    postOrder(r->right);

    cout << r->data << " ";

    return r;
}




nodo* preOrder(nodo* r) {

    if (r==NULL){
        return r;
    } 

    cout << r->data << " ";

    preOrder(r->left);

    preOrder(r->right);

    return r;
}




nodo* cancel_Iterattivo(nodo* r, int k) {
    nodo* current = r;
    nodo* parent = nullptr;

    
    while (current != nullptr) {
        if (current->data == k) {
            break;
        }
        parent = current;
        if (current->data > k) {    // Scorre il BST per trovare il nodo da cancellare 
            current = current->left;
        } else {
            current = current->right;
        }
    }

    
    if (current == nullptr) {
        cout << "Node not found" << endl; // Se il nodo non viene trovato
        return r;
    }

    if (current->left == nullptr && current->right == nullptr) {

        if (parent == nullptr) {
            r = nullptr;
        } else if (parent->left == current) {
            parent->left = nullptr;               // Case 1: Se il nodo e una foglia 
        } else {
            parent->right = nullptr;
        }

        delete current;

    }

        else if (current->left == nullptr) {

        if (parent == nullptr) {
            r = current->right;
        } else if (parent->left == current) {     // Case 2: Se il nodo ha un figlio
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }

        delete current;
        }
    return r;
    }




    nodo* cancel_Ricorsivo(nodo* r, int key){

    if(r==NULL){
        cout<<key<<"Il nodo inserito non esiste nell'BST."<<endl;
        return r;
    }

    if(r->data == key){
        if(r->left==NULL && r->right==NULL){

            delete r;
            r->data = 0;
            r->left = nullptr;
            r->right = nullptr;
            
            return r;
        }

        if(r->left==NULL){
            nodo* temp = r->right;
            delete r;
            r->data = 0;
            r->left = nullptr;
            r->right = nullptr;
            return temp;
        }

        if(r->right==NULL){
            nodo* temp = r->left;

            delete r;
            r->data = 0;
            r->left = nullptr;
            r->right = nullptr;

            return temp;
        }

        nodo* temp = r->right;
        r->data = temp->data;
        r->right = cancel_Ricorsivo(r->right, temp->data);
    }

    if(key<r->data){
        r->left = cancel_Ricorsivo(r->left, key);
    } else{
        r->right = cancel_Ricorsivo(r->right, key);
    }

    return r;
}




nodo* Insert_Iterattivo(nodo* r, int k){
    
    bool check {true};
    nodo* current {r};
    nodo* father {nullptr};

    while (check){
        if(current==NULL){

            if(father->data >k ){
                father->left = new nodo(k);
                check = false;
                return r;
            } else {
                father->right = new nodo(k);
                check = false;
                return r;
            }

        check = false;

        }
        if(current->data==k){
            check = false;
            current->weight++;
            return r;
        }
        if(current->data>k){

            father = current;
            current = current->left;

        } else {

            father = current;
            current = current->right;

        }
    }

    return r;
}




nodo*Insert_Ricorsivo( nodo*r , int k){
    if(r==NULL ){
        return new nodo(k);
    }

    if(r->data == k ){
        return r;
    }

    if(k <r->data ){
        r->left = Insert_Ricorsivo(r->left , k);
    }else{
        r->right = Insert_Ricorsivo (r->right, k);
    }

    return r;
}




nodo* Search_Iterattivo(nodo *r, int k){

    bool check {true};
    nodo* current {r};
    nodo* father {nullptr};
    
    while (check){
        if(current==NULL){
            cout << k<<" non presente all'interno dell'BST." << endl;
            check = false;
            break;
        }
        if(current->data==k){
            cout << k<<" presente all'interno dell'BST." << endl;
            check = false;
            break;
        }
        if(current->data>k){
            father = current;
            current = current->left;
        } else {
            father = current;
            current = current->right;
        }
    }

    return r;
}




nodo* Search_Ricorsivo (nodo *r , int k){

    if(r==NULL){
        cout<< k <<" non esiste nell'BST."<<endl;
        return r;
    }

    if(r->data == k){
        cout<< k <<" esiste nell'BST."<<endl;
        return r;
    }

    if(k< r->data){
        r->left = Search_Ricorsivo (r->left, k);
    } else{
        r->right = Search_Ricorsivo (r->right, k);
    }
    
    return r;
}
