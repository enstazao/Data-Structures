#include <iostream>
using namespace std;

// Structure of Node
struct node {
    int info;
    node *next;
};
// Stack Class
class Stack {
    private:
        node *top, *temp;       // Node Pointers
        int size, length;       //size = Data Present length = Capacity to Store Data
    public:
        Stack();                  // Constructor
        ~Stack();                 // Destructor
        void Push(int value);     // Push The Value At the Top
        int Pop();                // Remove Value From Top
        int Top();                // Get the Value From Top
        void Print();            // Print the Stack
};

// Constructor
Stack::Stack() {
    top = temp = NULL;
    size = 0;
    length = 10;
}

// Destructor
Stack::~Stack() {
    if (top == NULL) {
        delete temp, top;
    }
    else {
        while(top != NULL) {
            temp = top;
            top = top->next;
            delete temp;
        }
    }
}

// Push Function to Push the Value At Top of the stack
void Stack::Push(int value) {
    // Stack Is Full
    if (size == length) {
        cout << "=> Stack Is Full Now, More Data Cannot Be Added" << endl;
        return;
    }
    // Empty Stack
    if (size == 0 && top == NULL) {
        top = new node;
        top->info = value;
        top->next = NULL;
        cout << "=> Value Added At Stack Successfully" << endl;
        size += 1;
        return;
    }   
    // Data Present In Stack
    temp = top;
    temp = new node;
    temp->info = value;
    temp->next = top;
    top = temp;
    size += 1;
    cout << "=> Value Added At Stack Successfully" << endl;
    return;
}

// Print Function => To Print the Stack
void Stack::Print() {
    // Empty Stack
    if (size == 0 && top == NULL) {
        cout << "=> No Data Present In Stack To Print It" << endl;
        return;
    }
    // Data Present In Stack
    temp = top;
    cout << "Data Present In Stack Is" << endl;
    while(temp != NULL) {
        cout << temp->info << endl;
        temp = temp->next;
        Pop();
    }
    cout << endl;
}

// Pop Function => Remove Value Form Top
int Stack::Pop() {
    // Empty Stack
    if (size == 0 && top == NULL) {
        cout << "=> No Data In Stack To Pop" << endl;
        return 0;
    }
    // Data Present In Stack
    int popValue = top->info;
    temp = top;
    top = top->next;
    delete temp;
    temp = top;
    size -= 1;
    cout << "Popped Value = " << popValue << endl;
    return popValue;
}

// Top Function => To Return Value From Top
int Stack::Top() {
     // Empty Stack
    if (size == 0 && top == NULL) {
        cout << "=> No Data In Stack To Pop" << endl;
        return 0;
    }
    // Data Present In Stack
    return top->info;
}
int main() {
    Stack s;
    s.Push(15);
   s.Push(20);
    s.Print();
    s.Print();
    return 0;
}