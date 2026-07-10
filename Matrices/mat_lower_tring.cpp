// starting again with focus



#include <iostream>

using namespace std;


struct matrix{

    int *mat;
    int n;
};

void seter(matrix m,int i, int j, int x){

    if(i>=j){
        m.mat[i*(i-1)/2+j-1]=x;
    }
    
}

int geter(matrix m, int i, int j){
    if (i>=j){
        return m.mat[i*(i-1)/2+j-1];
    }else{
        return 0;
    }
}

void display(matrix m){
    
for(int i=1;i<=m.n;i++){
    for(int j=1;j<=m.n;j++){
        if(i>=j){
            cout<<m.mat[i*(i-1)/2+j-1]<<" ";
        }
        else{
            cout<<"0 ";
        }
    }
    cout<<"\n";
}
}
int main(){


    int sz;
    cout<<"Enter size: ";
    cin>>sz;
    matrix m;
    m.mat=new int[sz]();

    m.n=sz;

    
    int x;
    cout<<"Enter all the elemetns: ";
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            cin>>x;

            seter(m,i,j,x);
            
        }
    }



    display(m);


    delete m.mat;




}