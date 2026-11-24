#include <iostream>
using namespace std;



void generateKeys(int R, int keys[], int n)
{
int s = R + 1;
int count = 0;
while (count < n)
{
s = (s * 7) % 10007;
int k = 10 + s % 90;
bool used = false;
for (int j = 0; j < count; j++)
if (keys[j] == k) used = true;
if (!used) keys[count++] = k;
}
}


int main(){

    int R=545;  // 25P-0545

    int keys[13];
    generateKeys(R,keys,13);

    for(int i=0;i<13;i++){
        cout<<keys[i]<<" ";
    }
    cout<<endl;

}

