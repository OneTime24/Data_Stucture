

//balance parenthesis

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    cout<<"Enter expression.."<<endl;
    string str;
    getline(cin,str);

    stack<char> stk;
    int i=0;
    int bal=1;

    while(str[i]!='\0'){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            stk.push(str[i]);
            i++;
            continue;
        }

        if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if(stk.empty()){
                bal=0;
                break;
            }

            if(str[i]==')' && stk.top()=='('){
                stk.pop();
            }
            else if(str[i]=='}' && stk.top()=='{'){
                stk.pop();
            }
            else if(str[i]==']' && stk.top()=='['){
                stk.pop();
            }
            else{
                bal=0;
                break;
            }
        }

        i++;
    }

    if(stk.empty() && bal==1){
        cout<<"Balanced: ..."<<endl;
    }
    else{
        cout<<"NOT BALANCED..."<<endl;
    }
}
