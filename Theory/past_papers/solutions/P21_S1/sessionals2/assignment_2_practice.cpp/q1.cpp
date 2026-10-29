#include <iostream>
using namespace std;

class stack{
    private:

    int *arr;
    int size;
    int top;

    public:

    stack(int sz){
        arr=new int[sz];
        size=sz;
        top=-1;
    }

    void push(int x){

        if(top==size-1){
            cout<<"Stack overflowed..."<<endl;
            return;
        }

        top++;
        *(arr+top)=x;
    }

    bool isEmpty(){
        return top==-1;
    }

    void pop(){

        if(top==-1){
            cout<<"Stack underflowed..."<<endl;
            return;
        }

        top--;
    }

    void peek(){

        if(top==-1){
            cout<<"Stack underflowed..."<<endl;
            return;
        }

        cout<<*(arr+top)<<endl;
    }

    ~stack(){
        delete[] arr;
    }
};