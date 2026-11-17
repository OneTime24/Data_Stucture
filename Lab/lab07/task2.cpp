#include <iostream>
using namespace std;

class heap{
    private:

    int arr[20];

    int len;

    public:

    heap(){
        len=0;
    }

    void set(int a[], int n){

        len=n;

        for(int i=0;i<n;i++){
            arr[i]=a[i];
        }
    }

    // push node i downm until both children are smaller (n = size of heap part)
    void heapify(int n, int i){

        int big=i;

        int l=2*i+1;

        int r=2*i+2;


        if(l<n && arr[l]>arr[big]){

            big=l;
        }
        if(r<n && arr[r]>arr[big]){

            big=r;
        }

        if(big!=i){

            int tmp=arr[i];
            arr[i]=arr[big];

            arr[big]=tmp;

            heapify(n,big);
        }
    }

    // start from the last parent and go up to the root
    void buildHeap(){

        for(int i=len/2-1;i>=0;i--){

            heapify(len,i);
        }
    }

    // heap must already be built: move the biggest to the end, shrink, ffix the root.
    void heapSort(){

        for(int i=len-1;i>0;i--){

            int tmp=arr[0];

            arr[0]=arr[i];
            arr[i]=tmp;


            heapify(i,0);
        }
    }

    void traverse(){

        for(int i=0;i<len;i++){

            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){

    int a[8]={14,3,27,9,21,6,30,11};

    heap h1;
    h1.set(a,8);

    h1.buildHeap();
    cout<<"after buildHeap: ";

    h1.traverse();

    h1.heapSort();
    cout<<"after heapSort: ";

    h1.traverse();
}

// Paper work attached...