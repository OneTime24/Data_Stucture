

#include <iostream>
#include <stack>
using namespace std;



stack<int> stk1;
stack<int> stk2;

void enqueue(int x){

    stk1.push(x);
}

void dequeue(){

    if(stk1.empty() && stk2.empty()){
        cout<<"Stack is empty.... "<<endl;
        return ;
    }

    if(stk2.empty()){
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }

       
    }
     cout<<stk2.top()<<endl;
        stk2.pop();
        return ;
}

int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    

    dequeue();

    dequeue();
    
    dequeue();

    dequeue();
}