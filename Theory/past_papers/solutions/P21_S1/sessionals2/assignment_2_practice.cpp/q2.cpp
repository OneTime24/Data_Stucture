#include <iostream>
using namespace std;

class node{
    public:

    int data;
    node *next;

    node(int v){
        data=v;
        next=nullptr;
    }
};

class staK{
    private:

    node *top;

    public:

    staK(){
        top=nullptr;
    }

    void push(int x){

        node *t=new node(x);

        t->next=top;
        top=t;
    }

    void pop(){

        if(top==nullptr){
            cout<<"Stack underflowed..."<<endl;
            return;
        }

        node *t=top;
        top=top->next;
        delete t;
    }

    void display(){

        node *curr=top;

        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }

        cout<<endl;
    }

    ~staK(){

        while(top!=nullptr){
            node *t=top;
            top=top->next;
            delete t;
        }
    }
};