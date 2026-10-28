

#include <iostream>
#include <stack>
#include <queue>
using namespace std;


void reverseE(queue<int> &q){

    int n=q.size();
    if(n<=1){
        return ;
    }

    stack<int> stk;

    for(int i=1;i<=n;i++){
        
        int val=q.front();
        q.pop();

        if(i%2==0){
            stk.push(val);
        }else{
            q.push(val);
        }
    }
    
    for(int i=1;i<=n;i++){
        int val=q.front();
        q.pop();

        if(i%2==1){
            q.push(val);
        }else{
            q.push(stk.top());
            stk.pop();
        }
    }
}


int main(){

}


