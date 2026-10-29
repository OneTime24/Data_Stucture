#include <iostream>
using namespace std;

class queue{
    private:

    int *arr;
    int size;
    int f, r;

    public:

    queue(int sz){
        arr=new int[sz];
        size=sz;
        f=r=-1;
    }

    bool isEmpty(){
        return f==-1;
    }

    bool isFull(){
        return (r+1)%size==f;
    }

    void enqueue(int x){

        if(isFull()){
            cout<<"Queue overflowed..."<<endl;
            return;
        }

        if(isEmpty()){
            f=r=0;
        }
        else{
            r=(r+1)%size;
        }

        *(arr+r)=x;
    }

    void dequeue(){

        if(isEmpty()){
            cout<<"Queue underflowed..."<<endl;
            return;
        }

        cout<<"Dequeued: "<<*(arr+f)<<endl;

        if(f==r){
            f=r=-1;
        }
        else{
            f=(f+1)%size;
        }
    }

    void front(){

        if(isEmpty()){
            cout<<"Queue is empty..."<<endl;
            return;
        }

        cout<<*(arr+f)<<endl;
    }

    ~queue(){
        delete[] arr;
    }
};