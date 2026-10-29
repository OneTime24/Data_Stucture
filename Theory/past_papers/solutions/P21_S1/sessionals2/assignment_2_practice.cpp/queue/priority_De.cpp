#include <iostream>
using namespace std;

class node{
    public:
    int data;
    int priority;

    node(){
    data=0;
    priority=0;
}
    node(int d, int p){
        data=d;
        priority=p;
    }
};

class pqueue{
    private:

    node *arr;
    int size;
    int rear;

    public:

    
    pqueue(int sz){
        arr=new node[sz]{};
        size=sz;
        rear=-1;
    }

    void enqueue(int x, int p){

        if(rear==size-1){
            cout<<"Queue overflowed..."<<endl;
            return;
        }

        rear++;
        arr[rear].data=x;
        arr[rear].priority=p;
    }

    void dequeue(){

        if(rear==-1){
            cout<<"Queue underflowed..."<<endl;
            return;
        }

        int pos=0;

        for(int i=1; i<=rear; i++){
            if(arr[i].priority<arr[pos].priority){
                pos=i;
            }
        }

        cout<<"Dequeued: "<<arr[pos].data<<endl;

        for(int i=pos; i<rear; i++){
            arr[i]=arr[i+1];
        }

        rear--;
    }

    void display(){

        for(int i=0; i<=rear; i++){
            cout<<arr[i].data<<" ("<<arr[i].priority<<") ";
        }

        cout<<endl;
    }

    ~pqueue(){
        delete[] arr;
    }
};

int main(){

    pqueue q(5);

    q.enqueue(10,3);
    q.enqueue(20,1);
    q.enqueue(30,2);
    q.enqueue(40,1);

    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    return 0;
}