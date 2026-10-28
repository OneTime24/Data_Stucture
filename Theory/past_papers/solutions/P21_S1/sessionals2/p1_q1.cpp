


#include <iostream>
using namespace std;


int lft,rgt=0;
class node{
    public:

    int data;
    node *left;
    node *right;


    node(int val){
        data= val;
        left=right=nullptr;
    }
    
};


class tree{

    public:

    node* insert(node *&root,int val){

        if(root==nullptr){
            return new node(val);
        }

        if(val<root->data){
            root->left=insert(root->left,val);
        }
        if(val>root->data){
            root->right=insert(root->right,val);
        }else{
            cout<<"Ignoroing duplicates....";
        }
        
        return root;

    }

    void count_nodes(node *root){
        

        if(root==nullptr){
            return ;
        }
        if(root->left!=nullptr && root->right==nullptr){
            lft++;
        }
        // if(root!=nullptr){
        //     count_nodes(root->left);
        // }
        if(root->left==nullptr && root->right!=nullptr){
            rgt++;
        }

        // if(root!=nullptr){
        //     count_nodes(root->right);
        // }

        count_nodes(root->left);
        count_nodes(root->right);
        
    }


};



int main(){

}