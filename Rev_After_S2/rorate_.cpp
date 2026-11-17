

#include <iostream>
using namespace std;

int main(){

    int arr[7]={1,2,3,4,5,6,7};


    for(int i=0;i<2;i++){
        int tmp=arr[6];

        for(int j=6;j>0;j--){
            arr[(j)]=arr[j-1];
        }
        arr[0]=tmp;

    }

    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }

}