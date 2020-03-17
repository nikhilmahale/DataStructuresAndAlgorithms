#include <iostream>

#include "treeTraversal.h"
#include "treeCommon.h"

/*****************************************************************
 * Function Name: PrintBST
 * Description: Prints BST in Pre-Order Traversal
 *****************************************************************/
void PrintBST(BSTNode* node) {
    static int level = -1;
    level++; //we go deeper at each call
    if(node == (BSTNode*)NULL) { //Adding first element to BST
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
