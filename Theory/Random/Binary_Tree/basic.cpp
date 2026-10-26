
#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int info;
    node *left;
    node *right;

    node(int val)
    {
        info = val;
        left = NULL;
        right = NULL;
    }
};

// Insert a node while maintaining completeness
void insert(node *&root, int val)
{
    node *n = new node(val);

    if (root == NULL)
    {
        root = n;
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();

        if (curr->left == NULL)
        {
            curr->left = n;
            return;
        }
        else
            q.push(curr->left);

        if (curr->right == NULL)
        {
            curr->right = n;
            return;
        }
        else
            q.push(curr->right);
    }
}

// Search for a node by value
node* search(node *root, int val)
{
    if (root == NULL)
        return NULL;

    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();

        if (curr->info == val)
            return curr;

        if (curr->left != NULL)
            q.push(curr->left);

        if (curr->right != NULL)
            q.push(curr->right);
    }

    return NULL;
}

// Check whether the tree is complete
bool isComplete(node *root)
{
    if (root == NULL)
        return true;

    queue<node*> q;
    q.push(root);

    bool missing = false;

    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();

        if (curr->left != NULL)
        {
            if (missing)
                return false;

            q.push(curr->left);
        }
        else
            missing = true;

        if (curr->right != NULL)
        {
            if (missing)
                return false;

            q.push(curr->right);
        }
        else
            missing = true;
    }

    return true;
}

// Find the parent of a node
node* parent(node *curr, node *p, node *par)
{
    if (curr == NULL)
        return NULL;

    if (curr == p)
        return par;

    node *t = parent(curr->left, p, curr);

    if (t != NULL)
        return t;

    return parent(curr->right, p, curr);
}

// Find the sibling of a node
node* sibling(node *root, node *p)
{
    node *par = parent(root, p, NULL);

    if (par == NULL)
        return NULL;

    if (par->left == p)
        return par->right;

    return par->left;
}

// Find the level of a node (root level = 0)
int getLevel(node *root, int val, int level)
{
    if (root == NULL)
        return -1;

    if (root->info == val)
        return level;

    int left = getLevel(root->left, val, level + 1);

    if (left != -1)
        return left;

    return getLevel(root->right, val, level + 1);
}

// Find tree depth (measured in edges)
int maxDepth(node *root)
{
    if (root == NULL)
        return -1;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    if (left > right)
        return left + 1;

    return right + 1;
}

// Preorder: Root, Left, Right
void preOrder(node *root)
{
    if (root == NULL)
        return;

    cout << root->info << "\t";
    preOrder(root->left);
    preOrder(root->right);
}

// Inorder: Left, Root, Right
void inOrder(node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->info << "\t";
    inOrder(root->right);
}

// Postorder: Left, Right, Root
void postOrder(node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << "\t";
}

// Level-order traversal
void levelOrder(node *root)
{
    if (root == NULL)
        return;

    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();

        cout << curr->info << "\t";

        if (curr->left != NULL)
            q.push(curr->left);

        if (curr->right != NULL)
            q.push(curr->right);
    }
}

// Print the tree sideways
void printTree(node *root, int space = 0)
{
    if (root == NULL)
        return;

    space += 5;

    printTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->info << endl;

    printTree(root->left, space);
}

// Delete the entire tree
void deleteTree(node *root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}


void deleteNode(node *&root, int val)
{
    if (root == NULL)
        return;

    queue<node*> q;
    q.push(root);

    node *target = NULL;
    node *curr = NULL;
    node *lastParent = NULL;

    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        if (curr->info == val)
            target = curr;

        if (curr->left != NULL)
        {
            lastParent = curr;
            q.push(curr->left);
        }

        if (curr->right != NULL)
        {
            lastParent = curr;
            q.push(curr->right);
        }
    }

    // Value not found
    if (target == NULL)
        return;

    // Only one node in the tree
    if (curr == root)
    {
        delete root;
        root = NULL;
        return;
    }

    // Replace target value with last node's value
    target->info = curr->info;

    // Remove the last node
    if (lastParent->right == curr)
        lastParent->right = NULL;
    else
        lastParent->left = NULL;

    delete curr;
}


int main()
{
    node *root = NULL;

    // Insert nodes
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);

    cout << "Tree:" << endl;
    printTree(root);

    cout << "\nIs Complete: "
         << isComplete(root) << endl;

    cout << "\nPreorder: ";
    preOrder(root);

    cout << "\nInorder: ";
    inOrder(root);

    cout << "\nPostorder: ";
    postOrder(root);

    cout << "\nLevel Order: ";
    levelOrder(root);

    int val = 50;
    node *p = search(root, val);

    if (p != NULL)
    {
        cout << "\n\nFound: " << p->info;

        node *par = parent(root, p, NULL);

        if (par != NULL)
            cout << "\nParent: " << par->info;

        node *sib = sibling(root, p);

        if (sib != NULL)
            cout << "\nSibling: " << sib->info;
        else
            cout << "\nNo sibling";

        cout << "\nLevel: "
             << getLevel(root, val, 0) << endl;
    }
    else
        cout << "\nNode not found" << endl;

    cout << "Tree depth: " << maxDepth(root) << endl;

    deleteTree(root);
    root = NULL;

    return 0;
}
