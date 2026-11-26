

#include <iostream>

#include <algorithm>
using namespace std;


class heap{
    private:
    int hep[100];
    int size;


    public:
    heap(){
        size=1;
    }


    void insert(int val){

        hep[size]=val;
        int i=size;
        size++;

        while(i>1 && hep[i/2]<hep[i]){

            swap(hep[i],hep[i/2]);

            i=i/2;
        }
   
    }

void heapify(int i){
        int largest=i;

        int left=2*i;
        int right=2*i+1;

        if(left<size && hep[left]>hep[largest]){
            largest=left;
        }
        if(right<size && hep[right]>hep[largest]){
            largest=right;
        }

        if(largest!=i){

            swap(hep[i],hep[largest]);
            
            heapify(largest);
        }
}


    int getmax(){
        
        if(size==1){
            return -1;
        }

        return hep[1];
    }


    int getmin(){
        if(size==1){
            return -1;
        }

        int min=hep[1];

        
        for(int i=2;i<size;i++){
            if(hep[i]<min){
                min=hep[i];
            }
        }
        return min;
    }



    void buildHeap(int arr[], int n){
        size=n+1;

        for(int i=1;i<=n;i++){
            hep[i]=arr[i-1];
        }

        for(int i=n/2;i>=1;i--){

            heapify(i);
        }
    }


    bool search(int val){

    for(int i=1;i<size;i++){
        if(hep[i]==val){
            return true;
        }
    }

    return false;
}



void update_val(int pos, int val){
    if(pos<1 || pos>=size){
        cout<<"Invalid position";
        return;
    }
    int old=hep[pos];

    hep[pos]=val;


    if(val>old){

        while(pos>1 && hep[pos]>hep[pos/2]){
            swap(hep[pos],hep[pos/2]);
            pos/=2;
        }

    }else{


        heapify(pos);
        // int largest=pos;

        // int left=2*pos;
        // int right=2*pos+1;

        // if(left<size && hep[left]>hep[largest]){
        //     largest=left;
        // }
        // if(right<size && hep[right]>hep[largest]){
        //     largest=right;
        // }

        // if(largest!=pos){
        //     swap(hep[pos],hep[largest]);
        //     // recall the function
        // }
    }
}
    void deletion(){

         if(size==1){
        cout<<"Heap is empty";
        return;
    }
        hep[1]=hep[size-1];
        size--;

        heapify(1);
    }

    

    void display(){
        for(int i=1;i<size;i++){
            cout<<hep[i]<<" ";
        }
    }
};


int main(){

    heap h1;
    h1.insert(5);

    h1.insert(10);

    h1.insert(15);

    h1.insert(20);

    h1.insert(25);

    h1.display();

cout<<"\nAfter deletion: ";
h1.deletion();
h1.display();
}