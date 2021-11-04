#include <iostream>
using namespace std;

// Node Structure
struct node
{
    int info;
    node *next;
};

// Class
class Queue
{
private:
    node *front, *rear;
    node *temp;
    int length, size;

public:
    Queue();
    ~Queue();
    void Enqueue();
    void Dequeue();
    void Display();
};

// Consturctor
Queue::Queue()
{
    length = 10;
    size = 0;
    front = rear = NULL;
}
// Destructor
Queue::~Queue()
{
    if (front == NULL)
    {
        return;
    }
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}
// Enqueue Function
void Queue::Enqueue()
{
    // No Space in Queue
    if (size == length)
    {
        cout << "Overflow Condition Occur" << endl;
        return;
    }
    // Empty Queue
    if (front == NULL)
    {
        front = new node;
        cout << "Enter the Value In Queue=> ";
        cin >> front->info;
        front->next = NULL;
        rear = front;
        size += 1;
        return;
    }
    // Data Present In Queue
    rear->next = new node;
    rear = rear->next;
    cout << "Enter the Value In Queue=> ";
    cin >> rear->info;
    rear->next = NULL;
    size += 1;
}
// Dequeue Function
void Queue::Dequeue()
{
    // No Data Present In Queue
    if (front == NULL)
    {
        cout << "UnderFlow Condition Occur" << endl;
        return;
    }
    // Data Present In Queue
    temp = front;
    front = front->next;
    delete temp;
    // Queue Become Empty
    if (front == NULL)
        temp = rear = NULL;
    size -= 1;
}
// Display Function
void Queue::Display()
{
    // Empty Queue
    if (front == NULL)
    {
        cout << "=> No Data Present In Queue To Display" << endl;
        return;
    }
    temp = front;
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Queue obj;
    obj.Enqueue();
    obj.Display();
    obj.Dequeue();
    obj.Display();
    return 0;
}