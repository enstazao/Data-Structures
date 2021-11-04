#include <iostream>
using namespace std;

void UserInterface();   // Function ProtoType

struct node {
    int info;
    node *next;                                    // Self Referencing Pointer
};

// List Class
class List {
    private:
        node *head;
        node *temp, *temp1;
        node *max, *min;
        bool searchTest;
    public:
        List();                             // Constructor
        ~List();                            // Destructor
        void Search();                      // Search is the given value exist or Not
        void Delete();                     // Delete the given value from node
        void Print();                     // print the whole list
        void Add();                       // add the value at first 
        void Insert(int val);            // Insert node after search node
        bool IsEmpty();                   // Check for list is empty or Not
        void InsertAtEnd(int val);       // Insert the val at the end of the List
        void RemoveLastValue();          //  linked-list   Removes the Last Element and returns it
        void DeleteMaxMin();             // Delete Maximum and Minimum Value From Linked List
};

// Constructor
List::List() {
    head = temp = temp1 = NULL;
    searchTest = true;
}

// Destructor
List::~List() {
    delete head, temp, temp1;
}

// Search Function
void List::Search() {
    // Empty List
    if (head == NULL) {
        cout << "=> There is No Value in the List to Search ... " << endl;
        return;
    }
    // List Is not Empty
    int key = 0;
    searchTest = true;
    char userChoice;
    int counter = 0;
    cout << "Enter the Key that you want to search => ";
    cin >> key;
    for (temp = head; temp != NULL; temp = temp->next) {
        if (temp->info == key) {
            searchTest = false;
            counter += 1;
        }
    }
    // Check For Value Found
    if (searchTest) {
        // Value Not found
        cout << "=> The Given Key doesnot exist in the List" << endl;
        return;
    } else {
        // Value Found
        cout << "=> Given Key : " << key << " Is Found " << counter << " times In the List." << endl;
        return;
    }
}

// Add Function 
void List::Add() {
    // No Node Exist
    if (head == NULL) {
        head = new node;
        cout << "Enter the value that you want to add In the List => ";
        cin >> head->info;
        head->next = NULL;
        cout << "=> Value Added Successfully ... " << endl;
        return;
    }
    // Node Exist
    temp = new node;
    cout << "Enter the Value that you want to add In the List => ";
    cin >> temp->info;
    temp->next = head;
    head = temp;
    cout << "Value successfully added at First Node ... " << endl;
    return;
}

// Print Function
void List::Print() {
    // No Data In List
    if (head == NULL) {
        cout << "=> No Data In the List to Print" << endl;
        return;
    }
    cout << "Your List Data=> [ ";
    // Data Present In list
    for (temp = head; temp != NULL; temp = temp->next) {
        cout << temp->info << " ";
    }
    cout << "]" << endl;
    return;
}

// Delete Function
void List::Delete() {
    // Empty List
    if (head == NULL) {
        cout << "No Data In the List ... " << endl;
        return;
    }
    int key = 0;
    searchTest = true;
    temp = head;
    cout << "Enter the Data that You Want to delete From List => ";
    cin >> key;
    // If only One Node In list
    if (head->next == NULL && head->info == key) {
        delete head;
        head = NULL;
        cout << "=> Successfully Deleted the key" << endl;
        temp = temp1 = NULL;
        return;
    }
    // search for First node
    while (temp->info == key) {
        temp1 = temp;
        temp = temp1->next;
        delete temp1;
        temp = temp1 = NULL;
        cout << "=> Given Key Deleted Successfully" << endl;
    }
    // Data Presnt In the List
    temp = head;
    while(temp != NULL) {
        if (temp->next == NULL) break;
        if (temp->next->info == key) {
            searchTest = false;
            temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
            cout << "Successfully Deleted the Key ... " << endl;
        }
        temp = temp->next;
    }
    // Key Not Found
    if (searchTest) {
        cout << "=> Key that You Entered Is Not Found In the List" << endl;
        return;
    }
    return;
}

// Check for List Emptiness
bool List::IsEmpty() {
    if (head == NULL) {
        cout << "=> The List is Empty" << endl;
        return true;
    }
    cout << "=> The List is Not Empty" << endl;
    return false;
}

