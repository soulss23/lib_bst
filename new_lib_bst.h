using namespace std;
#include <iostream>


class Node{

    private:
    int data;
    int weight;

    Node*right;
    Node*left;

    public:


    Node(int k){

        data=k;
        weight=1;
        right=nullptr;
        left=nullptr;
    }

    Node* InsertR(int k){
            if (k==this->data){
        this->weight++;
        return this;
    }
    if (k<this->data){
        if (this->left == NULL){
            this->left= new Node (k);
        } else{
            this->left= this->left->InsertR(k);
        }
    } else if (this->right== NULL){
        this->right= new Node(k);
    } else {
        this->right= this->right->InsertR(k);
    }
    return this;
    }

    Node* insertI(int k) {
    bool check {true};
    Node* current {this};
    Node* father {nullptr};

    while (check) {
        if (current == nullptr) {
            if (father->data > k) {
                father->left = new Node(k);
                check = false;
                return this;
            } else {
                father->right = new Node(k);
                check = false;
                return this;
            }
        }
        if (current->data == k) {
            check = false;
            current->weight++;
            return this;
        }
        if (current->data > k) {
            father = current;
            current = current->left;
        } else {
            father = current;
            current = current->right;
        }
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


    bool searchR(int k){ 

        if(this==nullptr){
            cout<<k<<" non trovato in BST."<<endl;
            return false;
        }

        if(this->data == k){
            cout<<k<<" trovato in BST."<<endl;
            return true;
        }

        if(k < this->data){
            return this->left->searchI(k);
        }else{
            return this->right->searchI(k);
        }
    }

    bool searchI(int k) { 

    Node* current = this;

    while (current != nullptr) {

        if (current->data == k) {
            cout<<k<<" trovato in BST."<<endl;
            return true;

        } else if (k < current->data) {
            current = current->left;

        } else {
            current = current->right;
        }
    }
    cout<<k<<" non trovato in BST."<<endl;
    return false; 
}

friend ostream& operator<<(ostream& o, const Node* node){
        o << node->data;
        return o;
    }

friend istream& operator>>(istream& i, Node* node){
        i >> node->data;
        return i;
    }

};


