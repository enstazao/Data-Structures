#include <iostream>
using namespace std;

class Queue {
    private:
        int *queue;
        int *front, *rear;
        int size;
    public:
        Queue();
        Queue(int size);
        ~Queue();
        void Enqueue();
        void Dequeue();
        void Display();
};
// Constructor
Queue::Queue() {
    size = 5;
    queue = new int[size];
    front = rear = NULL;
}
// Constructor 
Queue::Queue(int size) {
    this->size = size;
    queue = new int[size];
    front = rear = NULL;
}
// Destructor
Queue::~Queue() {
    delete [] queue;
    rear = front = NULL;
}
// Enqueue Function
void Queue::Enqueue() {
    // Empty Queue
    if (rear == NULL) {
        rear = front = queue;
        cout << "Enter Data in Queue=> ";
        cin >> *rear;
    }
     // Rear Reached to End
    else if (rear == (queue + size - 1) && front != queue) {
        rear = queue;
        cout << "Enter Data in Queue=> ";
        cin >> *rear;
    }
    // Rear is between Array
    else if (rear + 1 != front && rear != (queue + size - 1)) {
        rear += 1;
        cout << "Enter Data in Queue=> ";
        cin >> *rear;
    }
    // Queue is Full
    else
        cout << "OverFlow Condtion Occur" << endl;
}
// DeQueue Function
void Queue::Dequeue() {
    // Empty Queue
    if (front == NULL) 
        cout << "UnderFlow Condition Occur" << endl;
    // queue is going to empty
    else if (front == rear) 
        front = rear = NULL;
    // front reached at end of arry
    else if (front == (queue + size - 1))
        front = queue;
    // front is between somewhere is array
    else
        front += 1;
}
// Display Function
void Queue::Display() {
    int *temp = queue;
    // Queue is empty
    if (front == NULL) {
        cout << "Queue Is Empty" << endl;
        return;
    }
    cout << "Data In Queue=> ";
    do {
        // temp reached at end of array
        if (temp == (queue + size - 1))
            temp = queue;
        cout << *temp << " ";
        temp += 1;
    }while(temp != rear);
}
int main() {
    Queue obj;
    obj.Enqueue();
    obj.Enqueue();
    obj.Dequeue();
    obj.Enqueue();
    obj.Enqueue();
    obj.Enqueue();
    obj.Enqueue();
    obj.Enqueue();
    obj.Dequeue();
    obj.Dequeue();
    obj.Dequeue();
    obj.Dequeue();
    obj.Dequeue();
    obj.Dequeue();
    obj.Display();
    return 0;
}