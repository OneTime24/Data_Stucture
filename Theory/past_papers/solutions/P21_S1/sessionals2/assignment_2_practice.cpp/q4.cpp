#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &s, int x){

    if(s.empty() || s.top() >= x){
        s.push(x);
        return;
    }

    int t=s.top();
    s.pop();

    insert(s,x);

    s.push(t);
}

void sort(stack<int> &s){

    if(s.empty()){
        return;
    }

    int t=s.top();
    s.pop();

    sort(s);

    insert(s,t);
}

int main(){

    stack<int> s;

    s.push(3);
    s.push(5);
    s.push(1);
    s.push(4);
    s.push(2);

    sort(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}