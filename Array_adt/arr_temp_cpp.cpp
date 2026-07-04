

#include <iostream>
using namespace std;


template<class T>

class Array{

    private:
    T* ary;
    int leng;
    int size;

    public:

    Array(){
        ary=new T[10];
        leng=0;
        size=10;

    }

    Array(int sz){
        ary=new T[sz];
        size=sz;
        leng=0;
    }


    void add(int x){
        ary[leng++]=x;
    }

    void insert(int ind, T x){

        for(int i=leng-1;i>ind;i++){
            ary[i+1]=ary[i];
        }
        ary[ind]=x;
        leng++;
    }

    void delet(int ind){

        for(int i=ind;i<leng-1;i++){
            ary[i]=ary[i+1];
        }
        leng--;
        
    }

    void display(){
        for(int i=0;i<leng;i++){
            cout<<ary[i]<<" "<<endl;
        }
    }



};

int main (){

    Array<int> arr(10);

    arr.add(10);

    arr.add(50);

    arr.add(20);

    arr.insert(1,30);
    
    arr.delet(0);

    arr.display();


}