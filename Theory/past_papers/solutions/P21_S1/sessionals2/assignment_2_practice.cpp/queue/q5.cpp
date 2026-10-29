
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void checkp(queue<int> q){

    int n=q.size();
    stack<int> s;
    queue<int> q2=q;

    while(!q.empty()){
        int t=q.front();
        q.pop();
        s.push(t);
    }

    while(!s.empty()){
        int t=s.top();
        s.pop();
        q.push(t);
    }

    int cnt=0;

    for(int i=0; i<n; i++){
        int t1=q.front();
        int t2=q2.front();

        if(t1==t2){
            cnt++;
        }

        q.pop();
        q2.pop();
    }

    if(cnt==n){
        cout<<"Palindrome..."<<endl;
    }else{
        cout<<"Not palindrome...."<<endl;
    }
}

int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(2);
    q.push(1);

    checkp(q);
}
