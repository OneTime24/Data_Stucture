

// //hieght of a node:


// #include <iostream>
// #include <algorithm>
// using namespace std;

// class node{
//     public:
//     int data;
//     node *left;
//     node *right;

//     node(int v){
//         data=v;
//         left=nullptr;
//         right=nullptr;
//     }
// };

// class tree{
//     public:

//     node* insert(node *root, int v){

//         if(root==nullptr){
//             return new node(v);
//         }

//         if(v<root->data){
//             root->left=insert(root->left,v);
//         }
//         if(v>root->data){
//             root->right=insert(root->right,v);
//         }

//         return root;
//     }


//     int height(node *root){
        
//         if(root==nullptr){
//             return 0;
//         }

//         int l=height(root->left);
//         int r=height(root->right);

//         if(l<r){
//             return 1+r;
//         }else{
//             return 1+l;
//         }

//     }


//     int leaf(node *root){

//     if(root==nullptr){
//         return 0;
//     }

//     if(root->left==nullptr && root->right==nullptr){
//         return 1;
//     }

//     return leaf(root->left)+leaf(root->right);
// }

// int nonleaf(node *root){

//     if(root==nullptr){
//         return 0;
//     }

//     if(root->left==nullptr && root->right==nullptr){
//         return 0;
//     }

//     return 1+nonleaf(root->left)+nonleaf(root->right);
// }
   
// };





#include <iostream>
#include <queue>
using namespace std;


class node{
    public:
    int data;
    node *left;
    node *right;

    node(int v){
        data=v;
        left=right=nullptr;
    }


};


class tree{
    public:

    node *insert(node *root,int v){

        if(root==nullptr){
            return new node(v);
        }

        if(v<root->data){
            root->left=insert(root->left,v);
        }

        if(v>root->data){
            root->right=insert(root->right,v);
        }

        
        return root;
    }


    node *findmin(node *root){
        while(root && root->left !=nullptr){
            root=root->left;
        }
        return root;
    }
    node *delet(node *root, int v){

    if(root==nullptr){
        return nullptr;
    }

    if(v<root->data){
        root->left=delet(root->left,v);
    }
    else if(v>root->data){
        root->right=delet(root->right,v);
    }
    else{

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

        node *min=findmin(root->right);
        root->data=min->data;
        root->right=delet(root->right,min->data);
    }

    return root;
}

int longestPathNodes(node* root) {
    // Base case: if the node is null, path length is 0
    if (root == nullptr) {
        return 0;
    }
    
    // Recursively find the longest path in the left and right subtrees
    int leftPath = longestPathNodes(root->left);
    int rightPath = longestPathNodes(root->right);
    
    // Return 1 (for the current node) + the maximum of left or right path
    return 1 + max(leftPath, rightPath);
}

    int findHeight(node *root){
        if(root==nullptr){
            return 0;
        }

        int l=findHeight(root->left);
        
        int r=findHeight(root->right);

        if(l<r){
            return 1+r;
        }else{
            return 1+l;
        }
    }



    int count_leaf(node *root){
        if(root==nullptr){
            return 0;
        }

        if(root->left==nullptr && root->right==nullptr){
            return 1;
        }

        return count_leaf(root->left)+count_leaf(root->right);
    }

    int non_leaf(node *root){
        if(root==nullptr)
            return 0;

        if(root->left==nullptr && root->right==nullptr){
            return 0;
        }
        return 1+non_leaf(root->left)+non_leaf(root->right);
    }

   void find_p(node *root, int v){

    if(root==nullptr){
        return;
    }

    cout<<root->data<<" ";

    if(v<root->data){
        find_p(root->left,v);
    }
    else if(v>root->data){
        find_p(root->right,v);
    }
}

    int left_leaf_sum(node *root){

    if(root==nullptr){
        return 0;
    }

    int sum=0;

    if(root->left!=nullptr &&
       root->left->left==nullptr &&
       root->left->right==nullptr){
        sum+=root->left->data;
    }

    sum+=left_leaf_sum(root->left);
    sum+=left_leaf_sum(root->right);

    return sum;
}
bool print_ances(node *root,int v){

    if(root==nullptr){
        return false;
    }

    if(root->data==v){
        return true;
    }

    if(print_ances(root->left,v) ||
       print_ances(root->right,v)){
        cout<<root->data<<" ";
        return true;
    }

    return false;
}

void level_order(node *root){

    if(root==nullptr){
        return;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        node *temp=q.front();
        q.pop();

        cout<<temp->data<<" ";

        if(temp->left!=nullptr){
            q.push(temp->left);
        }

        if(temp->right!=nullptr){
            q.push(temp->right);
        }
    }
}
bool isBST(node *root, int min, int max){

    if(root==nullptr){
        return true;
    }

    if(root->data<=min || root->data>=max){
        return false;
    }

    return isBST(root->left,min,root->data) &&
           isBST(root->right,root->data,max);
}
};

int main(){

}