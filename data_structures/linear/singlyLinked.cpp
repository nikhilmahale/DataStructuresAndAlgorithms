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

/************************* Global Variables *******************/
/* Head and start of the singly linked list */
struct Node* head = NULL;
struct Node* start = NULL;

/************************* Module functions ******************/
/*************************************************************
 * Function Name: InsertNode
 * Description: This functions dynamically allots memory
 *              to a node and add its to the linked list
 *************************************************************/
void InsertNode(int newValue)  {

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
void DeleteNode(int value)  {
    return;
}

/****************************************************************
 * Function Name: SearchElement
 * Description: This functions searches an element in the linked
 *              list. Function not optimized for time and space
 *              complexity.
 ***************************************************************/
int SearchElement(int searchVal)  {
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
    return 0;
}

/****************************************************************
 * Function Name: PrintList
 * Description: This functions prints a complete singly linked
 int*              list
 **************************************************************/
void PrintList(void)  {
    cout << "Printing Singly Linked list values:" << NEWLINE;

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
    int selection, newElement;
    while(1) {
        cout << "***************************" << NEWLINE;
        cout << "Menu Singly Linked List" << NEWLINE;
        cout << "Select an option:" << NEWLINE;
        cout << "1. Add a Node" << NEWLINE;
        cout << "2. Search an element" << NEWLINE;
        cout << "3. Delete a Node" << NEWLINE;
        cout << "4. Print the linked list" << NEWLINE;
        cout << "5. Exit Menu" << NEWLINE;
        cout << ">> ";
        cin >> selection;

        switch(selection) {
            case 1: cout << "Adding a value of node: " << NEWLINE;
                    cout << "Enter value to be added " << NEWLINE;
                    cin >> newElement;
                    InsertNode(newElement);
                    break;
            case 2: cout << "Searching an element " << NEWLINE;
                    cout << "Enter value to be searched " << NEWLINE;
                    cin >> newElement;
                    SearchElement(newElement);
                    break;
            case 3: cout << "Deleting a node " << NEWLINE;
                    cout << "Enter node number to be Deleted " << NEWLINE;
                    cin >> newElement;
                    SearchElement(newElement);
                    break;
            case 4: cout << "Printing the singly linked list " << NEWLINE;
                    PrintList();
                    break;
            case 5: cout << "Menu Exited.." << NEWLINE;
                    exit(0);
                    break;
            default: cout << "Invalid choice exiting menu...";
        }
    }
    cout << "***************************" << NEWLINE;
    return 0;
}
