

#include <iostream>
using namespace std;
class node{
    public:
    int data;

    node *left;
    node *right;

    node(int val){
        data=val;
        left=right=nullptr;
    }
};

class tree{
    public:

    node *insert(node *root,int val){
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
int count(node *root, int rootVal = -1) {
    // 1. Base case: if the node doesn't exist, add 0
    if (root == nullptr) {
        return 0;
    }

    // 2. On the very first call from main, rootVal will be -1. 
    // Capture the root node's value here!
    if (rootVal == -1) {
        rootVal = root->data;
    }

    // 3. Check if current node's value divides the root's value
    int match = 0;
    if (root->data != 0 && rootVal % root->data == 0) {
        match = 1;
    }

    // 4. Return current match + recursive counts from left and right children
    return match + count(root->left, rootVal) + count(root->right, rootVal);
}
};
int main(){



}