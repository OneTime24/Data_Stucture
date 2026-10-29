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

class queue{
    private:

    node *front;
    node *rear;

    public:

    queue(){
        front=rear=nullptr;
    }

    bool isEmpty(){
        return front==nullptr;
    }

    void enqueue(int x){

        node *t=new node(x);

        if(front==nullptr){
            front=rear=t;
            return;
        }

        rear->next=t;
        rear=t;
    }

    void dequeue(){

        if(front==nullptr){
            cout<<"Queue underflowed..."<<endl;
            return;
        }

        node *t=front;

        cout<<"Dequeued: "<<front->data<<endl;

        front=front->next;

        if(front==nullptr){
            rear=nullptr;
        }

        delete t;
    }

    void display(){

        node *curr=front;

        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }

        cout<<endl;
    }

    void getFront(){

        if(front==nullptr){
            cout<<"Queue is empty..."<<endl;
            return;
        }

        cout<<front->data<<endl;
    }

    ~queue(){

        while(front!=nullptr){
            node *t=front;
            front=front->next;
            delete t;
        }

        rear=nullptr;
    }
};