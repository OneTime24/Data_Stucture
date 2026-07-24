

#include <iostream>
using namespace std;


class queue{
  
    private:
    int front;
    int rear;
    int size;
    int *q;

    queue(int size){
        front=rear=-1;
        this->size=size;
        q=new int[size];
    }


    bool isEmpty(){
        return front==-1;
    }
    bool isFull(){
        
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
};
int main(){

}