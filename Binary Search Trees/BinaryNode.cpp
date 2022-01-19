#include "BinaryNode.h"

BinaryNode::BinaryNode(){

}
BinaryNode::BinaryNode(const int a, BinaryNode*left, BinaryNode*right){
    item = a;
    leftChildPtr = left;
    rightChildPtr = right;

}
int BinaryNode::getItem(){
    return item;
}
void BinaryNode::setItem(const int a){
    item = a;
}

BinaryNode* BinaryNode::getChildLeft(){
    return leftChildPtr;
}
void BinaryNode::setChildLeft(BinaryNode* nodeLeft){
    leftChildPtr = nodeLeft;
}
BinaryNode* BinaryNode::getChildRight(){
    return rightChildPtr;
}
void BinaryNode::setChildRight(BinaryNode* nodeRight){
    rightChildPtr = nodeRight;
}
