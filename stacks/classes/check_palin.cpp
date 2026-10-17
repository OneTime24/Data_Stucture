

#include <iostream>
#include <stack>
#include <string>
using namespace std;



void is_palin(string str){

    string str1=str;
    string str2="";
    stack<char> stk;

    for(char c :str1){

        stk.push(c);
    }
    while(!stk.empty()){
        str2+=stk.top();
        stk.pop();
    }

    int len=str1.length();
    int bf=0;
    for(int i=0;i<len;i++){
        if(str1[i]==str2[i]){
            bf++;
        }
    }
    if(bf==len){
        cout<<"Palindrome..."<<endl;
    }else{
        cout<<"Not palidrome..."<<endl;
    }
}
int main(){

    string str;
    getline(cin,str);

    is_palin(str);

}