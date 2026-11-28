

#include <iostream>
 using namespace std;


 struct node{
    int data;
    node *next=nullptr;

 };

 class hashtable{

    private:

    node **table;
    int size;


    public:

    hashtable(int sz){
        size=sz;
        table=new node*[sz];
        for(int i=0;i<size;i++){
        table[i]=nullptr;
    }
    }


    int hashfunc(int key){
        return key%size;

        
    }

    void insert(int key){

        int idx=hashfunc(key);

        node *newnode=new node;
        newnode->data=key;
        newnode->next=nullptr;


        if(table[idx]==nullptr){
            table[idx]=newnode;
            return ;
        }

        node *tmp=table[idx];

        while(tmp->next!=nullptr){
            tmp=tmp->next;
        }

        tmp->next=newnode;


    }


    void search(int key){

        int idx=hashfunc(key);

        node *tmp=table[idx];

        while(tmp!=nullptr){

            if(key==tmp->data){
                cout<<"FOUND: "<<key<<endl;
                return;
            }
            tmp=tmp->next;
        }
        cout<<"NOT FOUND\n";
    }
        void display(){

        for(int i=0;i<size;i++){

            cout<<"Index "<<i<<": ";

            node* temp=table[i];

            while(temp!=NULL){

                cout<<temp->data<<" -> ";
                temp=temp->next;
            }

            cout<<"NULL"<<endl;
        }
    }
     ~hashtable(){

        for(int i=0;i<size;i++){

            node* temp=table[i];

            while(temp!=NULL){

                node* del=temp;
                temp=temp->next;

                delete del;
            }
        }

        delete[] table;
    }
 };


 int main(){
    hashtable t1(5);

    t1.insert(10);
    t1.insert(15);
    t1.insert(20);
    t1.insert(7);
    t1.insert(12);

    cout<<"Hash Table:"<<endl;
    t1.display();

    cout<<"\nSearching 20:"<<endl;
    t1.search(20);

    cout<<"\nSearching 50:"<<endl;
    t1.search(50);

    return 0;
 }