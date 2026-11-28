

#include <iostream>
 using namespace std;


 class hashtable{

    private:

    int *table;
    int size;


    public:
    hashtable(int sz){
        table=new int[sz];
        size=sz;
        for(int i=0;i<size;i++){
            table[i]=-1;
        }
    }

    int hashfunc(int key){
        return key%size;
    }


    void insert(int key){

        int h=hashfunc(key);

        for(int i=0;i<size;i++){

            int idx=(h+i)%size;

            if(table[idx]==-1){
                table[idx]=key;
                return ;
            }
        }
        cout<<"Hash Table Full!"<<endl;
    }


    void search(int key){

    int h=hashfunc(key);

    for(int i=0;i<size;i++){

        int idx=(h+i)%size;

        if(table[idx]==-1){
            cout<<"Not Found"<<endl;
            return;
        }

        if(table[idx]==key){
            cout<<"Found: "<<table[idx]<<endl;
            return;
        }
    }

    cout<<"Not Found"<<endl;
}

void remove(int key){           //not fully working, need to maintain another state for deleted, free, and occupied

    int h=hashfunc(key);

    for(int i=0;i<size;i++){
        int idx=(h+i)%size;

        if(table[idx]==-1){
            continue;
        }

        if(table[idx]==key){
            table[idx]=-1;
            size--;
            return ;
        }
    }
    cout<<"KEY NOT FOUND>>>>"<<endl;
}


    void display(){

        for(int i=0;i<size;i++){
            cout<<table[i]<<" ";
        }
        cout<<endl;
    }

 };
 int main(){

    hashtable t1(10);
    t1.insert(10);

    t1.insert(20);

    t1.insert(25);

    t1.insert(7);

    t1.display();
 }