#include <iostream>
using namespace std;

void UserInterface();   // Function ProtoType

class ArrayStack {
    private:
        int * stack;
        int * top;
        int length;
    public:
        ArrayStack();               // Constructor
        ~ArrayStack();              // Destructor
        void Push(int val);         // Push Value At Top
        int Pop();                  // Remove Value From Top
        int Top();                  // Get the Value From Top
        void Display();               // Display the Stack
};

// Constructor
ArrayStack::ArrayStack() {
    length = 10;
    stack = new int[length];
    top = stack;
}
// Destructor
ArrayStack::~ArrayStack() {
   delete [] stack;
}
// Push Function
void ArrayStack::Push(int val) {
    // Array Is Full
    if (top == (stack + length)) {
        cout << "=> Stack Overflow Occur" << endl;
        return;
    }
    *(top) = val;   // Value Inserted
    top += 1;
}
// Pop Function
int ArrayStack::Pop() {
    // Empty Stack
    if (top == stack) {
        return -1;
    }
    int poppedData = *(top - 1);
    cout << "Popped Data=> " << poppedData << endl;
    top -= 1;
    return poppedData;
}
// Top Function
int ArrayStack::Top() {
    // Empty Stack
    if (top == stack) 
        return -1;
    // Data Present In Stack
    return *(top - 1);
}
// Display Function
void ArrayStack::Display() {
    // Empty Stack
    if (top == stack) {
        cout << "=> No Data Present" << endl;
        return;
    }
    cout << "Data Present In Stack=> ";
    for (int *i = stack; i != top; i++) {
        cout << *i << " ";
    }
    cout << endl;
}
int main() {
    UserInterface();
    return 0;
}

void UserInterface() {
    cout << "\t\t\t ================================== \n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||   Welcome To Array Stack       ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t ================================== \n";
    ArrayStack obj;
    int val = 0;
    int userChoice = 0;
    do {
        cout << "\nPress 1 For Push\nPress 2 for Pop\nPress 3 for Top Value\nPress 4 for Display the stack\nPress 0 to Exit\nEnter Your Input=> ";
        cin >> userChoice;
        switch(userChoice) {
            case 1:
                cout << "Enter the Value You Want to Push=> ";
                cin >> val;
                obj.Push(val);
                break;
            case 2:
                if (obj.Pop() == -1) {
                     cout << "=> Stack Underflow Occur" << endl;
                     break;
                }
                cout << "Data Popped Successfully" << endl;
                break;
            case 3: 
                if (obj.Top() == -1) {
                    cout << "=> No Data Present In Stack" << endl;
                    break;
                }
                cout << "Value At Top Of Stack is=> " << obj.Top() << endl;
                break;
            case 4:
                obj.Display();
                break;
            case 0:
                    cout << "\t\t\t ======================================= \n";
                    cout << "\t\t\t||                                       ||\n";
                    cout << "\t\t\t||                                       ||\n";
                    cout << "\t\t\t||   Thanks For Using Array Stack        ||\n";
                    cout << "\t\t\t||                                       ||\n";
                    cout << "\t\t\t||                                       ||\n";
                    cout << "\t\t\t =======================================  \n";
                break;
            default:
                cout << "Wrong Input" << endl;
                break;
        }
    } while(userChoice != 0);
}