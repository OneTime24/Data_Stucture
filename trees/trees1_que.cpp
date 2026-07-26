

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

        while(!q.empty()){
            p=q.front();
            q.pop();

            cout << "Enter left child of " << p->data << " (-1 for none): ";
            cin>>x;

            if(x!=-1){
                t=new Node;
                t->data=x;
                t->left=nullptr;
                t->right=nullptr;

                p->left=t;
                q.push(t);
            }

            cout << "Enter Right child of " << p->data << " (-1 for none): ";
            cin>>x;

            if(x!=-1){
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

int main(){

    Tree t;
    t.createtree();

    

}