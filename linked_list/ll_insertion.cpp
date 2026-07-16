


#include <iostream>

using namespace std;


struct Node{
    int data;
    Node *next;
};


void insert(Node *head){



}


int main(){

    Node *head;

    Node *n1=new Node;
    n1->data=1;
    head=n1;

    Node *n2=new Node;
    n2->data=2;
    n1=n2;

    Node *n3=new Node;
    n3->data=3;
    n2=n3;


    Node *n4=new Node;
    n4->data=4;
    n3=n4;

    insert(head);



}