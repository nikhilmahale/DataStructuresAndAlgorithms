#include <iostream>

#include "treeTraversal.h"
#include "treeCommon.h"

void PrintBstPreOrder(BSTNode* node) {
    if(node == NULL) { //Adding first element to BST
	return;
    } 
    else {
        cout << NEWLINE;
        cout << node->value << " " << NEWLINE;
        PrintBstPreOrder(node->left);
        PrintBstPreOrder(node->right);
    }
}

void PrintBstInOrder(BSTNode* node) {
    if(node == NULL) { //Adding first element to BST
	return;
    } 
    else {
        cout << NEWLINE;
        PrintBstInOrder(node->left);
        cout << node->value << " " << NEWLINE;
        PrintBstInOrder(node->right);
    }
}

void PrintBstPostOrder(BSTNode* node) {
    if(node == NULL) { //Adding first element to BST
	return;
    } 
    else {
        cout << NEWLINE;
        PrintBstPostOrder(node->left);
        PrintBstPostOrder(node->right);
        cout << node->value << " " << NEWLINE;
    }
}
