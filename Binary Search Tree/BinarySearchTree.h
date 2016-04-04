//
//  BinarySearchTree.h
//  Binary Search Tree
//
//  Created by Ken Ishiguro on 11/2/15.
//  Copyright © 2015 Ken Ishiguro. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#include "BinaryTree.cpp"

template<class ItemType>
class BinarySearchTree// : public BinaryTree<ItemType>
{
private:
    
    //*********** ADD A POINTER TO FUNCTION AS DESCRIBED ON THE ASSIGNMENT********
    
    // internal insert node: insert newNode in nodePtr subtree
    BinaryNode<ItemType>* _insert(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* newNode);
    
    // internal remove node: locate and delete target node under nodePtr subtree
    BinaryNode<ItemType>* _remove(BinaryNode<ItemType>* nodePtr, const ItemType target, bool & success);
    
    // delete target node from tree, called by internal remove node
    BinaryNode<ItemType>* deleteNode(BinaryNode<ItemType>* targetNodePtr);
    
    // remove the leftmost node in the left subtree of nodePtr
    BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType & successor);
    
    // search for target node
    BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType & target) const;
    
    // Pointer to function variable
    int (*compare)(const ItemType &, const ItemType &);
    
    void _inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
    
    bool &operator == (ItemType &target){ return ((this->getPips()== target.getPips()) && (this->getSuitNum() == target.getSuitNum()));}
    
    BinaryNode<ItemType> *copyTree(const BinaryNode<ItemType>* nodePtr);
    
    bool isEqual(BinaryNode<ItemType> &, BinaryNode<ItemType> &);
    
public:
    
    BinaryNode<ItemType>* rootPtr;

    //*********** ADD A CONSTRUCTOR AS DESCRIBED ON THE ASSIGNMENT********
    BinarySearchTree(int (*compareFunc)(const ItemType &, const ItemType &)) {compare = compareFunc;}
    
    //*********** ADD A COPY CONSTRUCTOR AS DESCRIBED ON THE ASSIGNMENT********
    BinarySearchTree(int (*sourcePtr)(const ItemType, const ItemType), BinarySearchTree<ItemType> &source);
    
    // insert a node at the correct location
    bool insert(const ItemType & newEntry);
    // remove a node if found
    bool remove(const ItemType & anEntry);
    // find a target node
    bool getEntry(const ItemType & target, ItemType & returnedItem) const;
    // NOT IN THE Tree Code Files on Catalyst, use for HW#4:
    BinarySearchTree & operator=(const BinarySearchTree & sourceTree);
    
    // YOU WRITE: gets the "smallest" Item
    void getFirst(ItemType &firstItem);
    // YOU WRITE: returns the "largest" Item
    void getLast(ItemType &lastItem);
    
    void inOrder(void visit(ItemType &)) const   {_inorder(visit, rootPtr);}
    
    bool operator == (const BinaryTree<ItemType> &sourceTree);
    
};
#endif /* BinarySearchTree_h */
