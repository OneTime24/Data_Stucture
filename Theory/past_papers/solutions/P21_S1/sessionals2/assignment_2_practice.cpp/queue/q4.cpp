#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void rever(queue<int> &q, int k){
    stack<int> s;
    int n=q.size();

    for(int i=0; i<k; i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    for(int i=0; i<n-k; i++){
        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    rever(q, 3);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}