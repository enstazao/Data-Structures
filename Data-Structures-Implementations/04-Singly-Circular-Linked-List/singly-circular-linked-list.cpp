#include <iostream>
using namespace std;

// User Interface Function prototype
void UserInterface();

struct node {
    int info;
    node *next;
};

class CList {
    private:
        node *head;
        node *temp, *temp1;
        int key, counter;
        bool searchTest;

    public:
        CList();                     // Constructor
        ~CList();                    // Destructor
        void Add();                 // Add Node At first Node
        void Insert(int val);       // Add Node after key value
        void Print();               // Print the List 
        void Delete();              // Delete the value from list
        void DeleteFirstNode();     // For Deleting first node
        bool IsEmpty();             // check for list emptiness
        void Search();              // To search any value In the list
        void Push(int val);         // Push The Value At End
        void Pop();                 // Removes The Last Node
};

// Constructor
CList::CList() {
    head = temp = temp1 = NULL;
    key = counter = 0;
    searchTest = true;
}
// Destructor
CList::~CList() {
    delete head, temp, temp1;
}
// Add Function
void CList::Add() {
    // Empty List
    if (head == NULL) {
        head = new node;
        cout << "Enter the Value In the List => ";
        cin >> head->info;
        head->next = head;
        cout << "=> Node Created Successfully" << endl;
        return;
    }
    // Node Present In List
    temp1 = new node;
    cout << "Enter the Value In the List=> ";
    cin >> temp1->info;
    temp1->next = head;
    temp = head;
    do {
        if (temp->next == head) {
            // Last Node reached
            temp->next = temp1;
            head = temp1;
            cout << "=> Node Added Successfully" << endl;
            return;
        }
        temp = temp->next;
    } while(temp != head);
}
// Print Function
void CList::Print() {
    // List Is empty
    if (head == NULL) {
        // List Is Empty
        cout << "=> No Data To Print" << endl;
        return;
    }
    temp = head;
    cout << "Data In the List=> [";
    do{
        cout << temp->info << " ";
        temp = temp->next;
    } while(temp != head);
    cout << "]" << endl;
}
// Insert Function
void CList::Insert(int value) {
    // Empty List
    if (head == NULL) {
        cout << "=> No Data Present In List" << endl;
        return;
    }
    key = 0;
    searchTest = true;
    cout << "Enter the Key You want to Add Value After It=> ";
    cin >> key;
    temp = head;
    do {
        if (temp->info == key) {
            searchTest = false;
            temp1 = new node;
            temp1->info = value;
            temp1->next = temp->next;
            temp->next = temp1;
            temp = temp->next;
        }
        temp = temp->next;
    } while(temp != head);
    if (searchTest) {
        cout << "=>Given Key Not Found" << endl;
    }
}
// Delete Function
void CList::Delete() {
    // Empty List
    if (head == NULL) {
        cout << "=> No Data Present In List to Delete" << endl;
        return;
    }
    // Deletion For First Node
    temp = head;
    key = 0;
    cout << "Enter the Key You want to Delete=> ";
    cin >> key;
    while(temp->info == key) {
        temp1 = temp;
        do{
            temp = temp->next;
        } while(temp->next != head);
        searchTest = false;
        if (temp1->next == head) {
            cout << "=> This is your Last Node After deletion List is Empty" << endl;
            delete temp1;
            temp = head = temp1 = NULL;
            return;
        } else {
            temp->next = temp1->next;
            head = temp1->next;
            delete temp1;
            temp1 = temp = head;
        }
    }
    // Deletion for last and mid nodes
    temp = head;
    do{
        if(temp->next->info == key) {
            // Key Found
            temp1 = temp->next;
            searchTest = false;
            temp->next = temp1->next;
            delete temp1;
        }
        temp = temp->next;
    } while(temp != head);
    if (searchTest) 
        cout << "=> Given Key Is Not Found" << endl;
}
// Search Function
void CList::Search() {
    // Empty List
    if (head == NULL) {
        cout << "=> List Is Empty" << endl;
        return;
    }
    temp = head;
    key = counter = 0;
    cout << "Enter the key you want to search=> ";
    cin >> key;
    do {
        if (temp->info == key) {
            searchTest = false;
            counter += 1;
        } 
        temp = temp->next;
    }while(temp != head);
    if (searchTest)
        cout << "=> Given Key Not Found In the List" << endl;
    else
        cout << "Given Key is Found => " << counter << " times In the List" << endl;
}
// Check For List Emptiness
bool CList::IsEmpty() {
    if (head == NULL) {
        // List Is empty
        return true;
    } else {
        // Not Empty
        return false;
    }
}
// Push Function
void CList::Push(int value) {
    // Empty List
    if(head == NULL) {
        head = new node;
        head->info = value;
        head->next = head;
        cout << "=> Node Pushed Successfully" << endl;
        return;
    }
    // Node exists
    temp = head;
    do {
        if (temp->next == head) {
            temp1 = new node;
            temp1->info = value;
            temp1->next = temp->next;
            temp->next = temp1;
            cout << "=> Node Added Successfully" << endl;
            return;
        }
        temp = temp->next;
    } while(temp != head);
}
// Pop Function
void CList::Pop() {
    // No Node Present
    if (head == NULL) {
        cout << "=> No Node Present To Pop" << endl;
        return;
    }
    // For First Node
    if (head->next == head) {
        temp = head;
        delete temp;
        temp = head = temp1 = NULL;
        cout << "=> List Last Item Popped Successfully" << endl;
    }
    // Mulitple Node Present In List
    temp = head;
    do {
        if (temp->next->next == head) {
            temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
            temp1 = temp;
            cout << "=> Last Item Popped Successfully" << endl;
            return;
        }
        temp = temp->next;
    } while(temp != head);
}
int main() {
    UserInterface();
    return 0;
}

