

// all programs are commented

//-TASK1-

// #include <iostream>
// #include <string>
// using namespace std;

// class patient{
//     public:

//     string name;
//     int urg;

//     patient(){
//         name="";
//         urg=0;
//     }

//     patient(string n, int u){
//         name=n;
//         urg=u;
//     }
// };

// // max heap: the most urgent patient is always at index 0
// class heap{
//     private:

//     patient arr[20];
//     int len;

//     public:

//     heap(){
//         len=0;
//     }

//     int size(){
//         return len;
//     }

//     void insert(string n, int u){

//         if(len==20){
//             cout<<"heap is full\n";
//             return ;
//         }

//         // put the new patient at the end, then move him up
//         arr[len]=patient(n,u);
//         int i=len;
//         len++;

//         while(i>0){
//             int p=(i-1)/2;
//             if(arr[p].urg>=arr[i].urg){
//                 break;
//             }
//             patient tmp=arr[p];
//             arr[p]=arr[i];
//             arr[i]=tmp;
//             i=p;
//         }
//     }

//     patient remove(){

//         if(len==0){
//             cout<<"no patients\n";
//             return patient();
//         }

//         patient top=arr[0];

//         // last patient goes to the root, then moves down
//         arr[0]=arr[len-1];
//         len--;

//         int i=0;
//         while(true){
//             int big=i;
//             int l=2*i+1;
//             int r=2*i+2;

//             if(l<len && arr[l].urg>arr[big].urg){
//                 big=l;
//             }
//             if(r<len && arr[r].urg>arr[big].urg){
//                 big=r;
//             }
//             if(big==i){
//                 break;
//             }
//             patient tmp=arr[big];
//             arr[big]=arr[i];
//             arr[i]=tmp;
//             i=big;
//         }
//         return top;
//     }
// };

// int main(){

//     heap h1;

//     h1.insert("Ahmed",4);
//     h1.insert("Sara",9);
//     h1.insert("Bilal",2);
//     h1.insert("Fatima",7);
//     h1.insert("Usman",9);
//     h1.insert("Zainab",5);
//     h1.insert("Omar",1);
//     h1.insert("Hira",8);

//     cout<<"treatment order:\n";
//     while(h1.size()>0){
//         patient p=h1.remove();
//         cout<<p.name<<" "<<p.urg<<endl;
//     }

//     cout<<"\nwhy heap: a new patient costs O(log n) to insert in a heap, but re-sorting the whole list after every patient costs O(n log n).\n";
// }


//-TASK02-

// #include <iostream>
// using namespace std;

// class heap{
//     private:

//     int arr[20];

//     int len;

//     public:

//     heap(){
//         len=0;
//     }

//     void set(int a[], int n){

//         len=n;

//         for(int i=0;i<n;i++){
//             arr[i]=a[i];
//         }
//     }

//     // push node i downm until both children are smaller (n = size of heap part)
//     void heapify(int n, int i){

//         int big=i;

//         int l=2*i+1;

//         int r=2*i+2;


//         if(l<n && arr[l]>arr[big]){

//             big=l;
//         }
//         if(r<n && arr[r]>arr[big]){

//             big=r;
//         }

//         if(big!=i){

//             int tmp=arr[i];
//             arr[i]=arr[big];

//             arr[big]=tmp;

//             heapify(n,big);
//         }
//     }

//     // start from the last parent and go up to the root
//     void buildHeap(){

//         for(int i=len/2-1;i>=0;i--){

//             heapify(len,i);
//         }
//     }

//     // heap must already be built: move the biggest to the end, shrink, ffix the root.
//     void heapSort(){

//         for(int i=len-1;i>0;i--){

//             int tmp=arr[0];

//             arr[0]=arr[i];
//             arr[i]=tmp;


//             heapify(i,0);
//         }
//     }

//     void traverse(){

//         for(int i=0;i<len;i++){

//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//     }
// };

// int main(){

//     int a[8]={14,3,27,9,21,6,30,11};

//     heap h1;
//     h1.set(a,8);

//     h1.buildHeap();
//     cout<<"after buildHeap: ";

//     h1.traverse();

//     h1.heapSort();
//     cout<<"after heapSort: ";

//     h1.traverse();
// }

// // Paper work attached...





//-TASK03-


// /*
// my method: build a max heap, O(n), then remove the max 5 times, O(k log n) with k=5.
// total cost: O(n+k log n)

// full sorting cost: O(n log n)

// why mine wins: we only need 5 scores, so we never pay to order the other 10.
// */

// #include <iostream>

// using namespace std;

// class heap{
//     private:

//     int arr[20];
//     int len;

//     public:

//     heap(){
//         len=0;
//     }

//     void set(int a[], int n){

//         len=n;
//         for(int i=0;i<n;i++){

//             arr[i]=a[i];
//         }
//     }

//     void heapify(int n, int i){

//         int big=i;
//         int l=2*i+1;

//         int r=2*i+2;

//         if(l<n && arr[l]>arr[big]){

//             big=l;
//         }
//         if(r<n && arr[r]>arr[big]){

//             big=r;
//         }

//         if(big!=i){

//             int tmp=arr[i];
//             arr[i]=arr[big];

//             arr[big]=tmp;

//             heapify(n,big);
//         }
//     }

//     void buildHeap(){

//         for(int i=len/2-1;i>=0;i--){

//             heapify(len,i);
//         }
//     }

//     // take out the biggest, last element goes to root and moves down
//     int removeMax(){

//         if(len==0){

//             cout<<"heap is empty\n";
//             return -1;
//         }

//         int top=arr[0];

//         arr[0]=arr[len-1];
//         len--;

//         heapify(len,0);
//         return top;
//     }
// };

// int main(){

//     int a[15]={56,88,72,95,63,81,47,90,77,69,84,58,92,66,73};

//     heap h1;

//     h1.set(a,15);

//     h1.buildHeap();

//     cout<<"top 5 scores: ";
//     for(int i=0;i<5;i++){

//         cout<<h1.removeMax()<<" ";
//     }
//     cout<<endl;
// }