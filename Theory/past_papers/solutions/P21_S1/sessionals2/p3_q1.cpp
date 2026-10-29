#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;          // Base pointer pointing to the start of allocated array memory
    int *front;        // Pointer to the front element in the queue
    int *rear;         // Pointer to the location where the next element will be enqueued
    int *capacity_end; // Pointer to the memory boundary just after the allocated array space

public:
    // Constructor: Allocates memory and sets up initial pointers
    Queue(int sz) {
        arr = new int[sz];         // Dynamically allocate array of size 'sz'
        front = arr;               // Initially, front points to the start of memory
        rear = arr;                // Rear also points to the start of memory
        capacity_end = arr + sz;   // Points to the memory address immediately following the array
    }

    // Destructor: Frees allocated memory to avoid memory leaks
    ~Queue() {
        delete[] arr;
    }

    // Enqueue (Push) Operation
    void enqueue(int x) {
        // OVERFLOW CHECK:
        // If 'rear' has reached 'capacity_end', the array memory is completely full.
        if (rear == capacity_end) {
            cout << "Queue Overflow! Cannot enqueue " << x << endl;
            return;
        }

        // Place value at current 'rear' memory location, then advance 'rear' pointer to next slot
        *rear = x;
        rear++;

        cout << "Enqueued: " << x << endl;
    }

    // Dequeue (Pop) Operation
    void dequeue() {
        // UNDERFLOW CHECK:
        // If 'front == rear', no elements are left in the queue.
        if (front == rear) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }

        // Print/Retrieve element at 'front' and advance 'front' pointer to next element
        cout << "Dequeued: " << *front << endl;
        front++;

        // Reset pointers if queue becomes completely empty to allow reusing array memory
        if (front == rear) {
            front = arr;
            rear = arr;
        }
    }

    // Print the element at the front of the queue
    void displayFront() {
        if (front == rear) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front Element: " << *front << endl;
    }

    // Print the element at the rear of the queue
    void displayRear() {
        if (front == rear) {
            cout << "Queue is empty!" << endl;
            return;
        }
        // Since 'rear' points to the NEXT empty slot, the last inserted element is at (rear - 1)
        cout << "Rear Element: " << *(rear - 1) << endl;
    }
};

int main() {
    Queue q1(5); // Create a queue of capacity 5

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    q1.displayFront(); // Output: 10
    q1.displayRear();  // Output: 30

    q1.dequeue();      // Dequeues 10
    q1.displayFront(); // Output: 20

    return 0;
}