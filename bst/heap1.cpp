#include <iostream>
using namespace std;

class MaxHeap {
private:
    int heap[100];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    void insert(int value) {
        size++;
        int i = size;

        while (i > 1 && value > heap[i / 2]) {
            heap[i] = heap[i / 2];
            i = i / 2;
        }

        heap[i] = value;
    }

    void display() {
        for (int i = 1; i <= size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);
    h.insert(35);
    h.insert(60);

    h.display();

    return 0;
}