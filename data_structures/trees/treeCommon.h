#ifndef TREE_COMMON_H
#define TREE_COMMON_H
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

/************************* Enumerations ***************************************/
enum MAIN_MENU { ADD = 1, SEARCH, IS_EMPTY, PRINT_BST, HEIGHT_BST, EXIT_MAIN};

#endif
