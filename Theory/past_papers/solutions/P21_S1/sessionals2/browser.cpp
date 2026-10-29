#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack<string> backStack;
    stack<string> forwardStack;

    string currentPage="Google";
    int choice;
    string page;

    while(true){

        cout<<"\nCurrent Page: "<<currentPage<<endl;
        cout<<"1. Visit Page"<<endl;
        cout<<"2. Back"<<endl;
        cout<<"3. Forward"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1){

            cout<<"Enter page: ";
            cin>>page;

            backStack.push(currentPage);
            currentPage=page;

            while(!forwardStack.empty()){
                forwardStack.pop();
            }
        }

        else if(choice==2){

            if(backStack.empty()){
                cout<<"No previous page!"<<endl;
            }
            else{
                forwardStack.push(currentPage);
                currentPage=backStack.top();
                backStack.pop();
            }
        }

        else if(choice==3){

            if(forwardStack.empty()){
                cout<<"No forward page!"<<endl;
            }
            else{
                backStack.push(currentPage);
                currentPage=forwardStack.top();
                forwardStack.pop();
            }
        }

        else if(choice==4){
            break;
        }

    }

    return 0;
}