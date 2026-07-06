

// jsut a rendom strings problem for resresh

#include <iostream>
#include <string>
using namespace std;


class detail{

    private:
     string name;
     int age;

     public:

     detail(string s, int a):name(s),age(a){};

     void output(){
        cout<<"Name: "<<name<<"\nAge"<<age<<endl;
     }
};

int main(){

    cout<<"Enter Name: ";

    string nm;
    
    cin>>nm;

    cout<<nm;

}