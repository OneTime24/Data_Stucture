
// //using array


// #include <iostream>


// const int cap=5;
// using namespace std;

// class stack{
// private:
// int arr[cap];
// int top;

// public:
// stack(){
//     top=-1;
// }

// bool isfull(){
//     if(top==cap-1){
//         cout<<"Stack is full: ..."<<endl;
//         return true;
//     }
//     return false;
// }

// bool isempty(){
//     if(top==-1){
//         cout<<"Stack is empty: ..."<<endl;
//         return true;
//     }
//     return false;
// }

// void insert(int val){

//     if(isfull()){

//        return ;
        
//     }
//      arr[top++]=val;
// }
// void peek(){
//     if(isempty()){
//         // cout<<"Stack is empty... "<<endl;
//         return ;
//     }
//     cout<<arr[top]<<endl;
// }
// int pop(){
//     if(isempty()){
//         // cout<<"Stack is empty... "<<endl;
//         return -1;
//     }

//     int val=arr[top];
//     top--;
//     return val;
// }

// void display(){
//     if(isempty()){
//         // cout<<"Stack is emptry...."<<endl;
//         return ;
//     }

//     for(int i=top;i>=0;i--){
//         cout<<arr[i]<<endl;
//     }
    
// }

// };
// int main(){

//     stack s1;
//     s1.insert(1);
//     s1.insert(2);
//     s1.insert(3);
//     s1.insert(4);
//     s1.insert(5);

//     s1.insert(6);

//     s1.peek();
//     s1.display();


//     cout<<s1.pop()<<endl;
//     cout<<s1.pop()<<endl;
//     cout<<s1.pop()<<endl;
//     cout<<s1.pop()<<endl;
//     cout<<s1.pop()<<endl;
//     cout<<s1.pop()<<endl;



    
// }

#include <iostream>
using namespace std;

// ---------- A single node of our linked list ----------
struct Node {
    int   data;      // the value stored
    Node* next;      // pointer to the node below it in the stack
};

class LinkedStack {
private:
    Node* top;       // points to the TOP node (the head of the list)

public:
    // ---------- CONSTRUCTOR ----------
    LinkedStack() {
        top = nullptr;                 // empty stack
    }

    // ---------- DESTRUCTOR : free all memory ----------
    ~LinkedStack() {
        while (!isEmpty()) {
            pop();                     // pop() already deletes the node
        }
    }

    // ---------- isEmpty ----------
    bool isEmpty() {
        return (top == nullptr);
    }

    // ---------- PUSH : insert at the head ----------
    void push(int value) {
        Node* newNode = new Node;      // 1. create a new node on the heap
        newNode->data = value;         // 2. store the value
        newNode->next = top;           // 3. new node points to the OLD top
        top = newNode;                 // 4. the new node becomes the new top
        // No isFull() check needed - the list grows as long as memory exists!
    }

    // ---------- POP : delete the head ----------
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return -1;
        }
        Node* temp = top;              // 1. remember the node we are removing
        int value = temp->data;        // 2. save its data
        top = top->next;               // 3. move top down to the next node
        delete temp;                   // 4. FREE the memory (very important!)
        return value;                  // 5. return the data
    }

    // ---------- PEEK ----------
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    // ---------- SIZE : count the nodes ----------
    int size() {
        int count = 0;
        Node* current = top;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;                  // O(n) - walk the whole list
    }

    // ---------- DISPLAY ----------
    void display() {
        if (isEmpty()) {
            cout << "Stack: [ empty ]" << endl;
            return;
        }
        cout << "Stack (top -> bottom): ";
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// ================= MAIN =================
int main() {
    LinkedStack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();                             // 30 20 10

    cout << "Top   : " << s.peek() << endl;   // 30
    cout << "Size  : " << s.size() << endl;   // 3

    cout << "Popped: " << s.pop() << endl;    // 30
    s.display();                             // 20 10

    return 0;
}