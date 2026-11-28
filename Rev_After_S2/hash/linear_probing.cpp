

#include <iostream>
using namespace std;

class hashtable{

    private:
    int *table;
    int size;
    int cnt;
    public:
    hashtable(int sz){
        size=sz;
        table=new int[size];
        cnt=0;

        for(int i=0;i<size;i++){
            table[i]=-1;
        }
    
    }

    int hashfunc(int key){
    return key%size;
}


    void rehash(){

        int *oldtable=table;
        int oldsize=size;

        size*=2;
        cnt=0; 
        table=new int[size];

        for(int i=0;i<size;i++){

            table[i]=-1;
        }

        for(int i=0;i<oldsize;i++){

            if(oldtable[i]!=-1){
                insert(oldtable[i]);
            }
        }
        delete[] oldtable;
    }
    

    void insert(int key){

        float a=(float)(cnt+1)/size;

        if(a>=0.7){
            rehash();
        }
        int h=hashfunc(key);

        for(int i=0;i<size;i++){

            int idx=(h+i)%size;

            if(table[idx]==-1){
                table[idx]=key;
                cnt++;
                return;
                
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





void display(){

    for(int i=0;i<size;i++){
        cout<<"Index "<<i<<": ";

        if(table[i]==-1)
            cout<<"EMPTY";
        else
            cout<<table[i];

        cout<<endl;
    }
}
~hashtable(){
    delete[] table;
}
};

int main(){

     hashtable t1(10);

    t1.insert(10);
    t1.insert(20);
    t1.insert(25);
    t1.insert(7);
    t1.insert(17);
    t1.insert(27);
    t1.insert(37);

    cout<<"Hash Table:"<<endl;
    t1.display();

    cout<<"\nSearching 27:"<<endl;
    t1.search(27);

    return 0;

}