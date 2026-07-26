

#include <iostream>
#include <queue>
using namespace std;

struct Node{
    Node *left;
    int data;
    Node *right;
};

class Tree{

    private:
        Node *root;

    public:

        Tree(){
            root=nullptr;
        }

        void createtree(){
            
            Node *p;
            Node *t;
            int x;

            queue<Node*> q;
            cout<<"Enter ROOT VLUE: ";
            cin>>x;

            root=new Node;

            root->data=x;
            root->left=nullptr;
            root->right=nullptr;

            q.push(root);
        }

};

int main(){


}