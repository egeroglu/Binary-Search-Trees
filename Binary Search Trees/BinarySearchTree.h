#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryNode.h"
#include <iostream>

using namespace std;
class BinarySearchTree{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& tree);
    ~BinarySearchTree();
    void destroyTree(BinaryNode*& treePtr);
    void copyTree(BinaryNode* treePtr, BinaryNode*& newTreePtr)const;
    bool isEmpty();
    int getHeight();
    int getNumberOfNodes();
    bool add(const int newEntry);
    bool remove(const int anEntry);
    bool contains(const int anEntry);
    void containsHelper(BinaryNode* node, int anEntry, bool& success);
    void display(int& anItem);
    void inorder(BinaryNode* node);
    void mirrorHelper(BinaryNode* node);
    void insertHelper(BinaryNode*& node, int newEntry, bool& check);
    void processLeftmost(BinaryNode *&node, int& anEntry);
    void levelorderTraverse();
    bool printLevel(BinaryNode* node, int level);
    int span(const int a, const int b);
    void mirror();
    void levelorderHelper(BinaryNode* node, int& lvl);
    void inorderMirror(BinaryNode* node);
    void spanHelper(BinaryNode* node, int& spanCount, const int a, const int b);
    void postorder(BinaryNode* node);
    void preorder(BinaryNode* node);
    int getHeightHelper(BinaryNode* node);
    void getNumberOfNodesHelper(BinaryNode* node, int& numberOfNode);
    void deleteItem(BinaryNode * &node, int anEntry,bool& success);
    void deleteNodeItem(BinaryNode*& node);
    void preorderTraverse();
    void preorderTraverseHelper(BinaryNode* node);
    void inorderTraverse();
    void inorderTraverseHelper(BinaryNode* node);
    void postorderTraverse();
    void postorderTraverseHelper(BinaryNode* node);

    BinaryNode *root;
};
#endif // end of BINARYSEARCHTREE_H
