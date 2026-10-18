
 // Campus help-desk simulator
// Use std::queue to model student requests. Each request has an ID, student name, and issue.
//  Allow adding requests, 
// serving the next request, viewing the next request, and listing the current waiting count.


#include <iostream>
#include <string>
#include <queue>
using namespace std;


struct request{

    int id;
    string name;
    string issue;
};

int main(){


    cout<<"Student Request......"<<endl;

    queue<request> q;

    int x;

    do{

    cout<<"\n----------------MENU----------------\n";
    cout<<"1.Do a request....\n2. Evaluate a request...\n3. View Front Request...\n4. View the count of request...\n5. Exit\n";

    cin>>x;

    switch(x){
        case 1:{
            request r1;
            int id;
            cout<<"Enter ID: ";
            cin>>id;
            r1.id=id;

            cin.ignore();
            string name;
            cout<<"Enter name: ";
            getline(cin,name);
            r1.name=name;

            string issue;
            cout<<"Enter issue: ";
            getline(cin,issue);
            r1.issue=issue;

            q.push(r1);
            break;
        }
        case 2:
            if (!q.empty()) {
            request tmp = q.front();
            cout << tmp.id << endl
                << tmp.name << endl
                << tmp.issue << endl;
            q.pop();
        }
        else {
            cout << "No requests to serve!\n";
        }
        break;

       case 3:
        if (!q.empty()) {
            request mp = q.front();
            cout << mp.id << endl
                << mp.name << endl
                << mp.issue << endl;
        }
        else {
            cout << "No requests waiting!\n";
        }
        break;

        case 4:
         cout << "Waiting requests: " << q.size() << endl;
        break;

        case 5:
            cout<<"Exiting...."<<endl;
            break;

        default:
            cout<<"Invalid Selection...."<<endl;
            
    }

    }while(x!=5);
}
