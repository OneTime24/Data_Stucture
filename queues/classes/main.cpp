
// //circular queue array


// #include <iostream>

// const int cap=10;
// using namespace std;

// class queue{
//     private:
//     // int size;
//     int arr[cap];
//     int front,rear;
//     int cnt;

//     public:
//     queue(){
//         front=rear=0;
//         cnt=0;
//     }

//     bool isfull(){

//         return cnt==cap;
//     }

//     bool isempty(){

//         return cnt==0;
//     }

//     void enqueue(int val){

//         if(isfull()){
//             cout<<"Queue overflowed...."<<endl;
//             return ;
//         }

//         if(isempty()){
//             front=0;
//         }
//         arr[rear]=val;
//         rear=(rear+1)%cap;  //wraparound
//         ++cnt;
//     }

//     int dequeue(){

//         if(isempty()){
//             cout<<"Queue Underflowed..."<<endl;
//             return -1;
//         }

//         int rmv=arr[front];
//         front=(front+1)%cap;
//         --cnt;

//         return rmv;


//     }

//     void frnt(){

//         if(isempty()){
//             cout<<"EMPOTY QUEUE..."<<endl;
//             return;
//         }
//         if(isfull()){
//             cout<<"Full QUEUE..."<<endl;
//             return;
//         }

//         cout<<arr[front]<<endl;
        
//     }

//     void display(){
//     int i = front;

//     for(int j=0; j<cnt; j++){
//         cout << arr[i] << " ";
//         i = (i+1)%cap;
//     }
//     cout<<endl;
//     }



// };

// int main(){



//     queue q1;

//     q1.enqueue(1);
//     q1.enqueue(2);
//     q1.enqueue(3);

//     q1.dequeue();
//     q1.dequeue();

//     q1.enqueue(4);
//     q1.enqueue(5);

//     q1.display();
// }


#include <iostream>
using namespace std;

class LinkedQueue {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v) : value(v), next(nullptr) {}
    };

    Node* frontPtr = nullptr;
    Node* rearPtr = nullptr;

public:
    // Destructor prevents memory leaks.
    ~LinkedQueue() {
        int ignored;
        while (dequeue(ignored)) { }
    }

    bool isEmpty() const {
        return frontPtr == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            frontPtr = rearPtr = newNode;
        } else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
    }

    bool dequeue(int& removedValue) {
        if (isEmpty()) return false;

        Node* oldFront = frontPtr;
        removedValue = oldFront->value;
        frontPtr = frontPtr->next;
        delete oldFront;

        // If the queue became empty, rear must also be null.
        if (frontPtr == nullptr) rearPtr = nullptr;
        return true;
    }

    bool front(int& value) const {
        if (isEmpty()) return false;
        value = frontPtr->value;
        return true;
    }
};

int main() {
    LinkedQueue q;
    q.enqueue(7); q.enqueue(14); q.enqueue(21);

    int value;
    while (q.dequeue(value))
        cout << "Serving: " << value << '\n';
    return 0;
}