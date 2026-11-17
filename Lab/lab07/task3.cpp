/*
my method: build a max heap, O(n), then remove the max 5 times, O(k log n) with k=5.
total cost: O(n+k log n)

full sorting cost: O(n log n)

why mine wins: we only need 5 scores, so we never pay to order the other 10.
*/

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

    void buildHeap(){

        for(int i=len/2-1;i>=0;i--){

            heapify(len,i);
        }
    }

    // take out the biggest, last element goes to root and moves down
    int removeMax(){

        if(len==0){

            cout<<"heap is empty\n";
            return -1;
        }

        int top=arr[0];

        arr[0]=arr[len-1];
        len--;

        heapify(len,0);
        return top;
    }
};

int main(){

    int a[15]={56,88,72,95,63,81,47,90,77,69,84,58,92,66,73};

    heap h1;

    h1.set(a,15);

    h1.buildHeap();

    cout<<"top 5 scores: ";
    for(int i=0;i<5;i++){

        cout<<h1.removeMax()<<" ";
    }
    cout<<endl;
}