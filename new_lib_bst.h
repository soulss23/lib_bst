using namespace std;
#include <iostream>

class Nodo{

    private:
    int data;
    int weight;
    Nodo*right;
    Nodo*left;

    public:

    Nodo(int k){
        data=k;
        weight=1;
        right=nullptr;
        left=nullptr;
    }

    Nodo* InsertR(int k){
        if(this==nullptr){
            return new Nodo(k);
        }

        if(this->data == k){
            this->weight++;
            return this;   //ritorna puntatore
        }

        if(k < this->data ){
            this->left = this->left->InsertR(k);
        }else{
            this->right = this->right->InsertR(k);
        } 
    
        return this;
    }

    void InOrder(){ //bst left root bst right 
        
        if(this->left!=NULL){
            this->left->InOrder();
            
        }

        cout<<this->data<<" ";

        if(this->right!=NULL){
            this->right->InOrder();
        }

    }
};
