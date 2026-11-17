

#include <iostream>
using namespace std;

int main(){

    int arr[7]={1,2,3,4,5,6,7};

    int i=0;
    int j=6;

    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    while(i<j){

        int tmp=arr[j];
        arr[j]=arr[i];
        arr[i]=tmp;
        i++;
        j--;
    }



    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}