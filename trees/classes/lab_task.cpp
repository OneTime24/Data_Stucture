
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Node{
    Node *left;
    int data;
    Node *right;

};


class tree{

    private:
        Node *root;

        Node* makeNode(int x){

            Node *t=new Node;
            t->data=x;
            t->left=nullptr;

            t->right=nullptr;

            return t;
        }

        void inorder(Node *p){

            if(p){
                inorder(p->left);

                cout<<p->data<<" ";

                inorder(p->right);
            }
        }

        void preorder(Node *p)

        {


            if(p)
            {
                cout<<p->data<<" ";
                preorder(p->left);
                preorder(p->right);
            }

        }

        void postorder(Node *p){
            if (p){
                postorder(p->left);

                postorder(p->right);

                cout<<p->data<<" ";
            }
        }


        int count(Node *p){

            if(p==nullptr)
                return 0;
            return count(p->left) + count(p->right) + 1;
        }

        int leaves(Node *p){
            if(p==nullptr) return 0;

            if(p->left==nullptr && p->right==nullptr)

                return 1;

            return leaves(p->left)+leaves(p->right);

        }

        int height(Node *p){

            if(p==nullptr)
                return -1;
            int l=height(p->left);
            int r = height(p->right);

            if(l>r){
                return l+1;
            }else{
                return r+1;
            }
        }

        Node* deleteNode(Node *p,int key){

            if(p==nullptr){


                cout<<key<<" not found, nothing deleted\n";
                return nullptr;
            }

            if(key<p->data){
                p->left=deleteNode(p->left,key);
            }
            else if(key>p->data){
                p->right=deleteNode(p->right,key);

            }
            else{

                // case 1 leaf
                if(p->left==nullptr && p->right==nullptr){

                    cout<<"Case 1: leaf node "<<key<<" removed\n";
                    delete p;

                    return nullptr;
                }

                // case 2 one child
                if(p->left==nullptr){
                    cout<<"Case 2: one child node "<<key<<" removed\n";
                    Node *t=p->right;
                    delete p;
                    return t;
                }
                if(p->right==nullptr){
                    cout<<"Case 2: one child node "<<key<<" removed\n";
                  Node *t=p->left;
                    delete p;
                    return t;
                }

                // case 3 two children, take inorder successor

                cout<<"Case 3: two child node "<<key<<" removed\n";
                Node *s=p->right;
                while(s->left!=nullptr)
                    s=s->left;

                p->data=s->data;

                p->right=deleteNode(p->right,s->data);
            }
            return p;
        }


        void range(Node *p,int low,int high){
            if(p==nullptr)

                return;

            // go left only if p is bigger than low
            if(p->data>low)

                range(p->left,low,high);

            if(p->data>=low && p->data<=high)

                cout<<p->data<<" ";

            // go right only if p is smaller than high

            if(p->data < high)
                range(p->right,low,high);

        }

        bool check(Node *p,long long lo,long long hi){


            if(p==nullptr)
                return true;

            if(p->data<=lo || p->data>=hi)
                return false;

            return check(p->left,lo,p->data) && check(p->right,p->data,hi);

        }

    public:
        tree(){
            root=nullptr;
        }

        void insert(int x){
            if(root==nullptr){
                root=makeNode(x);
                return;
            }

            Node *p=root;
            Node *q=nullptr;

            while(p!=nullptr){
                q=p;
                if(x<p->data)

                    p=p->left;

                else if(x>p->data)


                    p=p->right;


                else{
                    cout<<x<<" already there, duplicate ignored\n";
                    return;
                }

            }
            if(x<q->data)
                q->left=makeNode(x);
            else
                q->right=makeNode(x);

        }

        bool search(int key){
            Node *p=root;
            while(p!=nullptr){
                if(key==p->data)
                    return true;

                else if(key<p->data)
                    p=p->left;
                else
                    p=p->right;
            }
            return false;
        }

        void inorder(){ inorder(root); cout<<endl; }

        void preorder(){
            preorder(root);

            cout<<endl;

        }

        void postorder(){ postorder(root); cout<<endl; }

        int count(){ return count(root); }

        int leaves(){return leaves(root);}
        int height(){ return height(root); }

        int minimum(){

            Node *p=root;

            while(p->left!=nullptr)

                p=p->left;

            return p->data;
        }

        int maximum(){

            Node *p = root;
            while(p->right!=nullptr)
                p = p->right;

            return p->data;


        }

