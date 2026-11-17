
#include <iostream>
using namespace std;

const int cap=12;

int main(){

    int *arr=new int[cap];
    int len=0;

    while(true){

        int x;
        cout<<"\n1. Admit a patient at the end.\n2. Admit at a given position\n3. Discharge by position\n4. Discharge the first occurrence\n5. Remove all occurrences\n6. Search ID and find positions\n7. Transfer patient from i to j\n8. Display list, first, last, count and capacity\n9. Exit\n";

        cin>>x;

        switch(x){

            case 1:{
                if(len==cap){
                    cout<<"Ward full......\n";
                    break;
                }

                cout<<"Enter patient id: ";
                int id;
                cin>>id;

                *(arr+len)=id;
                len++;
                break;
            }

            case 2:{
                if(len==cap){
                    cout<<"Ward full......\n";
                    break;
                }

                cout<<"Enter position (0 to "<<len<<"): ";
                int pos;
                cin>>pos;

                if(pos<0 || pos>len){
                    cout<<"Invalid position\n";
                    break;
                }

                cout<<"Enter id.....: ";
                int id;
                cin>>id;

                for(int i=len;i>pos;i--){
                    *(arr+i)=*(arr+i-1);
                }

                *(arr+pos)=id;
                len++;
                break;
            }

            case 3:{
                if(len==0){
                    cout<<"Ward empty......\n";
                    break;
                }

                cout<<"Enter position to discharge (0 to "<<len-1<<"): ";
                int pos;
                cin>>pos;

                if(pos<0 || pos>=len){
                    cout<<"Invalid position\n";
                    break;
                }

                for(int i=pos;i<len-1;i++){
                    *(arr+i)=*(arr+i+1);
                }

                len--;
                break;
            }

            case 4:{
                if(len==0){
                    cout<<"Ward empty......\n";
                    break;
                }

                cout<<"Enter id...: ";
                int id;
                cin>>id;

                int i;
                for(i=0;i<len;i++){
                    if(*(arr+i)==id){
                        break;
                    }
                }

                if(i==len){
                    cout<<"ID not found\n";
                    break;
                }

                for(int j=i;j<len-1;j++){
                    *(arr+j)=*(arr+j+1);
                }

                len--;
                cout<<"Patient discharged\n";
                break;
            }

            case 5:{
                if(len==0){
                    cout<<"Ward empty......\n";
                    break;
                }

                cout<<"Enter id...: ";
                int id;
                cin>>id;

                int j=0;
                int count=0;

                for(int i=0;i<len;i++){
                    if(*(arr+i)!=id){
                        *(arr+j)=*(arr+i);
                        j++;
                    }
                    else{
                        count++;
                    }
                }

                len=j;

                if(count==0)
                    cout<<"ID not found\n";
                else
                    cout<<"Removed "<<count<<" occurrences\n";

                break;
            }

            case 6:{
                if(len==0){
                    cout<<"Ward empty......\n";
                    break;
                }

                cout<<"Enter id...: ";
                int id;
                cin>>id;

                int found=0;

                for(int i=0;i<len;i++){
                    if(*(arr+i)==id){
                        cout<<"Found at position: "<<i<<endl;
                        found=1;
                    }
                }

                if(found==0)
                    cout<<"ID not found\n";

                break;
            }

            case 7:{
                if(len==0){
                    cout<<"Ward empty......\n";
                    break;
                }

                cout<<"Enter source position i: ";
                int it;
                cin>>it;

                cout<<"Enter destination position j: ";
                int jt;
                cin>>jt;

                if(it<0 || it>=len || jt<0 || jt>=len){
                    cout<<"Invalid position\n";
                    break;
                }

                int temp=*(arr+it);

                if(it<jt){
                    for(int i=it;i<jt;i++){
                        *(arr+i)=*(arr+i+1);
                    }
                }
                else if(it>jt){
                    for(int i=it;i>jt;i--){
                        *(arr+i)=*(arr+i-1);
                    }
                }

                *(arr+jt)=temp;
                cout<<"Patient transferred\n";
                break;
            }

            case 8:{
                cout<<"Patients: ";

                for(int i=0;i<len;i++){
                    cout<<*(arr+i)<<" ";
                }

                cout<<"\nCount: "<<len;
                cout<<"\nCapacity: "<<cap;

                if(len>0){
                    cout<<"\nFirst: "<<*arr;
                    cout<<"\nLast: "<<*(arr+len-1);
                }
                else{
                    cout<<"\nWard is empty";
                }

                cout<<endl;
                break;
            }

            case 9:{
                delete[] arr;
                return 0;
            }

            default:
                cout<<"Invalid choice\n";
        }
    }
}

/*
Sample run (positions are 0-based):

Initial list: [5, 9, 2]

Admit ID 7 at position 1:
[5, 7, 9, 2]

Transfer patient from position 1 to position 3:
[5, 9, 2, 7]

Remove all occurrences of ID 5 from [5, 9, 5, 5, 2]:
[9, 2]

Search for ID 99:
ID not found
*/
