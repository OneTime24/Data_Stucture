
#include <iostream>

using namespace std;

struct matrix{
    int *A;
    int n;
};


void create(matrix m){

    cout<<"Enter all the elements: ";
    for(int i=1;i<m.n;i++){
        for(int j=1;j<m.n;j++){
            cin>>m.A[i];
        }
    }
}

int main(){


    matrix m;
    cout<<"Enter dimension of the array: ";
    cin>>m.n;

    m.A=new int[m.n];


}