// User Interface
void UserInterface() {
    cout << "\t\t\t ================================== \n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||   Welcome To Circular List     ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t ================================== \n";
    CList obj;
    int val = 0;
    int userChoice = 1;
    cout << "\n=> Press 1 To Add Data In the List\n=> Press 2 To Insert Data In the List: \n=> Press 3 To Search Data In List"
         << "\n=> Press 4 To Push Data In the List\n=> Press 5 To Pop Data In the List\n=> Press 6 To Delete Data In List"
         << "\n=> Press 7 To Check For List Emptiness\n=> Press 8 To Print List\n=> Press 0 To exit" << endl;
    while(userChoice) {
        cout << "Enter The  Operation You want to Perform=> ";
        cin >> userChoice;
        if ( userChoice == 1 ) {
            obj.Add();
        } else if ( userChoice == 2 ) {
            val = 0;
            cout << "Enter the Value That You want to Insert In List=> ";
            cin >> val;
            obj.Insert(val);
        } else if ( userChoice == 3 ) {
            obj.Search();
        } else if (userChoice == 4 ) {
            val = 0;
            cout << "Enter the Data That You want to Push In the List=> ";
            cin >> val;
            obj.Push(val);
        } else if ( userChoice == 5 ) {
            obj.Pop();
        } else if ( userChoice == 6 ) { 
            obj.Delete();
        } else if ( userChoice == 7 ) {
            obj.IsEmpty();
        } else if ( userChoice == 8 ) {
            obj.Print();
        } else if ( userChoice == 0 ) {
            userChoice = 0;
            cout << "\t\t\t-------------------------------------------------------------------------  \n\t\t\t\t" << endl;
            cout << "\t\t\t############################   GOOD BYE   ############################### \n\t\t\t\t" << endl;
            cout << "\t\t\t-------------------------------------------------------------------------  \n\t\t\t\t" << endl; 
        } else {
            cout << "=> Enter the Correct Option" << endl;
        }
    }
}



/************************************************* END ***********************************************************************/