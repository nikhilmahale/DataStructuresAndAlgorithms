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
enum MAIN_MENU { READYMADE = 0, ADD, SEARCH, IS_EMPTY, PRINT_BST, HEIGHT_BST, EXIT_MAIN};
enum BST_PRINT { PRE_ORDER = 1, IN_ORDER, POST_ORDER };

#endif