        bool empty(){
            return root==nullptr;
        }

        void remove(int key){

            root=deleteNode(root,key);
        }

        void rangeQuery(int low,int high){
            range(root,low,high);
            cout<<endl;
        }

        bool isBST(){

            return check(root,LLONG_MIN,LLONG_MAX);

        }

        // any binary tree, level order, -1 = no child
        void createtree(){
            Node *p;
            Node *t;

            int x;

            queue<Node*> q;

            cout<<"Enter ROOT Value: ";

            cin>>x;
            root=makeNode(x);

            q.push(root);

            while(!q.empty()){
                p=q.front();

                q.pop();

                cout<<"Enter LEft Child of "<<p->data<<" Value: ";
                cin>>x;

                if(x!=-1){
                    t=makeNode(x);
                p->left=t;
                q.push(t);
                }
                cout<<"Enter Right Child of "<<p->data<<" Value: ";
                cin>>x;

                if(x!=-1){
                    t=makeNode(x);
                    p->right=t;
                    q.push(t);
            }


        }
        }

};



// prints inorder before and after delete
void demo(int arr[],int n,int key){
    tree t;
    for(int i=0;i<n;i++){
        t.insert(arr[i]);
    }

    cout<<"Inorder before: ";


    t.inorder();
    t.remove(key);
    cout<<"Inorder after : ";

    t.inorder();

    cout<<endl;
}


int main(){

    tree t;


    tree other;
    int ch,x,lo,hi;

    do{
        cout<<"\n---- BST MENU ----\n";
        cout<<"1.Insert\n2.Search\n3.Traversals\n4.Delete\n5.Deletion demo (3 cases)\n";
        cout<<"6.Measurements\n7.Range query\n8.isBST (this tree)\n9.isBST (make own binary tree)\n0.Exit\n";
        cout<<"Choice: ";
        cin>>ch;

        switch(ch){

            case 1:
                cout<<"Enter value: ";


                cin>>x;


                t.insert(x);

                break;

            case 2:

                cout<<"Enter value: ";
                cin>>x;
                if(t.search(x))
                    cout<<x<<" FOUND\n";
                else
                    cout<<x<<" NOT found\n";
                break;

            case 3:

                cout<<"Inorder  : ";
                t.inorder();
                cout<<"Preorder : ";
                t.preorder();
                cout<<"Postorder: ";
                t.postorder();

                break;

            case 4:
                cout<<"Enter value to delete: ";
                cin>>x;
                cout<<"Before: ";
                t.inorder();
                t.remove(x);
                cout<<"After : ";
                t.inorder();
                break;

            case 5:{

                int a[]={50,30,70,20,40,60,80};

                int b[]={50,30,70,20,60,80,10};

                cout<<"\n[Leaf] delete 20\n";

                demo(a,7,20);

                cout<<"[One child] delete 20 (only child is 10)\n";
                demo(b,7,20);

                cout<<"[Two children] delete 50 (root)\n";
                demo(a,7,50);

                break;
            }

            case 6:
                if(t.empty()){
                    cout<<"Tree is empty\n";
                    break;
                }

                cout<<"Nodes  : "<<t.count()<<endl;

                cout<<"Leaves : "<<t.leaves()<<endl;
                cout<<"Min    : "<<t.minimum()<<endl;
                cout<<"Max    : "<<t.maximum()<<endl;
                cout<<"Height : "<<t.height()<<" (counted in edges)"<<endl;
                break;

            case 7:
                cout<<"Enter low and high: ";
                cin>>lo>>hi;
                cout<<"Values in range: ";

                t.rangeQuery(lo,hi);


                break;

            case 8:
                if(t.isBST())


                    cout<<"Yes valid BST\n";
                else


                    cout<<"No, not a BST\n";
                break;

            case 9:

                other.createtree();
                if(other.isBST())
                    cout<<"Yes valid BST\n";
                else
                    cout<<"No, not a BST\n";
                break;

            case 0:
                cout<<"Bye\n";
                break;

            default:
                cout<<"Wrong choice\n";
        }

    }while(ch!=0);


}





//why can sorted insertion make a BST slow, and what kind of tree solves that problem?

//Sorted insertion makes a standard Binary Search Tree (BST) slow because inserting elements
//  in a pre-sorted or reverse-sorted order turns the tree into a linear tree
//  like a linked list instead of a making it structured of a tree