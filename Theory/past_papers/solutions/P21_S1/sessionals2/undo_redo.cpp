#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack<string> undoStack;
    stack<string> redoStack;

    string text="";
    string oldText;
    int choice;
    char ch;

    while(true){

        cout<<"\nCurrent Text: "<<text<<endl;
        cout<<"1. Type Character"<<endl;
        cout<<"2. Undo"<<endl;
        cout<<"3. Redo"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1){

            cout<<"Enter character: ";
            cin>>ch;

            undoStack.push(text);
            text=text+ch;

            while(!redoStack.empty()){
                redoStack.pop();
            }
        }

        else if(choice==2){

            if(undoStack.empty()){
                cout<<"Nothing to undo!"<<endl;
            }
            else{
                redoStack.push(text);
                text=undoStack.top();
                undoStack.pop();
            }
        }

        else if(choice==3){

            if(redoStack.empty()){
                cout<<"Nothing to redo!"<<endl;
            }
            else{
                undoStack.push(text);
                text=redoStack.top();
                redoStack.pop();
            }
        }

        else if(choice==4){
            break;
        }

    }

    return 0;
}