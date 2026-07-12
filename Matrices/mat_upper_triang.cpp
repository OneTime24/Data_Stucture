
#include <iostream>

using namespace std;

struct matrix{
    int *A;
    int n;
};



void setter(matrix m,int i, int j,int x){

    if(i<=j){
        m.A[i-1*m.n-i-2*i-1/2+(j-1)]=x;
    }
}

int getter(matrix m,int i, int j,int x){

    if(i<=j){
       return m.A[i-1*m.n-i-2*i-1/2+(j-1)];
    }else{
        return 0;
    }
}
void create(matrix m){
    int x;
    cout<<"Enter all the elements: ";
    for(int i=1;i<m.n;i++){
        for(int j=1;j<m.n;j++){
            cin>>x;
            setter(m,i,j,x);

        }
    }
}

void display(matrix m){
    for(int i=1;i<m.n;i++){
        for(int j=1;j<m.n;j++){
            if(i<=j){
                cout<<m.A[i-1*m.n-i-2*i-1/2+(j-1)];
            }else{
                cout<<"0 ";
            }
        }
    }
}

int main(){


    matrix m;
    cout<<"Enter dimension of the array: ";
    cin>>m.n;

    m.A=new int[m.n];

    create(m);
    display(m);


}