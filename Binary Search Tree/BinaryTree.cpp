
#include <iostream>
#include "BinaryTree.h"

template<class ItemType>
string BinaryTree<ItemType>::writeToString(ItemType &target){
    
    string stuff("");
    stuff.append(target->getPipsName());
    stuff.append(" of ");
    stuff.append(target->getSuitName()+endl);
    
}

//template<class ItemType>
//int BinaryTree<ItemType>::isEqual(BinaryNode<ItemType> &source, BinaryNode<ItemType> &target){
//
//    int diff = 0;
//    
//    if (source->isLeaf() && target->isLeaf()) {
//        if (source->getItem() == target->getItem()) {
//            return 0;
//        }
//        else{
//            return 1;
//        }
//    }else if (source->isLeaf()){
//        diff += isEqual(source, target->getLeftPtr());
//        if (source->getItem() != target->getItem()) {
//            ++diff;
//        }
//        diff += isEqual(source, target->getRightPtr());
//        if (source->getItem() != target->getItem()) {
//            ++diff;
//        }
//        return diff;
//    }
//    else if (target->isLeaf()){
//        diff += isEqual(source->getLeftPtr(), target);
//        if (source->getItem() != target->getItem()) {
//            ++diff;
//        }
//        diff += isEqual(source->getRightPtr(), target);
//        if (source->getItem() != target->getItem()) {
//            ++diff;
//        }
//        return diff;
//    }
//    else{
//        diff += isEqual(source->getLeftPtr(), target->getLeftPtr());
//        if (source->getItem() == target->getItem()) {
//            return diff;
//        }
//        else{
//            return ++diff;
//        }
//    }
//    
//    
//    
//}

template<class ItemType>
bool BinaryTree<ItemType>::isEqual(BinaryNode<ItemType> &source, BinaryNode<ItemType> &target){
    
    if (source->isLeaf() && target->isLeaf()) {
        if (source->getItem() == target->getItem()) {
            return true;
        }
        else{
            return false;
        }
    }else if (source->isLeaf()){
        if (isEqual(source, target->getLeftPtr()) && isEqual(source, target->getRightPtr)) {
            return true;
        }
        else{
            return false;
        }
    }
    else if (target->isLeaf()){
        if (isEqual(source->getLeftPtr(), target) && isEqual(source->getRightPtr(), target)) {
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if (isEqual(source->getLeftPtr(), target->getLeftPtr()) && isEqual(source->getRightPtr, target->getRightPtr())) {
            return true;
        }
        else{
            return false;
        }
    }
    
    
    
}

template<class ItemType>
bool BinaryTree<ItemType>::operator == (const BinaryTree &sourceTree){
    
    return (isEqual(this->getRootPtr(), sourceTree->getRootPtr()) == 0);
}

template<class ItemType>
BinaryNode<ItemType>* BinaryTree<ItemType>::copyTree(const BinaryNode<ItemType>* nodePtr)
{
    BinaryNode<ItemType> *newNodePtr = 0;
    // FILL IN SEVERAL LINES HERE USING THE ALGORITHM:
    //    If nodePtr doesn't exist (is 0) Then return 0
    //
    //	Assign a new BinaryNode to newNodePtr
    //	Set the newNodePtr's data (item) to the nodePtr's item
    //	Set the newNodePtr's leftPtr to
    //		a recursive call to copyTree for the nodePtr's leftPtr
    //     Set the newNodePtr's rightPtr to
    //		a recursive call to copyTree for the nodePtr's rightPtr
    //	INCREMENT count
    
    if (nodePtr == 0){
        return 0;
    }
    
    if (!nodePtr->isLeaf()) {
        newNodePtr = new BinaryNode<ItemType> (nodePtr->getItem(), copyTree(nodePtr->getLeftPtr()),copyTree(nodePtr->getRightPtr()));
    }
    else{
        newNodePtr = new BinaryNode<ItemType> (nodePtr->getItem());
    }
    
    count++;
    
    return newNodePtr;
}


template<class ItemType>
void BinaryTree<ItemType>::destroyTree(BinaryNode<ItemType>* nodePtr)
{
    //FILL IN SEVERAL LINES HERE, USING THE ALGORITHM:
    //    if nodePtr doesn't exist (is 0), return
    //    destroy the left subtree (recursive call to destroyTree)
    //    destroy the right subtree (recursive call to destroyTree)
    //    delete nodePtr
    
    if (nodePtr == 0) {
        return;
    }
    
    if (nodePtr->getLeftPtr()!=0) {
        destroyTree(nodePtr);
        delete nodePtr->getLeftPtr();
    }
    
    if (nodePtr->getRightPtr()!=0) {
        destroyTree(nodePtr);
        delete nodePtr->getRightPtr();
    }
    
    if (nodePtr->isLeaf()) {
        delete nodePtr;
    }
    else{
        if (nodePtr->getLeftPtr() != 0) {
            cout << "Error deleting Left nodes" << endl;
        }
        else if (nodePtr->getRightPtr() != 0){
            cout << "Error deleting Right nodes" << endl;
        }
        else{
            cout << "Just go home..." << endl;
        }
    }
    
}

template<class ItemType>
void BinaryTree<ItemType>::_preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr != 0)
    {
        ItemType item = nodePtr->getItem();
        visit(item);
        _preorder(visit, nodePtr->getLeftPtr());
        _preorder(visit, nodePtr->getRightPtr());
    }
}

//*****************************COMPLETE THIS******************************
template<class ItemType>
void BinaryTree<ItemType>::_inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    // see _preorder for similar code
    if (nodePtr == nullptr) {
        return;
    }
    else if(!nodePtr->isLeaf()) {
        ItemType item = nodePtr->getItem();
        _inorder(visit, nodePtr->getLeftPtr());
        visit(item);
        _inorder(visit, nodePtr->getRightPtr());
    }
    else{
        ItemType item = nodePtr->getItem();
        visit(item);
        return;
    }
}

//*****************************COMPLETE THIS******************************
template<class ItemType>
void BinaryTree<ItemType>::_postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    // see _preorder for similar code
}

template<class ItemType>
BinaryTree<ItemType> & BinaryTree<ItemType>::operator=(const BinaryTree<ItemType> & sourceTree)
{
    // CALL copyTree and return *this
    if(rootPtr != 0) // already filled tree?
        clear(); // clear old tree
    rootPtr = copyTree(sourceTree.rootPtr);
    return *this;
}
