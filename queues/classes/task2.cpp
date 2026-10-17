
// Circular queue, from scratch
// Implement a menu-driven circular queue of strings with capacity 8. Include 
// enqueue, dequeue, front, size, display, overflow, and underflow

#include <iostream>
#include <string>
using namespace std;

const int cap=8;

// class node{
//     public:

//     string data;
//     node *next;

//     node(string str){
//         data=str;
//         next=nullptr;
//     }
// };

// node *front=nullptr;
// node *rear=nullptr;
class queue{
    private:

    string arr[cap];

    int front,rear;
    int count;

    public:
    queue(){
        front=-1;
        rear=-1;
        count=0;
    }

    bool isfull(){

        return count==cap;

    }
    bool isempty(){
        return count==0;
    }

    void enqueue(string val) {
        if (isfull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (isempty())
            front = 0;

        if (rear == cap - 1)
            rear = 0;
        else
            rear++;

        arr[rear] = val;
        count++;
    }void dequeue() {
        if (isempty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << "Removed: " << arr[front] << endl;

        if (count == 1) {
            front = rear = -1;
        }
        else if (front == cap - 1) {
            front = 0;
        }
        else {
            front++;
        }

        count--;
    }
    void showfront() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Front: " << arr[front] << endl;
    }

    void size() {
        cout << "Size: " << count << endl;
    }
    void display(){


        int i=front;

        for(int j=0;j<count;j++){

            cout<<arr[i]<<" ";

            if (i == cap - 1)
                i = 0;
            else
                i++;
        }
        cout<<endl;
    }

};

int main(){

    queue q1;
    q1.enqueue("Hello");
    q1.enqueue("Hello");
    q1.enqueue("Hello");
    q1.enqueue("Hello");
    q1.enqueue("Hello");

    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.display();
}