// Insert Function
void List::Insert(int val) {
    // Empty List
    if (head == NULL) {
        cout << "There is Not Data In the List" << endl;
        return;
    }
    // Not empty List
    int key = 0;
    searchTest = true;
    cout << "Enter the Key that You want to serach and after that You want new Node Inserted=> ";
    cin >> key;
    temp = head;
    while(temp != NULL) {
        if (temp->info == key) {
            // Key Found
            searchTest = false;
            temp1 = new node;
            temp1->info = val;
            temp1->next = temp->next;
            temp->next = temp1;
            cout << "=> New Node Added successfully" << endl;
            return;
        }
        temp = temp->next;
    }
    // Key Not Found
    if (searchTest) {
        cout << "=> Given Key Not Found so the New Node is Not Inserted" << endl;
        return;
    }
}

// InsertAtEnd Function
void List::InsertAtEnd(int val) {
    // List Is Empty
    if (head == NULL) {
        head = new node;
        head->info = val;
        head->next = NULL;
        cout << "=> Value is InsertAtEnded Successfully" << endl;
        return;
    }
    // List Is Not Empty
    temp = head;
    while(temp != NULL) {
        if (temp->next == NULL) {
            temp1 = new node;
            temp1->info = val;
            temp1->next = NULL;
            temp->next = temp1;
            cout << "=> Value is InsertAtEnded Successfully" << endl;
            return;
        }
        temp = temp->next;
    }
}

// RemoveLastValue Function
void List::RemoveLastValue() {
    // List Is Empty
    if (head == NULL) {
        cout << "=> No Data In the List to Remove" << endl;
        return;
    }
    temp = head;
    while(temp != NULL) {
        if (temp->next->next == NULL) {
            temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
            cout << "=> Last Node is Deleted Successfully" << endl;
            return;
        }
        temp = temp->next;
    }
}
// Delete Max and Min Function
void List::DeleteMaxMin() {
    // Empty List
    if (head == NULL) {
        cout << "=> No Data Present In List to Delete" << endl;
        return;
    }
    // Search For Max and Min
    max = min = head;
    temp = head;
    while(temp != NULL) {
        if (temp->info > max->info) 
            max = temp;
        if (temp->info < min->info)
            min = temp;
        temp = temp->next;
    }
    // Deletetion For Max And Min
    temp = head;
    while(temp != NULL) {
        // Min Is At First Node
        if (temp == min) {
            temp1 = min;
            head = temp1->next;
            temp = min->next;
            delete temp1;
            temp1 = min = NULL;
        }
        // Max At First Node
        if (temp == max) {
            temp1 = max;
            head = temp1;
            temp = max->next;
            delete temp1;
            temp1 = max = NULL;
        }
        // Min Is At Not First node
        if (temp->next == min) {
            temp1 = min;
            temp->next = min->next;
            temp = min->next;
            delete temp1;
            temp1 = min = NULL;
        }
        // Max Is not First Node
        if (temp->next = max) {
            temp1 = max;
            temp->next = max->next;
            temp = max->next;
            delete temp1;
            temp1 = max = NULL;
        }
        // Delete Successness Check
        if (max == NULL && min == NULL) {
            cout << "=> Deleted Successfully" << endl;
            break;
        }
    }
}
// Main Function
int main() {
    UserInterface();
    return 0;
}

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
         << "\n=> Press 4 To InsertAtEnd Data In the List\n=> Press 5 To RemoveLastValue Data In the List\n=> Press 6 To Delete Data In List"
         << "\n=> Press 7 To Check For List Emptiness\n=> Press 8 To Print List\n=> Press 9 to Delete Max and Min From List=> Press 0 To exit" << endl;
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
            cout << "Enter the Data That You want to InsertAtEnd In the List=> ";
            cin >> val;
            obj.InsertAtEnd(val);
        } else if ( userChoice == 5 ) {
            obj.RemoveLastValue();
        } else if ( userChoice == 6 ) { 
            obj.Delete();
        } else if ( userChoice == 7 ) {
            obj.IsEmpty();
        } else if ( userChoice == 8 ) {
            obj.Print();  
        } else if ( userChoice == 9 ) {
            obj.DeleteMaxMin();
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
