


#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;


int preced(char ch){

    if(ch=='^') return 3;
    if(ch=='%' ||ch=='*'||ch=='/' ) return 2;
    if(ch=='+'||ch=='-') return 1;

return 0;
    
}

string to_postf(string str){

    stack<char> stk;
    string postf="";
    for(char c : str){

        if(isalnum(c)){
            postf+=c;
        }

        else if(c=='('){
            stk.push(c);
        }
        else if(c==')'){

            while(!stk.empty() && stk.top()!='('){
                postf+=stk.top();
                stk.pop();
            }

            if(!stk.empty()){
                stk.pop();
            }
        }
        else{


            while(!stk.empty() && preced(stk.top())>=preced(c)){

                postf+=stk.top();
                stk.pop();
            }

            stk.push(c);
        }
    }

    while(!stk.empty()){
        postf+=stk.top();
        stk.pop();
    }
    return postf;
}

int main(){


    string str;
    getline(cin,str);

    cout<<str<<endl;

    cout<<to_postf(str)<<endl;



}