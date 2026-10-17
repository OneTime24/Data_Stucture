// josephus problem

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

int josephus(int n, int k){

    node *head=new node(1);
    node *curr=head;
    for(int i=2;i<=n;i++){
        curr->next=new node(i);
        curr=curr->next;
    }
    curr->next=head;
    // curr=head;
    node *tmp;
    int val=0;
    while(curr->next!=curr){

        for(int i=1;i<k;i++){
            curr=curr->next;
        }
        tmp=curr->next;
        // val=tmp->data;
        curr->next=tmp->next;
        delete tmp;

    }
    int ans=curr->data;
    delete curr;
    return ans;


}

int main(){


    cout<<josephus(5,2)<<endl;

}

