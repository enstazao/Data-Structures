#include <iostream>
using namespace std;

void UserInterface();   // Interface for user

// Array List Class
class List {
    private:
        int *Array, length, size;  // Length => total capcity of the list, size => number of current elements in the list
        int *current;
        bool searchTest;
    public:
        void get(int pos);                          // Get the value at given position
        int update(int value, int pos);             // Update value at given position      
        void add(int pos, int val);                 // Add the value at Given Position
        void insert(int value);                     // Add the Value at available Position
        int returnSize();                           // Return the Length of the List
        void start();                               // Move the current pointer to start
        void end();                                 // Move the current pointer to end
        void Next();                                // Move the current Pointer One Next
        void Back();                                // Move the Current pointer one back
        void keyRemove(int key);   // Using Value   // Remove the Given value
        void positionRemove(int pos);               // Remove the Given Position
        void print();                               // Print the List
        bool find(int value);                       // Find The Value In Array
        List();                                     // Constructor
        bool isFull();                              // Check For List Is Full Or Not
        bool isEmpty();                             // Check For List Is Empty or not
        void clear();                               // Clear the List
        List(int userSize);                         // Default Constructor
        void KeyInsert(int val);                    // Add the value after key
        ~List();                                    // Destructor
        List(List &othrList);                       // Copy Constructor
};

// Constructor
List::List() {
    length = 10;
    size = 0;
    current = NULL;
    Array = new int[length];
    searchTest = true;
    for (int i = 0; i < length; i++)
        *(Array + i) = -1;
}    

// Copy Constructor
List::List(List &othrList) {
    size = othrList.size;
    length = othrList.length;
    Array = new int[length];
    searchTest = true;
    // Copy Only the Data Present
    for (int i = 0; i < size; i++) {
        Array[i] = othrList.Array[i];
    }
}
// Default Constructor
List::List(int userSize) {
    length = userSize;
    size = 0;
    current = NULL;
    searchTest = true;
    Array = new int[length];
    for (int i = 0; i < length; i++)
        *(Array + i) = -1;
}

// Destructor
List::~List() {
    delete [] Array;
}

void List::insert(int value) {
    if (length == size) {
        cout << "=> The Array Is full New Data cannot be Added" << endl;
        return;
    }
    // Array has capacity To add data
    current = Array;
    *(current + size) = value;
    cout << "=> Data Added Successfully" << endl;
    size += 1;   // New Data Added
    return;
}
// get value at given position
void List::get(int pos) {
    current = Array;
    if (pos > size) {
        cout << "There is No Data in this Position ... " << endl;
        return;
    }
    cout << "Data At Given Position is=> " << *(current + pos) << endl;
    return;
}

// Update In Array
int List::update(int value, int pos) {
    current = Array;
    if (pos > size) {
        cout << "Not Finded your given position in array ... " << endl;
        return 0;
    }
    *(current + pos) = value;
    return 1;
}

// Add Data In Array
void List::add(int pos, int val) {
    // Array Is Full
     if (length == size) {
        cout << "=> The Array Is full New Data cannot be Added" << endl;
        return;
    }
    // Position Is not valid
    current = Array;
    if (pos > length)  {
        cout << "=> Position is Greater then array Length" << endl;
        return;
    }
    // Postion Exist In Array
    if (pos <= size) {
        current += size;
        while(current != Array + (pos - 1)) {
            *(current + 1) = *current;
            current -= 1;
        }
        current = Array + pos;
        *current = val;
        size += 1;
        return;
    }
    return;
}

// Print the Array
void List::print() {
    if (size == 0) {
        cout << "=> No Data In the Array" << endl;
        return;
    }
    current = Array;
    cout << "Data In the List=> [";
    while(current != Array + size) {
        cout << *current << " ";
        current += 1;
    }
    cout << "]" << endl;
}

