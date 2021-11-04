#include <iostream>
using namespace std;

void UserInterface();    // Function Prototype

struct node {
    int info;
    node *next;
    node *previous;
};

class List {
    private:
        node *head;
        node *temp, *temp1;
        int key, counter;
        bool searchTest;

    public:
        List();                     // Constructor
        ~List();                    // Destructor
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
List::List() {
    head = temp = temp1 = NULL;
    key = counter = 0;
    searchTest = true;
}

// Destructor
List::~List() {
    delete head, temp, temp1;
}
// Add Function
void List::Add() {
    //Empty List
    if (head == NULL) {
        head = new node;
        cout << "Enter the Data In the List=> ";
        cin >> head->info;
        head->next = head->previous = NULL;
        cout << "=> Node Added Successfully" << endl;
        return;
    }
    temp = new node;
    cout << "Enter the Data In the List=> ";
    cin >> temp->info;
    temp->next = head;
    temp->previous = NULL;
    head->previous = temp;
    head = temp;
    cout << "=> Node Added Successfully" << endl;
    return;
}

// Print Function
void List::Print() {
    // Empty List
    if (head == NULL) {
        cout << "=> No Data In the List" << endl;
        return;
    }
    // Data Present In List
    temp = head;
    cout << "Data In the List => [ ";
    while(temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << "]" << endl;
}

// Insert Function
void List::Insert(int val) {
    // Emtpy list
    if (head == NULL) {
        cout << "=> No Data In the List" << endl;
        return;
    }
    // Data Present In List
    temp = head;
    key = 0;
    cout << "Enter the Key that You Want to search and After that You want to Add New Value=> ";
    cin >> key;
    while(temp != NULL) {
        if (temp->info == key) {
            // Key Found
            searchTest = false;
            temp1 = new node;
            temp1->info = val;
            temp1->next = temp->next;
            temp->next = temp1;
            temp1->previous = temp;
            // If Not The Last Node
            if (temp1->next != NULL)
                temp1->next->previous = temp1;
            break;
        }
        temp = temp->next;
    }

    // Key Not Found
    if (searchTest) {
        cout << "=> Given key Is Not Found" << endl;
        return;
    }
}

// Delete First Node
void List::DeleteFirstNode() {
    temp = head;
    delete temp;
    temp1 = head = temp = NULL;
    cout << "=> Deleted and Now No Data Is In List" << endl;
    return;
}
// Delete FunctionFirst
void List::Delete() {
    // Empty Listhead = new node;
    if (head == NULL) {
        head = new node;
        cout << "Enter the Data In the List=> ";
        cin >> head->info;
        head->next = head->previous = NULL;
        cout << "=> Node Added Successfully" << endl;
        return;
    }
    // Data Present
    temp = head;
    key = 0;
    searchTest = true;
    cout << "Enter the Data That You want to Delete=> ";
    cin >> key;
    // Deletion For First Node
    if(temp->next == NULL && temp->previous == NULL && temp->info == key) {
        DeleteFirstNode();
        return;
    }
    // Deletion if Data is At First node
    while(temp->info == key && temp->next != NULL) {
        // Data Present At First Node
        temp1 = temp->next;
        temp->next->previous = NULL;
        delete temp;
        head = temp = temp1;
        searchTest = false;
        // One Node Left
        if(temp->next == NULL && temp->previous == NULL && temp->info == key) {
            DeleteFirstNode();
            return;
        }
    }
    temp = head;
    // Data Is At End or In Center
    while(temp != NULL) {
        if (temp->info == key) {
            // Delete Data FoundIsEmpty
            searchTest = false;
            temp1 = temp->previous;
            temp1->next = temp->next;
            if (temp->next != NULL)
                temp->next->previous = temp1;
            delete temp;
            temp = temp1;
        }
        temp = temp->next;
    }
    if (searchTest) {
        cout << "=> Given Data Is Not Found In the List" << endl;
        return;
    }
}

// Check For List Is Empty Or Not
bool List::IsEmpty() {
    if (head == NULL) {
        cout << "=> No Data In the List" << endl;
        return true;
    }
    cout << "=> Data Present In List" << endl;
    return false;
}

// Search Function
void List::Search() {
    // Empty List
    if (head == NULL) {
        cout << "=> There Is No Data In the List" << endl;
        return;
    }
    temp = head;
    counter = 0;
    key = 0;
    cout << "Enter the Key that You want to Search => ";
    cin >> key;
    while(temp != NULL) {
        if (temp->info == key) {
            counter += 1;
            searchTest = false;
        }
        temp = temp->next;
    }
    if (searchTest) {
        // key Not FoundIsEmpty
        cout << "=> Given Key is not Found In the List" << endl;
    } else {
        // Key Found
        cout << "=> Given Key " << key << " Is Found " << counter << " Times" << endl;
        return;
    }
}
// Push Function
void List::Push(int val) {
    // Empty List
    if (head == NULL) {
        head = new node;
        head->info = val;
        head->next = head->previous = NULL;
        cout << "=> Node Added Successfully" << endl;
        return;
    }
    // Not Empty List
    temp = head;
    while(temp != NULL) {
        if (temp->next == NULL) {
            temp1 = new node;
            temp1->info = val;
            temp->next = temp1;
            temp1->previous = temp;
            temp1->next = NULL;
            cout << "=> Node Added Successfully" << endl;
            break;
        }
        temp = temp->next;
    }
}
// pop Function 
void List::Pop() {
    // Empty List
    if (head == NULL) {
        cout << "=> No Data In the List" << endl;
        return;
    }
    // Only One Node In List
    if (head->next == NULL && head->previous == NULL) {
        delete head;
        head = temp = temp1 = NULL;
        cout << "=> No Node Present In List Now" << endl;
        return;
    }
    // More Then One Node
    temp = head;
    while(temp != NULL) {
        if (temp->next == NULL) {
            temp1 = temp->previous;
            temp1->next = NULL;
            delete temp;
            temp = temp1;
            cout << "=> Last Node Deleted Successfully" << endl;
            break;
        }
        temp = temp->next;
    }
    return;
}
// Main Function
int main() {
    UserInterface();
    return 0;
}

// User Interface
void UserInterface() {
    cout << "\t\t\t ================================== \n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||   Welcome To Linked List       ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t||                                ||\n";
    cout << "\t\t\t ================================== \n";
    List obj;
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