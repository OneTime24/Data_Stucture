
#include <iostream>
#include <string>
using namespace std;

const int cap=8;

int main(){

    string arr[cap];
    int front=0,rear=-1,count=0;

    while(true){

        int x;

        cout<<"\n1. Issue a token\n2. Serve next customer\n3. View front and rear\n4. Cancel customer at position p\n5. Display queue\n6. Exit\n";
        cin>>x;

        switch(x){

            case 1:{
                if(count==cap){
                    cout<<"Queue full\n";
                    break;
                }

                string name;
                cout<<"Enter customer name: ";
                cin.ignore();
                getline(cin,name);

                rear=(rear+1)%cap;
                arr[rear]=name;
                count++;

                cout<<"Token issued\n";
                break;
            }

            case 2:{
                if(count==0){
                    cout<<"Queue empty\n";
                    break;
                }

                cout<<"Serving: "<<arr[front]<<endl;

                front=(front+1)%cap;
                count--;

                if(count==0){
                    front=0;
                    rear=-1;
                }

                break;
            }

            case 3:{
                if(count==0){
                    cout<<"Queue empty\n";
                    break;
                }

                cout<<"Front customer: "<<arr[front]<<endl;
                cout<<"Rear customer: "<<arr[rear]<<endl;
                break;
            }

            case 4:{
                if(count==0){
                    cout<<"Queue empty\n";
                    break;
                }

                int p;
                cout<<"Enter position to cancel (1 to "<<count<<"): ";
                cin>>p;

                if(p<1 || p>count){
                    cout<<"Invalid position\n";
                    break;
                }

                int idx=(front+p-1)%cap;

                for(int i=p-1;i<count-1;i++){
                    int curr=(front+i)%cap;
                    int next=(front+i+1)%cap;

                    arr[curr]=arr[next];
                }

                rear=(rear-1+cap)%cap;
                count--;

                if(count==0){
                    front=0;
                    rear=-1;
                }

                cout<<"Customer cancelled\n";
                break;
            }

            case 5:{
                if(count==0){
                    cout<<"Queue empty\n";
                    break;
                }

                cout<<"Customers in service order: ";

                for(int i=0;i<count;i++){
                    cout<<arr[(front+i)%cap]<<" ";
                }

                cout<<"\nSize: "<<count;
                cout<<"\nFree slots: "<<cap-count<<endl;
                break;
            }

            case 6:{
                return 0;
            }

            default:
                cout<<"Invalid choice\n";
        }
    }
}

/*
Sample run:

Issue A, B, C, D, E, F, G, H.
Queue is full:
[A, B, C, D, E, F, G, H]

Serve A, then B, then C.
front moves forward.

Issue I, J, K.
The queue wraps around to the beginning of the array.

Service order:
D E F G H I J K

Cancel position 3 (F):
D E G H I J K

Size: 7
Free slots: 1
*/
