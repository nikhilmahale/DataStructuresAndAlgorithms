/**********************************************************
 * Author: Nikhil Mahale
 * Description: This code presents a program menu for a
 * binary search tree. BST is created using a
 * a doubly linked list. Following options are provided
 * in the menu
 * 1. Add (Add element to the BST)
 * 2. Search (Search element in the BST)
 * 3. IsEmpty (Tells whether BST is empty)
 * 4. Print BST (Print completes BST in tree format)
 * 5. Height of BST
 **********************************************************/
#include <iostream>
using namespace std;

/********************* Data structures and macros ************/
#define NEWLINE "\n"
#define TRUE 1
#define FALSE 0

/* A node in a BST */
struct BSTNode {
    int value;
    BSTNode* left;
    BSTNode* right;
};
typedef int BOOLEAN;
int RightHeight = -1, LeftHeight = -1;
/************************* Enumerations ***************************************/
enum MAIN_MENU { ADD = 1, SEARCH, IS_EMPTY, PRINT_BST, HEIGHT_BST, EXIT_MAIN};

/************************* Global Variables ***********************************/
/* root of binary search tree */
BSTNode* RootPtr = NULL;
int IsEmpty = TRUE;

/********************* Function Prototypes *******************/
int AddNode(int, BSTNode*);
BOOLEAN SearchNode(int);
BOOLEAN IsBSTEmpty(int);
void PrintBST(BSTNode*);
int HeightOfBST(void);

/************************* Module functions ******************/
/*****************************************************************
 * Function Name: AddNode
 * Description: TBD
 *****************************************************************/
int AddNode(int newValue, BSTNode* node) {
    if(RootPtr == (BSTNode*)NULL) { //Adding first element to BST
        RootPtr = (BSTNode*)malloc(sizeof(BSTNode));
        cout << "Adding root node to BST" << NEWLINE;
        RootPtr->value = newValue;
        RootPtr->left = NULL;
        RootPtr->right = NULL;
        LeftHeight++;
        RightHeight++;
    } else {
        if(newValue < (node->value)) {
            LeftHeight++;
            cout << newValue << " is smaller than " << node->value << " hence adding at left";
            /* Add smaller values to left */
            if(node->left == NULL) {
                BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
                newNode->value = newValue;
                newNode->left = NULL;
                newNode->right = NULL;
                node->left = newNode;
            } else {
                AddNode(newValue, node->left);
            }
        } else {
            RightHeight++;
            cout << newValue << " is greater than " << node->value << " hence adding at right";
            /* Add bigger values to right */
            if(node->right == NULL) {
                BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
                newNode->value = newValue;
                newNode->left = NULL;
                newNode->right = NULL;
                node->right = newNode;
            } else {
                AddNode(newValue, node->right);
            }
        }
    }

    return 0;
}

/*****************************************************************
 * Function Name: IsBSTEmpty
 * Description: Returns TRUE if BST is empty, else FALSE.
 *****************************************************************/
int IsBSTEmpty() {
    if(RootPtr == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*****************************************************************
 * Function Name: HeightOfBST
 * Description: TBD
 *****************************************************************/
int HeightOfBST() {
    if(LeftHeight > RightHeight) {
        return LeftHeight;
    }
    else if (LeftHeight < RightHeight){
        return RightHeight;
    }
    else {
        return 0;
    }
}

/*****************************************************************
 * Function Name: PrintBST
 * Description: TBD
 *****************************************************************/
void PrintBST(BSTNode* node) {
    static int level = -1;
    level++; //we go deeper at each call
    if(RootPtr == (BSTNode*)NULL) { //Adding first element to BST
        cout << "BST is empty. Nothing to print" << NEWLINE;
    } else {
        cout << NEWLINE;
        //cout << "Values at level " << level << "are ";
        if((node->left == NULL) && (node->right == NULL)) {
            cout << node->value << " " << NEWLINE;
        }
        else if((node->left == NULL) && (node->right != NULL)) {
            cout << node->value << " " << NEWLINE;
            PrintBST(node->right);
        }
        else if((node->right == NULL) && (node->left != NULL)) {
            cout << node->value << " " << NEWLINE;
            PrintBST(node->right);
        }
        else {
            cout << node->value << " " << NEWLINE;
            PrintBST(node->left);
            PrintBST(node->right);
        }
    }
}

/**************************************************************/
int main() {
    int selection, newElement;
    while(1) {
        cout << "***************************" << NEWLINE;
        cout << "BST using Linked List Functions" << NEWLINE;
        cout << "***************************" << NEWLINE;
        cout << "Select an option:" << NEWLINE;
        cout << "1. Add Node to BST" << NEWLINE;
        cout << "2. Search a value in BST" << NEWLINE;
        cout << "3. Is BST Empty" << NEWLINE;
        cout << "4. Print Binary Search Tree" << NEWLINE;
        cout << "5. Height of BST" << NEWLINE;
        cout << "6. Exit" << NEWLINE;
        cout << "***************************" << NEWLINE;
        cout << ">> ";
        cin >> selection;

        switch(selection) {
            case ADD:
                cout << "Enter value to be added to BST " << NEWLINE;
                cin >> newElement;
                AddNode(newElement, RootPtr);
                break;
            case SEARCH:
                break;
            case IS_EMPTY:
                break;
            case PRINT_BST:
                PrintBST(RootPtr);
                break;
            case HEIGHT_BST:
                cout << "Height is " << HeightOfBST();
                break;
            case EXIT_MAIN:
                cout << "Binary Search Tree using linked list Menu Exiting.." << NEWLINE;
                exit(0);
                break;
            default:
                cout << "Invalid choice exiting menu...";
        }
        cout << "***************************" << NEWLINE;
    }
    return 0;
}
