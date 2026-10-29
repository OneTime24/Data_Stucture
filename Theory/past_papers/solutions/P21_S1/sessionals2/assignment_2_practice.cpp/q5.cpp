#include <iostream>

#include <stack>
using namespace std;

void stk_pop(stack<int> &s, int cnt){

    if(cnt==0){
        
        s.pop();
        return;
    }

    int t=s.top();
    s.pop();

    stk_pop(s,cnt-1);

    s.push(t);
}

int main(){

    stack<int> stk;

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    stk_pop(stk,stk.size()/2);

    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }

    return 0;
}