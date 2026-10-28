
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int val){
        data=val;
        left=right=nullptr;
    }
};

node *root=nullptr;

node *head=nullptr;
node *prevN=nullptr;

class tree{
    public:

    node* insert(node *root,int val){

        if(root==nullptr){
            return new node(val);
        }

        if(val<root->data){
            root->left=insert(root->left,val);
        }
        else if(val>root->data){
            root->right=insert(root->right,val);
        }
        else{
            cout<<"Duplicate ignored..."<<endl;
        }

        return root;
    }
};

void convert(node *root){

    if(root==nullptr){
        return;
    }

    convert(root->left);

    if(prevN==nullptr){
        head=root;
    }
    else{
        prevN->right=root;
        root->left=prevN;
    }

    prevN=root;

    convert(root->right);
}

void display(node *head){

    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->right;
    }
}

int main(){

    tree t;

    root=t.insert(root,4);
    root=t.insert(root,2);
    root=t.insert(root,6);
    root=t.insert(root,1);
    root=t.insert(root,3);
    root=t.insert(root,5);
    root=t.insert(root,7);

    convert(root);

    display(head);
}