// Get Length
int List::returnSize() {
    if (size == 0) {
        cout << "=> There is No Data In the Array" << endl;
        return 0;
    }
    return size; 
}

// Move The Current Pointer to Start
void List::start() {
    if (size == 0) {
        cout << "=> No Data In the Array To Point By Current" << endl;
        return;
    }
    current = Array;
    cout << "Successfully Pointer Moved to start" << endl;
    return;
}

// Move The Current Pointer to End
void List::end() {
    if (size == 0) {
        cout << "=> No Data In the Array To Point By Current" << endl;
        return;
    }
    current = Array + size;
    cout << "Successfully Pointer Moved to end" << endl;
    return;
}

// move The Current Pointer Next
void List::Next() {
    // Pointer At End
    if (current == (Array + size)) {
        cout << "=> You Are at the end of the Array so cannot move next" << endl;
        return;
    }
    current += 1;
    cout << "=> Pointer Moved Next successfully" << endl;
    return;
}

// Move Pointer Back
void List::Back() {
    //Pointer at start
    if (current == Array) {
        cout << "=> You are at the start so cannot move back" << endl;
        return;
    }
    current -= 1;
    cout << "=> Pointer Moved Back successfully " << endl;
    return;
}

// Remove Using Key
void List::keyRemove(int key) {
    // No Data In the Array
    if (size == 0) {
        cout << "=> No Data Found" << endl;
        return;
    }
    // Search Funcion
    current = Array;
    while(current != (Array + size)) {
        // Key Found
        if (*current == key) {
            while(current != Array + size) {
                *current = *(current + 1);
                current += 1;
            }
            size -= 1;
            cout << "=> Data Removed successfully" << endl;
            return;
        } else {
            // Key Not Found
            current += 1;
            continue;
        }
    }
    cout << "=> Key Not Found" << endl;
    return;
}


// Remove Value Using Index
void List::positionRemove(int pos) {
    // Given Position Not Found
    if (size == 0 || size < pos) {
        cout << "=> No Elements In the Array" << endl;
        return;
    }
    current = Array;
    while(current != (Array + size)) {
        *current = *(current + 1);
        current += 1;
    }
    size -= 1;
    cout << "=> Data Removed Successfully" << endl;
    return;
}

// Find Function
bool List::find(int value) {
    // Array Is Empty
    if (size == 0) {
        cout << "=> No Data In the Array" << endl;
        return false;
    }
    current = Array;
    while(current != (Array + size)) {
        // Search
        if(*current == value) {
            cout << "=> Given Value Is Present In the Array" << endl;
            return true;
        }
        current += 1;
    }
    cout << "=> Given Value Is Not Found In Array" << endl;
    return false;
} 


// List Is Full or not
bool List::isFull() {
    if (size == length) {
        return true;
    } else {
        return false;
    }
}

// List is Empty Or Not
bool List::isEmpty() {
    if (size == 0) {
        return true;
    } else {
        return false;
    }
}

// Clear The list
void List::clear() {
    size = 0;
    cout << "=> Array Cleared Successfully" << endl;
    return;
}
// Key Based Insert
void List::KeyInsert(int val) {
    // Empty List
    if (size == 0) {
        cout << "=> No Data Present In List" << endl;
        return;
    }
    // Get Key From User
    int key = 0;
    cout << "Enter the Key you want to Insert After That=> ";
    cin >> key;
    searchTest = true;

    for (int i = 0; i < size; i++) {
        if (*(Array + i) == key) {
            current = Array + size;
            while(current != (Array + i)) {
                // Movind the Data
                *(current + 1) = *current;
                current -= 1;
            }
            current = Array;
            searchTest = false;
            *(current + i + 1) = val;
            size += 1;
        }
    }
    if (searchTest) {
        cout << "=> Given key Not Found" << endl;
    } else {
        cout << "Data Added Successfully" << endl;
    }
}
// Main Function
int main() {
    List l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.KeyInsert(12);    
    l.print();
    return 0;
}

