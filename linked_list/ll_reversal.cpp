

#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
};

void traversal(Node *head){
    Node *n=head;

    while(n!=nullptr){
        cout<<n->data<<" ";
        n=n->next;
    }
}

void reversal(Node *&head){
    Node *n=head;

    Node *prev=nullptr;
    Node *curr=head;
    Node *next=nullptr;


    while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
}
Node *head=nullptr;
Node *last=nullptr;
void Insert(int pos, int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;

    // Case 1: Empty list
    if (head == nullptr)
    {
        head = last = t;
        return;
    }

    // Case 2: Insert at beginning
    if (pos == 0)
    {
        t->next = head;
        head = t;
        return;
    }

    // Case 3: Insert at any other position
    Node *p = head;

    for (int i = 0; i < pos - 1 && p != nullptr; i++)
    {
        p = p->next;
    }

    if (p != nullptr)
    {
        t->next = p->next;
        p->next = t;

        // If inserted at the end, update last
        if (t->next == nullptr)
            last = t;
    }
}
int main(){


    Insert(0,1);


    Insert(1,2);


    Insert(2,3);


    Insert(3,4);


    traversal(head);
}