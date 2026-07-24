

#include <iostream>
using namespace std;


class queue{
  
    private:
    int front;
    int rear;
    int size;
    int *q;

    public:

    queue(int size){
        front=rear=-1;
        this->size=size;
        q=new int[size];
    }


    bool isEmpty(){
        return front==-1;
    }
    bool isFull(){
        return (rear+1)%size==front;
    }

    void enqueue(int x){
        if(front==-1 && rear==-1){
            front=rear=0;
            q[rear]=x;
        }else if((rear+1)%size==front){
                cout<<"Overflow!!";
        }else{
            rear=(rear+1)%size;
            q[rear]=x;
        }
    }

    void dequeue(){
        if(front==-1){
            cout<<"Queue Underflowed: ";
        }else if(front==0 && rear==0){
            front=rear=0;
            cout<<"Queue empty now: ";
        }else{
            front=(front+1)%size;
            front++;
        }
    }
    void traverse(){

        for(int i=front;i<rear;i++){
            cout<<q[i]<<" ";
        }
    }
};
int main(){

 
    queue q1(5);

    q1.enqueue(1);
    q1.enqueue(2);

    q1.enqueue(3);
    q1.enqueue(4);

    q1.enqueue(5);
    // q1.enqueue(6);

    // q1.enqueue(7);
    // q1.enqueue(8);

    q1.traverse();
    
}