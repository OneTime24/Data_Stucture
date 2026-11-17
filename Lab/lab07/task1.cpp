

#include <iostream>
#include <string>
using namespace std;

class patient{
    public:

    string name;
    int urg;

    patient(){
        name="";
        urg=0;
    }

    patient(string n, int u){
        name=n;
        urg=u;
    }
};

// max heap: the most urgent patient is always at index 0
class heap{
    private:

    patient arr[20];
    int len;

    public:

    heap(){
        len=0;
    }

    int size(){
        return len;
    }

    void insert(string n, int u){

        if(len==20){
            cout<<"heap is full\n";
            return ;
        }

        // put the new patient at the end, then move him up
        arr[len]=patient(n,u);
        int i=len;
        len++;

        while(i>0){
            int p=(i-1)/2;
            if(arr[p].urg>=arr[i].urg){
                break;
            }
            patient tmp=arr[p];
            arr[p]=arr[i];
            arr[i]=tmp;
            i=p;
        }
    }

    patient remove(){

        if(len==0){
            cout<<"no patients\n";
            return patient();
        }

        patient top=arr[0];

        // last patient goes to the root, then moves down
        arr[0]=arr[len-1];
        len--;

        int i=0;
        while(true){
            int big=i;
            int l=2*i+1;
            int r=2*i+2;

            if(l<len && arr[l].urg>arr[big].urg){
                big=l;
            }
            if(r<len && arr[r].urg>arr[big].urg){
                big=r;
            }
            if(big==i){
                break;
            }
            patient tmp=arr[big];
            arr[big]=arr[i];
            arr[i]=tmp;
            i=big;
        }
        return top;
    }
};

int main(){

    heap h1;

    h1.insert("Ahmed",4);
    h1.insert("Sara",9);
    h1.insert("Bilal",2);
    h1.insert("Fatima",7);
    h1.insert("Usman",9);
    h1.insert("Zainab",5);
    h1.insert("Omar",1);
    h1.insert("Hira",8);

    cout<<"treatment order:\n";
    while(h1.size()>0){
        patient p=h1.remove();
        cout<<p.name<<" "<<p.urg<<endl;
    }

    cout<<"\nwhy heap: a new patient costs O(log n) to insert in a heap, but re-sorting the whole list after every patient costs O(n log n).\n";
}