/**********************************************************
 * Author: Nikhil Mahale
 * Description: This code presents a program menu for a
 * stack with following options. Stack is created using a
 * fixed dimensional array :
 * 1. Push (Adds value to top of stack)
 * 2. Pop (Removes value from top of stack)
 * 3. Is Stack Empty
 * 4. Value at Top of Stack (Doesn't remove the top value)
 * 5. Print Stack
 **********************************************************/
#include <iostream>
using namespace std;

/********************* Data structures and macros ************/
#define NEWLINE "\n"
#define TRUE 1
#define FALSE 0
#define STACK_ARRAY_SIZE 100

int StackArray[STACK_ARRAY_SIZE];
typedef int BOOLEAN;

/************************* Enumerations ***************************************/
enum MAIN_MENU { PUSH = 1, POP, IS_EMPTY, TOP_VALUE, PRINT_STACK, EXIT_MAIN};

/************************* Global Variables ***********************************/
/* Index of top of stack */
int TopIndex = -1;
int IsEmpty = TRUE;

/********************* Function Prototypes *******************/
BOOLEAN IsStackEmpty(void);
int Push(int);
int Pop(void);
int PrintStack(void);

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

    TopIndex = TopIndex + 1;
    StackArray[TopIndex] = value;
    cout << "Top Index is" << TopIndex;
    return 0;
}

/*****************************************************************
 * Function Name: Pop
 * Description: This functions pops a value from top of the stack
 *****************************************************************/
int Pop() {
    int popValue;
    if(IsStackEmpty()) {
        cout << "Stack is Empty. Nothing to pop." << NEWLINE;
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
    return IsEmpty;
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
        cout << "Stack is Empty. Nothing to print." << NEWLINE;
        return -1;
    }

    cout << "***** Stack Top *****" << NEWLINE;
    for(index = TopIndex; index >= 0; index--) {
        cout << "***** " << StackArray[index] << " *****" << NEWLINE;
    }
    cout << "***** Stack Bottom *****" << NEWLINE;
    return 0;
}

/**************************************************************/
int main() {
    int selection, newElement, isEmpty;
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
                cout << "Enter value to be pushed " << NEWLINE;
                cin >> newElement;
                Push(newElement);
                break;
            case POP:
                newElement = Pop();
                cout << "Popped value is " << newElement << NEWLINE;
                break;
            case IS_EMPTY:
                isEmpty = IsStackEmpty();
                if(isEmpty == TRUE) {
                    cout << "Stack is Empty" << NEWLINE;
                }
                else {
                    cout << "Stack is Not Empty" << NEWLINE;
                }
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
