#include <iostream>
#include <climits>
using namespace std;



class node{
    public:

    int data;

    node *left;
    node *right;

    node(int v){
        data=v;
        left=nullptr;
        right=nullptr;
    }
};


class tree{
    private:

    node *root;


    node* insert(node *root, int key){

        if(root==nullptr){ 
            root=new node(key);
            return root;
        }

        if(key<root->data){
            root->left=insert(root->left,key);
        }

        else if(key>root->data){
            root->right=insert(root->right,key);
        }

        return root;
        

    }


    node *success(node *root){

        while(root && root->left){
            root=root->left;
        }
        return root;
    }


    node *deleten(node *root, int key){

        if(root==nullptr){
            return nullptr;
        }


        if(key<root->data){
            root->left=deleten(root->left,key);
        }else if(key > root->data){
            root->right=deleten(root->right,key);
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


            node *suc=success(root->right);

            root->data=suc->data;

            root->right=deleten(root->right,suc->data);


        }
        return root;
    }

    bool isvalidBst(node *root, long long min=LLONG_MIN, long long max=LLONG_MAX){
        if(root==nullptr){
            return true;
        }
        if(root->data<=min || root->data>=max){
            return false;

        }

        return isvalidBst(root->left,min,root->data)&&isvalidBst(root->right,root->data,max);

    }

    int kthSmallest(node* root, int& k) {
        if (!root) return -1;

        int left = kthSmallest(root->left, k);
        if (k == 0) return left;

        k--;
        if (k == 0) return root->data;

        return kthSmallest(root->right, k);
    }

    void inorder(node *root){

        if(root==nullptr){
            return ;
        }
        inorder(root->left);


        cout<<root->data<<" ";
        inorder(root->right);
    }

    void destroy(node *root){
        if(root==nullptr) return;
        destroy(root->left);
        destroy(root->right);
        delete root;
    }


    public:

    tree(){
        root=nullptr;
    }

    ~tree(){
        destroy(root);
    }

    void insert(int key){
        root=insert(root,key);
    }

    void deleten(int key){
        root=deleten(root,key);
    }

    bool isvalidBst(){
        return isvalidBst(root);
    }

    int kthSmallest(int k){
        return kthSmallest(root,k);
    }

    void inorder(){
        inorder(root);
    }

};

int main(){


    tree t1;
    t1.insert(10);

    t1.insert(30);

    t1.insert(5);


    t1.insert(100);

    t1.inorder();
}