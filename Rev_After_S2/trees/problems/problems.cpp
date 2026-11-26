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


    public:
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




    int sum_leaf(node *root){

        if(root==nullptr){
            return 0;
        }

        if(root->left==nullptr && root->right==nullptr){
            return root->data;
        }

        int lfs=sum_leaf(root->left);
        int rts=sum_leaf(root->right);

        return lfs+rts;
    }

    int count_at_level(node *root, int level){
        if(root==nullptr){
            return 0;
        }

        if(level==0){
            return 1;
        }

        int lhs=count_at_level(root->left,level-1);

        int rhs=count_at_level(root->right,level-1);
        return lhs+rhs;


    }


    int sum_at_level(node *root, int level){
        if(root==nullptr){
            return 0;
        }
        if(level==0){
            return root->data;
        }

        int lhs=sum_at_level(root->left,level-1);
        int rhs=sum_at_level(root->right,level-1);

        return lhs+rhs;
    }

    int total_nodes(node *root){

        if(root==nullptr){
            return 0;
        }

        int lhs=total_nodes(root->left);

        int rhs=total_nodes(root->right);


        return 1+lhs+rhs;
    }


    int get_height(node *root){

        if(root==nullptr){
            return -1;
        }

        int lhs=get_height(root->left);

        int rhs=get_height(root->right);

        if(lhs<rhs){
            return 1+rhs;
        }else{
            return 1+rhs;
        }
    }

    int find_max(node *root){

        if(root==nullptr){
            return INT_MIN;

        }

        int lhs=find_max(root->left);
        int rhs=find_max(root->right);

        int best=root->data;

        if(lhs>best){
            return lhs;
        }

        if(rhs>best){
            return rhs;
        }

        return best;
    }


    int find_min(node *root){

        if(root==nullptr){
            return INT_MAX;
        }

        int lhs=find_min(root->left);
        int rhs=find_min(root->right);

        int best=root->data;
        if(lhs<best){
            return lhs;
        }
        if(rhs<best){
            return rhs;
        }
        return best;
    }


    void printPath(node *root, int path[],int len){

        if(root==nullptr){
            return ;
        }
        path[len++]=root->data;

        if(root->left==nullptr && root->right==nullptr){
            for(int i=0;i<len;i++){
                cout<<path[i]<<" ";
            }
             cout<<endl;
                return ;


        }

        printPath(root->left, path, len);
        printPath(root->right, path, len);
               
    }
    void printPathSpecific(node *root, int path[], int len, int val){
        if(root==nullptr){
            return ;
        }


         if(val==root->data){
            for(int i=0;i<len;i++){
                cout<<path[i]<<" ";
            }

        cout<<endl;
        return ;
            
        }

        if(val<root->data){
            path[len++]=root->data;
            printPathSpecific(root->left,path, len, val);
        }else if(val>root->data){
            path[len++]=root->data;
            printPathSpecific(root->right,path, len, val);
        }

       

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



    tree(){
        root=nullptr;
    }


    
    node *getroot(){
        return root;
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

    node *root=t1.getroot();

    cout<<"Total Nodes: "<<t1.total_nodes(root)<<endl;

    cout<<"Height: "<<t1.get_height(root)<<endl;


}