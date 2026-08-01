

#include <iostream>
#include <queue>
using namespace std;


struct Node{
    Node *left;
    int data;
    Node *right;
};



Node *root;


class tree{

    public:

    tree(){
        root=nullptr;
    }

    void createtree(){
        Node *p;
        Node *t;

        int x;

        cout<<"Enter root value: ";
        cin>>x;

        root=new Node;
        root->data=x;
        root->left=nullptr;
        root->right=nullptr;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            p=new Node;
            p=q.front();
            q.pop();

            cout<<"Enter left child of "<<root->data<<" value: ";
            cin>>x;
            
            while(x!=-1){
                t=new Node;
                t->data=x;
                t->left=nullptr;
                t->right=nullptr;

                p->left=t;
                q.push(t);
            }


            cout<<"Enter RIght child of "<<root->data<<" value: ";
            cin>>x;
            
            while(x!=-1){
                t=new Node;
                t->data=x;
                t->left=nullptr;
                t->right=nullptr;

                p->right=t;
                q.push(t);
            }

        }

    }
};