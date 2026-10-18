#include <iostream>
#include <algorithm>
using namespace std;


class node{

    public:

    int data;

    node *left;
    node *right;

    node(int val){
        data=val;
        left=nullptr;  // Initialize left pointer
        right=nullptr; // Initialize right pointer
    }
};


node *root=nullptr;
class tree{
    private:


    public:

    node* insert(node *root,int val){

        if(root==nullptr){
            return new node(val);
        }

        if(val<root->data){
            root->left=insert(root->left,val);
        }else if(val>root->data){
            root->right=insert(root->right,val);
        }else{
            cout<<"Ignorairng duplicates...."<<endl;
        }

        return root; // Return updated root
    }

    bool search(node *root, int trg){

        node *curr=root;

        while(curr!=nullptr){ // Check nullptr before accessing data

            if(curr->data==trg){
                return true;
            }

            if(trg<curr->data){
                curr=curr->left;
            }else{
                curr=curr->right;
            }
        }

        return false;
    }
    int height(node *root){

        if(root==nullptr){
            return -1;
        }

        int lefT=height(root->left);
        int righT=height(root->right);

        return max(lefT,righT)+1; // Find maximum subtree height
    }


    node* findmin(node *root){
        if(root==nullptr){ // Compare instead of assigning
            return nullptr;
        }

        while(root->left!=nullptr){
            root=root->left;
        }
        return root;
    }
    node* remove(node* root, int val){

        if(root ==nullptr){
            return nullptr;
        }


        if(val<root->data){
            root->left=remove(root->left,val);
        }else if(val>root->data){
            root->right=remove(root->right,val);
        }else{

            if(root->left==nullptr){
                node *tmp=root->right;
                delete root;
                return tmp;

            }
            if(root->right==nullptr){
                node *tmp=root->left;
                delete root;
                return tmp;
            }


            node *tmp=findmin(root->right);
            root->data=tmp->data;
            root->right=remove(root->right,tmp->data); ///deleting the smallest inorder successor after changing node vlue...




        }

        return root; // Return updated root after deletion
    }

    void cleartree(node *root){

        if(root==nullptr){
            return ;
        }

        cleartree(root->left);
        cleartree(root->right);
        delete root;
    }
};
int main(){


    tree t1;
    root=t1.insert(root,5);
    root=t1.insert(root,4);
    root=t1.insert(root,3);

    root=t1.insert(root,2);

    root=t1.insert(root,7);

    root=t1.insert(root,9);

    root=t1.insert(root,6);

    cout<<"HEIGHT"<<t1.height(root)<<endl;

    if(t1.search(root,9)){
        cout<<"found...."<<endl;
    }else{
        cout<<"Not found...."<<endl;
    }


    root=t1.remove(root,9);

    root=t1.remove(root,5);

}