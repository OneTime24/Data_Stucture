

#include <iostream>
using namespace std;

int main(){

    int arr[7]={1,2,3,4,5,6,7};


    for(int i=0;i<2;i++){

        int tmp=arr[0];

        for(int j=0;j<6;j++){
            arr[j]=arr[j+1];
        }

        arr[6]=tmp;
    }

    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }

}