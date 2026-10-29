
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char ch){

    if(ch=='+' || ch=='-'){
        return 1;
    }

    if(ch=='*' || ch=='/'){
        return 2;
    }

    return 0;
}

int main(){

    stack<char> s;
    string infix;
    string postfix="";

    cout<<"Enter infix expression: ";
    cin>>infix;

    // Input: A+B*C

    for(int i=0; i<infix.length(); i++){

        char ch=infix[i];

        if((ch>='A' && ch<='Z') ||
           (ch>='a' && ch<='z') ||
           (ch>='0' && ch<='9')){

            postfix=postfix+ch;
            // A -> postfix: A

        }

        else if(ch=='('){
            s.push(ch);
        }

        else if(ch==')'){

            while(!s.empty() && s.top()!='('){
                postfix=postfix+s.top();
                s.pop();
            }

            if(!s.empty()){
                s.pop();
            }
        }

        else{

            while(!s.empty() && s.top()!='(' &&
                  priority(s.top())>=priority(ch)){

                postfix=postfix+s.top();
                s.pop();
            }

            s.push(ch);
        }

        // After A:   Stack: empty   Postfix: A
        // After +:   Stack: +       Postfix: A
        // After B:   Stack: +       Postfix: AB
        // After *:   Stack: + *     Postfix: AB
        // After C:   Stack: + *     Postfix: ABC
    }

    while(!s.empty()){
        postfix=postfix+s.top();
        s.pop();
    }

    // Pop * -> ABC*
    // Pop + -> ABC*+

    cout<<"Postfix: "<<postfix<<endl;

    return 0;
}
