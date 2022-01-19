#ifndef BINARYNODE_H
#define BINARYNODE_H
class BinaryNode { 	// a node in the tree
public:
    BinaryNode();
	friend class BinarySearchTree;

   	BinaryNode(const int a, BinaryNode*left,BinaryNode*right);
   	int getItem();
   	void setItem(const int a);

   	BinaryNode* getChildLeft();
   	void setChildLeft(BinaryNode* nodeLeft);

   	BinaryNode* getChildRight();
   	void setChildRight(BinaryNode* nodeRight);

private:
    int item; 		// a data item in the tree
    BinaryNode *leftChildPtr;	// pointers to children
    BinaryNode *rightChildPtr;

};
#endif // end of BINARYNODE_H
