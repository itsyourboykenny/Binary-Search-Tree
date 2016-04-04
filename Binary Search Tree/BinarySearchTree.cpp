//
//  BinarySearchTree.cpp
//  Binary Search Tree
//
//  Created by Ken Ishiguro on 11/5/15.
//  Copyright © 2015 Ken Ishiguro. All rights reserved.
//

#include <iostream>
#include "BinarySearchTree.h"

template<class ItemType>
bool BinarySearchTree<ItemType>::operator == (const BinaryTree<ItemType> &sourceTree){
    return isEqual(this->getRootPtr(), sourceTree->getRootPtr());
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEqual(BinaryNode<ItemType> &source, BinaryNode<ItemType> &target){
    
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
BinaryNode<ItemType>* BinarySearchTree<ItemType>::copyTree(const BinaryNode<ItemType>* nodePtr)
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
        
    return newNodePtr;
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(int (*sourcePtr)(const ItemType, const ItemType), BinarySearchTree<ItemType> &source){
    compare = sourcePtr;
    rootPtr = copyTree(source);
}


///////////////////////// public function definitions ///////////////////////////

template<class ItemType>
bool BinarySearchTree<ItemType>::insert(const ItemType & newEntry)
{
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
    rootPtr = _insert(rootPtr, newNodePtr);
    return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType & target)
{
    bool isSuccessful = false;
    rootPtr = _remove(rootPtr, target, isSuccessful);
    return isSuccessful;
}

//*****************************COMPLETE THIS******************************
template<class ItemType>
bool BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry, ItemType & returnedItem) const
{
    // MUST INCLUDE CALLING THE PRIVATE findNode FUNCTION
    // Be sure to check if the findNode function actually finds anEntry
    // If it does, assign to the returnedItem parameter the item of the
    //     found node and return true
    // If it doesn't, return false
    BinaryNode<ItemType> *temp = findNode(rootPtr, anEntry);
    
    if (temp == 0) {
        return false;
    }
    else{
        if (*temp->getItem() == *anEntry){
            returnedItem = temp->getItem();
            return true;
        }
        else{
            return false;
        }
    }
    
    
}

//NOT IN THE Tree Code Files on Catalyst, use for HW#4:
template<class ItemType>
BinarySearchTree<ItemType> & BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType> & sourceTree)
{
    compare = sourceTree.compare;
    rootPtr = copyTree(sourceTree.rootPtr);
    return *this;
}

template<class ItemType>
void BinarySearchTree<ItemType>::getFirst(ItemType &firstItem)
{
    // NON-recursive algorithm:
    // If the tree is empty, just return
    // FIND THE LEFT-MOST LEFT CHILD
    // WHEN you can't go left anymore, assign the node's data to firstItem
    
    if (rootPtr->getItem()==0 || rootPtr==0) {
        return;
    }
    else{
        BinaryNode<ItemType> *temp = rootPtr;
        
        while (temp->getLeftPtr()!=nullptr) {
            temp = temp->getLeftPtr();
        }
        
        firstItem = temp->getItem();
        delete temp;
    }
    
}

template<class ItemType>
void BinarySearchTree<ItemType>::getLast(ItemType &lastItem)
{
    // If the tree is empty, just return
    // FIND THE LEFT-MOST LEFT CHILD
    // WHEN you can't go left anymore, assign the node's data to firstItem
    
    BinaryNode<ItemType> *temp = rootPtr;
    if (rootPtr == 0 || rootPtr->getItem() == 0) {
        return;
    }
    else{
        BinaryNode<ItemType> *temp = rootPtr;
        while (temp->getRightPtr()!=nullptr) {
            temp = temp->getRightPtr();
        }
        lastItem = temp->getItem();
        delete temp;
    }
    
}
//////////////////////////// private functions //////////////////////////////////

// Done as class exercise:
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_insert(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* newNodePtr)
{
    if( nodePtr==0 )
        return newNodePtr;
    if( (*compare)(newNodePtr->getItem(), nodePtr->getItem()) == -1 ) //*****CHANGE THIS*****
        nodePtr->setLeftPtr(_insert( nodePtr->getLeftPtr(), newNodePtr ));
    else
        nodePtr->setRightPtr(_insert( nodePtr->getRightPtr(), newNodePtr ));
    
    return nodePtr; // must return
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_remove(BinaryNode<ItemType>* nodePtr, const ItemType target, bool & success)
{
    if (nodePtr == nullptr)
    {
        success = false;
        return 0;
    }
    if ((*compare)(target, nodePtr->getItem()) == -1) //*****CHANGE THIS*****
        nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), target, success));
    else if ((*compare)(target, nodePtr->getItem()) == 1) //*****CHANGE THIS*****
        nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), target, success));
    else	// found the node
    {
        nodePtr = deleteNode(nodePtr);
        success = true;
    }
    return nodePtr;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::deleteNode(BinaryNode<ItemType>* nodePtr)
{
    if (nodePtr->isLeaf())
    {
//        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;
    }
    else if (nodePtr->getLeftPtr() == 0)
    {
        BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightPtr();
//        delete nodePtr;
        nodePtr = nullptr;
        return nodeToConnectPtr;
    }
    else if (nodePtr->getRightPtr() == 0)
    {
        BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftPtr();
//        delete nodePtr;
        nodePtr = nullptr;
        return nodeToConnectPtr;
    }
    else
    {
        ItemType newNodeValue;
        nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
        nodePtr->setItem(newNodeValue);
        return nodePtr;
    }
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr,
                                                                     ItemType & successor)
{
    if (nodePtr->getLeftPtr() == 0)
    {
        successor = nodePtr->getItem();
        return deleteNode(nodePtr);
    }
    else
    {
        nodePtr->setLeftPtr(removeLeftmostNode(nodePtr->getLeftPtr(), successor));
        return nodePtr;
    }
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* nodePtr, const ItemType & target) const
{
    // ALGORITHM:
    //       IF nodePtr doesn't exist (is 0) THEN
    //            return 0
    //       ELSE IF nodePtr's item > target THEN (make sure you use the compare function)
    //                return what the recursive call to findNode, for the leftPtr, returns
    //       ELSE IF nodePtr's item < target THEN (make sure you use the compare function)
    //            return what the recursive call to findNode, for the rightPtr, returns
    //	ELSE
    
    if (nodePtr == 0) {
        return nullptr;
    }
    else if ((*compare)(target, nodePtr->getItem()) == -1){
        return findNode(nodePtr->getLeftPtr(), target);
    }
    else if ((*compare)(target, nodePtr->getItem()) == 1){
        return findNode(nodePtr->getRightPtr(), target);
    }
    else{
        return nodePtr;
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::_inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
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
