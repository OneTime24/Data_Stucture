


#include <iostream>
using namespace std;

class node{
    public:

    int data;
    node *left;
    node *right;

    node(int val){
        data=val;
    }

};


class tree{

    public:

    node* insert(node *root,int val){

        if(root==nullptr){
            return new node(val);
        }

        if(val<root->data){
            root->left=insert(root->left,val);
        }
        if(val>root->data){
            root->right=insert(root->right,val);
        }
        
        return root;
        

    }

    bool check_b(node *root) {
        if (root == nullptr) {
            return true;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }

        if (root->left != nullptr && root->right != nullptr) {
            return false;
        }

        return check_b(root->left) && check_b(root->right);
    }

    void inorder(node *root){

        if(root==nullptr){
            return ;
        }

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        // cout<<endl;
    }

    
};

int main(){

    node *root=nullptr;
    tree t1;
    root=t1.insert(root,5);

    root=t1.insert(root,3);

    root=t1.insert(root,7);

    root=t1.insert(root,1);

    // root=t1.insert(root,2);

    root=t1.insert(root,6);

    // root=t1.insert(root,9);


    t1.inorder(root);

    if(t1.check_b(root)){
        cout<<"TRUE";
    }else{
        cout<<"FALSE";
    }
}