/**********************************************************
 * Author: Nikhil Mahale
 * Description: This code presents a program menu for a
 * stack with following options:
 * 1. Push
 * 2. Pop
 * 3. Is Stack Empty?
 * 4. Value at Top of Stack(Doesnt remove the top value)
 **********************************************************/
#include <iostream>
using namespace std;

/********************* Data structures and macros ************/
#define NEWLINE "\n"
#define TRUE 1
#define FALSE 0
#define STACK_ARRAY_SIZE 5

int StackArray[STACK_ARRAY_SIZE];
typedef int BOOLEAN;

/************************* Enumerations ***************************************/
enum MAIN_MENU { PUSH = 1, POP, IS_EMPTY, TOP_VALUE, PRINT_STACK, EXIT_MAIN};

/************************* Global Variables ***********************************/
/* Index of top of stack */
int TopIndex = -1;
int IsEmpty = TRUE;

/********************* Function Prototypes *******************/

/************************* Module functions ******************/
/*****************************************************************
 * Function Name: Push
 * Description: This functions pushes a value at top of the stack
 *****************************************************************/
int Push(int value) {
    if(TopIndex >= STACK_ARRAY_SIZE) {
        cout << "ARRAY OVERFLOW!!. Cannot complete push operation.";
        return -1;
    }

    TopIndex++;
    StackArray[TopIndex] =value;
    return 0;
}

/*****************************************************************
 * Function Name: Pop
 * Description: This functions pops a value from top of the stack
 *****************************************************************/
int Pop() {
    int popValue;
    if(IsStackEmpty()) {
        cout << "Stack is Empty. Nothing to pop.";
        return -1;
    }

    popValue = StackArray[TopIndex];
    TopIndex--;
    return popValue;
}

/*******************************************************************
 * Function Name: IsEmpty
 * Description: This functions returns TRUE if Stack is empty, else
 *              FALSE.
 *******************************************************************/
BOOLEAN IsStackEmpty() {
    if(TopIndex == -1) {
        IsEmpty = TRUE;
    }
    else {
        IsEmpty = FALSE;
    }
    return TRUE;
}

/********************************************************************
 * Function Name: ValueAtTop
 * Description: This functions return a value from top of the stack.
 *              This value is not removed from the stack.
 *****************************************************************/
int ValueAtTop() {
    if(IsStackEmpty()) {
        cout << "Stack is Empty. No value at top.";
        return -1;
    }

    return StackArray[TopIndex];
}

/********************************************************************
 * Function Name: PrintStack
 * Description: This functions prints the elements of the stack.
 *****************************************************************/
int PrintStack() {
    int index;
    if(IsStackEmpty()) {
        cout << "Stack is Empty. Nothing to print.";
        return -1;
    }

    cout << NEWLINE;
    for(index = 0; index<= TopIndex; index++) {
        cout << StackArray[TopIndex] << NEWLINE;
    }
    return 0;
}
/**************************************************************/
int main() {
    int selection, newElement, option;
    while(1) {
        cout << "***************************" << NEWLINE;
        cout << "Stack using Array Functions" << NEWLINE;
        cout << "***************************" << NEWLINE;
        cout << "Select an option:" << NEWLINE;
        cout << "1. Push" << NEWLINE;
        cout << "2. Pop" << NEWLINE;
        cout << "3. Check if Stack is Empty" << NEWLINE;
        cout << "4. Value at top" << NEWLINE;
        cout << "5. Print Complete Stack" << NEWLINE;
        cout << "6. Exit" << NEWLINE;
        cout << "***************************" << NEWLINE;
        cout << ">> ";
        cin >> selection;

        switch(selection) {
            case PUSH:
                cout << "Adding a value of node: " << NEWLINE;
                cout << "Enter value to be added " << NEWLINE;
                cin >> newElement;
                InsertNode(newElement);
                break;
            case POP:
                cout << "Searching an element " << NEWLINE;
                cout << "Enter value to be searched " << NEWLINE;
                cin >> newElement;
                SearchElement(newElement);
                break;
            case IS_EMPTY:
                cin >> option;
                DeleteNode(option);
                break;
            case TOP_VALUE:
                cout << "Value at top is  " << ValueAtTop() << NEWLINE;
                break;
            case PRINT_STACK:
                PrintStack();
                break;
            case EXIT_MAIN:
                cout << "Stack Using Array Menu Exiting.." << NEWLINE;
                exit(0);
                break;
            default:
                cout << "Invalid choice exiting menu...";
        }
        cout << "***************************" << NEWLINE;
    }
    return 0;
}
