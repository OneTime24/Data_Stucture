

#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
};




int main(){

    Node *head=new Node;

    Node *n1=new Node;
    n1->data=1;
    
    Node *n2=new Node;
    n2->data=2;
    n1->next=n2;

    Node *n3=new Node;
    n3->data=3;
    n2->next=n3;


    Node *n4=new Node;
    n4->data=4;
    n3->next=n4;



    

    
    
    
}