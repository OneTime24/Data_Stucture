

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *top=nullptr;

void push(int x){
    Node *t=new Node;

    if(t==nullptr){
        cout<<"Stack OVerflowed: ";

    }else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop(){
    if(top==nullptr){
        cout<<"Stack Underflowed: ";
    }

    Node *p=top;
    int x=p->data;

    top=top->next;
    delete p;

    return x;
}


int peek(){
    if(top==nullptr){
        return -1;
    }else{
        return top->data;
    }
}

bool isEmpty(){

    return top==nullptr;
}


int main(){

    Node *head=new Node;
    Node *n1;
    n1->data=10;
    head->next=n1;

    Node *n2;
    n2->data=20;
    n1->next=n2;

    Node *n3;
    n3->data=20;
    n2->next=n3;

    Node *n4;
    n4->data=20;
    n3->next=n4;


    
}