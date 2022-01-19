#include "BinarySearchTree.h"
using namespace std;
BinarySearchTree::BinarySearchTree() : root(NULL)
{

}
BinarySearchTree::~BinarySearchTree()
{
    destroyTree(root);
}
void BinarySearchTree::destroyTree(BinaryNode*& treePtr)
{
    if (treePtr != NULL)
    {
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }

}
BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree)
{
    copyTree(tree.root,root);
}
void BinarySearchTree::copyTree(BinaryNode* treePtr, BinaryNode*& newTreePtr)const
{

    if (treePtr != NULL)  		// copy node
    {
        newTreePtr = new BinaryNode(treePtr->item, NULL, NULL);
        copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
        copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
    }
    else
        newTreePtr = NULL;	// copy empty tree
}
void BinarySearchTree::insertHelper(BinaryNode*& node, int newEntry, bool& check)
{
    if(node == NULL)
    {
        node = new BinaryNode(newEntry, NULL, NULL);
    }
    else if(newEntry < node->item)
    {
        insertHelper(node->leftChildPtr, newEntry, check);
    }
    else if(newEntry > node->item)
    {
        insertHelper(node->rightChildPtr, newEntry, check);
    }
    else
    {
        check = false;
    }
}
bool BinarySearchTree::add(const int newEntry)
{
    bool success = true;
    insertHelper(root, newEntry, success);
    return success;
}
void BinarySearchTree::processLeftmost(BinaryNode *&node, int& anEntry)
{

    if (node->leftChildPtr == NULL)
    {
        anEntry = node->item;
        BinaryNode *delPtr = node;
        node = node->rightChildPtr;
        delPtr->rightChildPtr = NULL; // defense
        delete delPtr;
    }
    else
        processLeftmost(node->leftChildPtr, anEntry);
}
void BinarySearchTree::deleteNodeItem(BinaryNode*& node)
{
    BinaryNode* delPtr;
    int replacementItem;


    // (1)  Test for a leaf
    if ( (node->leftChildPtr == NULL) &&
            (node->rightChildPtr == NULL) )
    {
        delete node;
        node = NULL;
    }


    // (2)  Test for no left child
    else if (node->leftChildPtr == NULL)
    {
        delPtr = node;
        node = node->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }

    // (3)  Test for no right child
    else if (node->rightChildPtr == NULL)
    {
        // ...
        delPtr = node;
        node = node->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }


    // (4)  There are two children:
    //      Retrieve and delete the inorder successor
    else
    {
        processLeftmost(node->rightChildPtr, replacementItem);
        node->item = replacementItem;
    }
}
void BinarySearchTree::deleteItem(BinaryNode * &node, int anEntry,bool& success)
{
    if (node == NULL) // Empty tree
        success = false;
    // Position of deletion found
    else if (anEntry == node->item)
        deleteNodeItem(node);

    // Else search for the deletion position
    else if (anEntry < node->item)
        deleteItem(node->leftChildPtr, anEntry,success);
    else
        deleteItem(node->rightChildPtr, anEntry,success);
}
bool BinarySearchTree::remove(const int anEntry)
{
    bool success = true;
    deleteItem(root, anEntry,success);
    if(success == true)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


bool BinarySearchTree::isEmpty()
{
    if(root == NULL)
        return 1;
    return 0;
}
void BinarySearchTree::getNumberOfNodesHelper(BinaryNode* node, int& numberOfNode)
{
    if(node != NULL)
    {
        numberOfNode++;
        getNumberOfNodesHelper(node->leftChildPtr, numberOfNode);
        getNumberOfNodesHelper(node->rightChildPtr, numberOfNode);
    }
}
int BinarySearchTree::getNumberOfNodes()
{
    int numberOfNodes = 0;
    getNumberOfNodesHelper(root, numberOfNodes);
    return numberOfNodes;
}
int BinarySearchTree::getHeightHelper(BinaryNode* node)
{
    if(node == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(getHeightHelper(node->leftChildPtr),getHeightHelper(node->rightChildPtr));
    }
}
int BinarySearchTree::getHeight()
{
    int height = getHeightHelper(root);
}
void BinarySearchTree::preorderTraverse()
{
    cout<<"Preorder Traverse: ";
    preorderTraverseHelper(root);
    cout<<endl;
}
void BinarySearchTree::preorder(BinaryNode* node)
{
    if (node != NULL)
    {
        cout<<node->item<<" ";
        preorder(node->leftChildPtr);
        preorder(node->rightChildPtr);
    }
}
void BinarySearchTree::preorderTraverseHelper(BinaryNode* node)
{
    preorder(root);
}
void BinarySearchTree::inorderTraverse()
{
    cout<<"Inorder Traverse: ";
    inorderTraverseHelper(root);
    cout<<endl;
}
void BinarySearchTree::inorder(BinaryNode* node)
{
    if (node != NULL)
    {
        inorder(node->leftChildPtr);
        cout<<node->item<<" ";
        inorder(node->rightChildPtr);
    }

}
void BinarySearchTree::inorderTraverseHelper(BinaryNode* node)
{
    inorder(root);
}
void BinarySearchTree::postorderTraverse()
{
    cout<<"PostOrderTraverse: ";
    postorderTraverseHelper(root);
    cout<<endl;
}
void BinarySearchTree::postorder(BinaryNode* node)
{
    if (node != NULL)
    {
        postorder(node->leftChildPtr);
        postorder(node->rightChildPtr);
        cout<<node->item<<" ";
    }

}
void BinarySearchTree::postorderTraverseHelper(BinaryNode* node)
{
    postorder(root);
}
void BinarySearchTree::containsHelper(BinaryNode* node, int anElement, bool& check)
{

    if(node == NULL)
    {
        check = false;
    }
    else if(anElement < node->item)
    {
        containsHelper(node->leftChildPtr, anElement, check);
    }
    else if(anElement > node->item)
    {
        containsHelper(node->rightChildPtr, anElement, check);
    }
    else
    {
        check = true;
    }
}
bool BinarySearchTree::contains(int anEntry)
{
    bool success = false;
    containsHelper(root, anEntry, success);
    return success;
}
void BinarySearchTree::spanHelper(BinaryNode* node, int& spanCount, const int a, const int b)
{
    if(node != NULL)
    {
        if(node->item>b)
        {
            spanHelper(node->leftChildPtr, spanCount,a,b);
        }
        else if(node->item<a)
        {
            spanHelper(node->rightChildPtr, spanCount,a,b);
        }
        else
        {
            spanCount++;
            if(node->item>=a)
            {
                spanHelper(node->rightChildPtr, spanCount,a,b);
            }
            if(node->item<=b)
            {
                spanHelper(node->leftChildPtr,spanCount,a,b);
            }
        }
    }
}
int BinarySearchTree::span(const int a, const int b)
{
    int spanCount = 0;
    spanHelper(root,spanCount,a,b);
    return spanCount;
}
void BinarySearchTree::inorderMirror(BinaryNode* node)
{
    if (node != NULL)
    {
        inorderMirror(node->leftChildPtr);
        cout<<node->item<<" ";
        inorderMirror(node->rightChildPtr);
    }
}
void BinarySearchTree::mirrorHelper(BinaryNode* node)
{
    if(node)
    {
        BinaryNode* tempChild;
        mirrorHelper(node->leftChildPtr);
        mirrorHelper(node->rightChildPtr);

        tempChild = node->leftChildPtr;
        node->leftChildPtr = node->rightChildPtr;
        node->rightChildPtr = tempChild;
    }
    else
        return;
}
void BinarySearchTree::mirror()
{
    mirrorHelper(root);
    inorderMirror(root);
}
bool BinarySearchTree::printLevel(BinaryNode* node, int level)
{
    if (node == nullptr) {
        return false;
    }

    if (level == 1)
    {
        cout <<node->item<< " ";

        return true;
    }
    bool left = printLevel(node->leftChildPtr, level-1);
    bool right = printLevel(node->rightChildPtr, level-1);

    return left || right;
}
void BinarySearchTree::levelorderHelper(BinaryNode* node, int& lvl){
    while(printLevel(node,lvl)){
        lvl++;
    }
}
void BinarySearchTree::levelorderTraverse()
{
    int level = 1;
    levelorderHelper(root,level);
}
