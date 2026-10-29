// 6. Check for Balanced Parentheses 


#include <iostream>
#include <stack>
using namespace std;


void balanced(string s){

    stack<char> stk;
    int i=0;
    while(s[i]!='\0'){

        if(s[i]=='(' ||s[i]=='{' ||s[i]=='['){
            stk.push(s[i]);
            continue;
        }

        if(s[i]==')'||s[i]=='}'||s[i]==']'){

            if(stk.empty()){
                cout<<"Stack is emptry..."<<endl;

            }
            if(s[i]==')' && stk.top()=='('){
                stk.pop();
                continue;
            }

            if(s[i]=='}' && stk.top()=='{'){
                stk.pop();
                continue;
            }

            if(s[i]==']' && stk.top()=='['){
                stk.pop();
                continue;
            }
        }

    

        i++;
    }


    if(stk.empty()){
        cout<<"balanced..."<<endl;
        
    }else{
        cout<<"Not balanced..."<<endl;
    }
}
int main(){

    string s="[{()}]";
    balanced(s);
}