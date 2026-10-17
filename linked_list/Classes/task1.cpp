// Problem 1 — The Broken Chain
// Input:
// The first line contains N (1 ≤ N ≤ 100000).
// The second line contains N integers representing the initial chain.
// The third line contains Q (1 ≤ Q ≤ 100000), followed by Q lines. Each line contains an integer X.


#include <iostream>
using namespace std;


class node{
    public:
    int data;
    node *next;

    node(int val){
        data=val;
        next=nullptr;
    }
};

int main(){

    int n;
    cin>>n;
    node *head=nullptr;
    node *curr=head;
    for(int i=0;i<n;i++){
        if(head==nullptr){
            // cout<<"Enter Head value: "<<endl;
            int tmp;
            cin>>tmp;
            head=new node(tmp);
            curr=head;
            continue;
        }
        // cout<<"Enter value of the node: "<<endl;
        int tmp;
        cin>>tmp;

        curr->next=new node(tmp);
        curr=curr->next;
    } 
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        curr=head;
        if(head != nullptr && head->data == x){
            node *tmp = head;
            head = head->next;
            delete tmp;
        }
        curr=head;
        while(curr->next!=nullptr && curr->next != nullptr){
            if(curr->next->data==x){
                node *tmp=curr->next;
                curr->next=tmp->next;
                delete tmp;
                break;
            }
             curr=curr->next;

        }

        curr=head;

        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        
        
    }

}