#include <iostream>
using namespace std;
// Node 
struct node {
    int info;
    node *next;
    node *previous;
};
// Class
class CDoublyList {
private:
    node *head;
    node *temp, *temp1;
    int key, counter;
    bool searchTest;

public:
    CDoublyList();                  // Constructor
    ~CDoublyList();                 // Destructor
    void Add();                     // Add Node At first Node
    void Insert(int val);           // Add Node after key value
    void Print();                   // Print the List
    void Delete();                  // Delete the value from list
    bool IsEmpty();                 // check for list emptiness
    void Search();                  // To search any value In the list
    void InsertAtEnd(int value);    // Add value at last
};

// Constructor
CDoublyList::CDoublyList() {
    head = temp = temp1 = NULL;
    key = counter = 0;
    searchTest = true;
}

// Destructor
CDoublyList::~CDoublyList() {
    if (head == NULL) 
        delete temp, temp1, head;
    else {
        temp = head;
        do {
            temp1 = temp;
            temp->next->previous = temp1->previous;
            temp1->previous->next = temp->next;
            temp = temp->next;
            head = temp;
            delete temp1;
        } while(temp != head);
    }
}
// Add Function
void CDoublyList::Add() {
    // Empty List
    if (head == NULL) {
        head = new node;
        head->next = head->previous = head;
        cout << "Enter the value In List=> ";
        cin >> head->info;
        cout << "=> Node Added Successfully" << endl;
        return;
    }
    // Not Empty List
    temp = head;
    temp = new node;
    temp->next = head;
    temp->previous = head->previous;
    temp->previous->next = temp;
    cout << "Enter the value In List=> ";
    cin >> temp->info;
    head->previous = temp;
    head = temp;
    cout << "=> Node Added Successfully" << endl;
    return;
}
// Print Function
void CDoublyList::Print() {
    // Empty List
    if (head == NULL) {
        cout << "=> No Data Present In the List" << endl;
        return;
    }
    // Data Present
    cout << "Data In the List=> [";
    temp = head;
    do {
        cout << temp->info << " ";
        temp = temp->next;
    } while (temp != head);
    cout << "]" << endl;
}
// Insert Function
void CDoublyList::Insert(int val) {
    // Empty List
    if (head == NULL) {
        cout << "=> No Data Present In the List" << endl;
        return;
    }
    // Searching for key
    cout << "Enter the Key You want to search=> ";
    searchTest = true;
    cin >> key;
    temp = head;
    // Multiple Nodes exist In list
    do {
        if (temp->info == key)  {
            searchTest = false;
            temp1 = new node;
            temp1->info = val;
            temp1->next = temp->next;
            temp1->next->previous = temp1;
            temp->next = temp1;
            temp1->previous = temp;
            temp = temp->next;
        }
        temp = temp->next;
    } while (temp != head);
    // Key Not Found
    if (searchTest) {
        cout << "=> Given Key Is Not Found" << endl;
        return;
    } else {
        cout << "=> Given Key is Added successfully" << endl;
    }
}
// Delete Function
void CDoublyList::Delete() {
    // Empty List
    if (head == NULL) {
        cout << "=> No Data Present In the List" << endl;
        return;
    }
    // Searching for key
    cout << "Enter the Key You want to Delete=> ";
    searchTest = true;
    cin >> key;
    temp = head;
    do {
        if (temp == head && temp->info == key) {
            head->previous->next = head->next;
            head->next->previous = head->previous;
            temp = temp->next;
            delete head;
            head = temp = NULL;
            return;
        }
        // Key Search
        if (temp->info == key)  {
            searchTest = false;
            temp1 = temp->next;
            temp->previous->next = temp1;
            temp1->previous = temp->previous;
            delete temp;
            // For Head Deletion
            if (temp == head) 
                head = temp1;
            temp = head;
        }
        temp = temp->next;
    } while (temp != head);
    // Key Not Found
    if (searchTest) {
        cout << "=> Given Key Is Not Found" << endl;
        return;
    }
}
// Check for List Emptiness
bool CDoublyList::IsEmpty() {
    if (head == NULL) 
        return true;
    else 
        return false;
}
// Push Function
void CDoublyList::InsertAtEnd(int value) {
     // Empty List
    if(head == NULL) {
        head = new node;
        head->info = value;
        head->next = head->previous = head;
        cout << "=> Node Pushed Successfully" << endl;
        return;
    }
    // Node exists
    temp = head;
    temp1 = new node;
    temp1->info = value;
    temp1->previous = temp->previous;
    temp1->next = temp;
    temp->previous->next = temp1;
    temp->previous = temp1;
    cout << "=> Node Added Successfully" << endl;
    return;
}
// Main Function
int main() {            
    CDoublyList l;
    l.InsertAtEnd(5);
    l.Print();
    l.Delete();
    l.Print();
    l.InsertAtEnd(1);
    l.Print();
    return 0;
}