// Problem 4 — Merge the Two Sorted Chains


#include <iostream>
using namespace std;


class node{
    public:

    int data;
    node *next;

    node(int val){
        data=val;
        next =nullptr;
    }
};

class linkedl{

    private:
    node *head;
    node *curr;
    int len;

    public:

    linkedl(){
        head=nullptr;
        curr=head;
        len=0;
    }

    node* gethead(){
        return head;
    }

    void insert(int pos, int val){

        node *t=new node(val);
        if(head==nullptr){
            t->next=nullptr;
            head=t;
            curr=head;
            len++;
            return ;
        }
        curr=head;
        if(pos==1){
            t->next=curr;
            head=t;
            len++;
            return ;
        }else{
            curr=head;
            for(int i=1;i<pos-1;i++){
                curr=curr->next;
            
            }
            t->next=curr->next;
            curr->next=t;
            len++;
            return ;
        }

    }
    void display(){
        curr=head;

        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
};

node* merge(linkedl head1, linkedl head2){
    node *h1=head1.gethead();
    node *h2=head2.gethead();

    node *p1=h1;
    node *p2=h2;

    node *curr=nullptr;
    node *mainh=nullptr;
    int flg=0; // first itr check;
     if (p1 == nullptr) {
        return p2;
    }

    if (p2 == nullptr) {
        return p1;
    }
    while(p1!=nullptr && p2!=nullptr){

        if(p1->data<p2->data){
            if(flg==0){
                mainh=p1;
                curr=p1;
                p1=p1->next;
                flg=1;
                continue ;
            }
            curr->next=p1;
            curr=curr->next;
            p1=p1->next;
        }else{
            if(flg==0){
                mainh=p2;
                curr=p2;
                p2=p2->next;
                flg=1;
                continue;
            }
            curr->next=p2;
            curr=curr->next;
            p2=p2->next;
        }
        
    }  
    if(p1!=nullptr){
        curr->next=p1;
    }

    if(p2!=nullptr){
        curr->next=p2;
    }

    return mainh;
}

int main(){



   int n,m;
   cin>>n>>m;

   linkedl l1;
   for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    l1.insert(i,x);
   }
   l1.display();

   linkedl l2;
   for(int i=1;i<=m;i++){
    int x;
    cin>>x;
    l2.insert(i,x);
   }

   l2.display();

   cout<<"Merged:.........."<<endl;

   node *merged=merge(l1,l2);

   while ((merged->next!=nullptr))
   {
    cout<<merged->data<<" ";
    merged=merged->next;
   }
   cout<<endl;
   

}