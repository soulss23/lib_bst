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

    void InOrder(){ 
        
        if(this->left!=NULL){
            this->left->InOrder();
            
        }

        cout<<this->data<<" ";

        if(this->right!=NULL){
            this->right->InOrder();
        }

    }
    void PreOrder(){ 

        cout<<this->data<<" ";

        if(this->left!=NULL){
            this->left->PreOrder();
        }

        if(this->right!=NULL){
            this->right->PreOrder();
        }

    }
     void PostOrder(){ 
        
        if(this->left!=NULL){
            this->left->PostOrder();
        }

        if(this->right!=NULL){
            this->right->PostOrder();
        }

        cout<<this->data<<" ";
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

Node* deleteNode(int k){       //CANCEL

    if(this==NULL){
        cout<<k<<" non posso cancellarlo."<<endl;
        return this;
    }

    if(this->data == k){
        if(this->left==NULL && this->right==NULL){

            delete this;
            this->data = 0;
            this->left = nullptr;
            this->right = nullptr;
            
            return this;
        }

        if(this->left==NULL){
            Node* temp = this->right;
            delete this;
            this->data = 0;
            this->left = nullptr;
            this->right = nullptr;
            return temp;
        }

        if(this->right==NULL){
            Node* temp = this->left;

            delete this;
            this->data = 0;
            this->left = nullptr;
            this->right = nullptr;

            return temp;
        }

        Node* temp = this->right;
        this->data = temp->data;
        this->right = deleteNode(temp->data);
    }

    if(k<this->data){
        this->left = this->left -> deleteNode(k);
    } else{
        this->right = this->right -> deleteNode(k);
    }

    return this;
}

bool isBst(){

    if(this==NULL){
        return true;
    }
    
    if(this->left!=NULL && this->left->data<this->data){
        return this->left->isBst();
    }else if(this->left!=NULL && this->left->data>this->data){
        return false;
    }

    if(this->right!=NULL && this->right->data>this->data){
        return this->right->isBst();
    }else if(this->right!=NULL && this->right->data<this->data){
        return false;
    }

    return true;
}

friend ostream &operator<<(ostream &os, Node *root){
        os << "dato della root" << root->data <<endl;
        os << "peso della root" << root->weight <<endl;
        return os;
    }

    friend istream &operator>>(istream &is, Node*root){
        int value;
        is >> value;
        return is;
    }
    
};


