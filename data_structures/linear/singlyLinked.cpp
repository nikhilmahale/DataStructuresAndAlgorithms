/**********************************************************
 * Author: Nikhil Mahale
 * Description: This code presents a program menu for a
 * singly liked list with following options:
 * 1. Add Node
 * 2. Delete Node
 * 3. Search Node
 * 4. Print all members of the linked list
 **********************************************************/
#include <iostream>
using namespace std;

/********************* Data structures and macros ************/
#define NEWLINE "\n"
/* Singly Linked List Node */
struct Node {
    int value;
    struct Node* next;
};

/************************* Enumerations ***********************/
enum MAIN_MENU { ADD = 1, SEARCH, DELETE, PRINT, EXIT_MAIN};
enum DELETE_MENU { START = 1, END, POSITION, VALUE, EXIT_DELETE};

/************************* Global Variables *******************/
/* Head of the singly linked list */
struct Node* head = NULL;
struct Node* start = NULL;

/********************* Function Prototypes *******************/
void DeleteNodeAtPosition(int);
int SearchElement(int);
/************************* Module functions ******************/
/*************************************************************
 * Function Name: InsertNode
 * Description: This functions dynamically allots memory
 *              to a node and add its to the linked list
 *************************************************************/
void InsertNode(int newValue) {

    struct Node* currentHead = head;
    /* First allocate memory for this node*/
    struct Node* currentNode = (struct Node*)malloc(sizeof(struct Node));
    if(currentNode == NULL) {
        cout << "Malloc failed";
        exit(-1);
    }

    currentNode->next = NULL;
    currentNode->value = newValue;

    if(head == NULL) {
        cout << "Adding first value";
        /* First element in array */
        head = currentNode;
        start = currentNode;
        return;
    } else {
        cout << "Adding subsequent values";
    }

    while((currentHead->next) != NULL) {
        currentHead = currentHead->next;
    }
    currentHead->next = currentNode;

    cout << "Node value is " << currentNode->value;
    cout << "Node next address is " << currentNode->next;
    cout << "Head value is " << head->value;
    cout << "start value is " << start->value;
    return;
}

/*************************************************************
 * Function Name: DeleteNode
 * Description: This functions deletes a node from linked list
 *************************************************************/
void DeleteNode(int option) {
    int search, position;
    switch(option) {
        case START:
            /* just increment start pointer to next node */
            start = start->next;
            break;
        case END:
            break;
        case VALUE:
            cout << "Enter value to be deleted" << NEWLINE << ">> ";
            cin >> search;
            position = SearchElement(search);
            DeleteNodeAtPosition(position);
            break;
        case POSITION:
            cout << "Enter position at which node is to be deleted" << NEWLINE << ">> ";
            cin >> position;
            DeleteNodeAtPosition(position);
            break;
        case EXIT_DELETE:
            break;
        default:
            cout << "Invalid Option for Delete Menu";
    }
}

/*************************************************************
 * Function Name: DeleteNodeAtPosition
 * Description: This functions deletes a node from linked list
 *************************************************************/
void DeleteNodeAtPosition(int pos) {
    cout << "Deleting node at position " << pos;
}

/****************************************************************
 * Function Name: SearchElement
 * Description: This functions searches an element in the linked
 *              list. Function not optimized for time and space
 *              complexity.
 ***************************************************************/
int SearchElement(int searchVal) {
    cout << "Searching value " << searchVal << " in the linked list..." << NEWLINE;
    Node* currentNode = start;
    int pos = 0;//position where value is found
    int valueFound = 0;

    /* Loop through every node from start and print their values */
    do {
        if(currentNode->value == searchVal) {
            valueFound = 1;
            break;
        }
        pos++;
        currentNode= currentNode->next;
    }while(currentNode != NULL);

    if(valueFound == 1) {
        cout << "Value found at position " << pos << NEWLINE;
    }
    else {
        cout << "Value not found in the linked list" << NEWLINE;
    }
    return pos;
}

/****************************************************************
 * Function Name: PrintList
 * Description: This functions prints a complete singly linked
                list
 **************************************************************/
void PrintList(void) {
    cout << "Printing Singly Linked list values:" << NEWLINE;

    /* Exit gracefully if list is empty and nothing to print */
    if(start == NULL) {
        cout << "List is empty. Nothing to print" << NEWLINE;
        exit(0);
    }

    Node* currentNode = start;
    /* Loop through every node from start and print their values */
    do {
        cout << " -> " << currentNode->value;
        currentNode= currentNode->next;
    }while(currentNode != NULL);

    cout << NEWLINE;
    cout << "Finished printing list" << NEWLINE;
}

/**************************************************************/
int main() {
    int selection, newElement, option;
    while(1) {
        cout << "***************************" << NEWLINE;
        cout << "Menu Singly Linked List" << NEWLINE;
        cout << "***************************" << NEWLINE;
        cout << "Select an option:" << NEWLINE;
        cout << "1. Add a Node" << NEWLINE;
        cout << "2. Search an element" << NEWLINE;
        cout << "3. Delete a Node" << NEWLINE;
        cout << "4. Print the linked list" << NEWLINE;
        cout << "5. Exit Menu" << NEWLINE;
        cout << "***************************" << NEWLINE;
        cout << ">> ";
        cin >> selection;

        switch(selection) {
            case ADD:
                cout << "Adding a value of node: " << NEWLINE;
                cout << "Enter value to be added " << NEWLINE;
                cin >> newElement;
                InsertNode(newElement);
                break;
            case SEARCH:
                cout << "Searching an element " << NEWLINE;
                cout << "Enter value to be searched " << NEWLINE;
                cin >> newElement;
                SearchElement(newElement);
                break;
            case DELETE:
                cout << "    Deleting Node. Select an option:" << NEWLINE;
                cout << "    1. Delete Node at Start" << NEWLINE;
                cout << "    2. Delete Node at End" << NEWLINE;
                cout << "    3. Delete Nth Node" << NEWLINE;
                cout << "    4. Delete Node with a value" << NEWLINE;
                cout << "    5. Exit Delete Menu" << NEWLINE;
                cout << "    >> ";
                cin >> option;
                DeleteNode(option);
                break;
            case PRINT:
                cout << "Printing the singly linked list " << NEWLINE;
                PrintList();
                break;
            case EXIT_MAIN:
                cout << "Singly Link List Menu Exited.." << NEWLINE;
                exit(0);
                break;
            default:
                cout << "Invalid choice exiting menu...";
        }
        cout << "***************************" << NEWLINE;
    }
    return 0;
}
