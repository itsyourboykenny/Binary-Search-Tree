
#ifndef BinaryTree_h
#define BinaryTree_h
#include "BinaryNode.h"
using namespace std;

template<class ItemType>
class BinaryTree
{
protected:
    int count;							// number of nodes in tree
    // copy from the tree rooted at nodePtr and returns a pointer to the copy
    
public:
    BinaryNode<ItemType>* rootPtr;		// ptr to root node

    BinaryNode<ItemType>* returnRootPtr(){return rootPtr;}
    BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* nodePtr);
    
    // "admin" functions
    BinaryTree()					{rootPtr = 0; count = 0;}
    BinaryTree(const BinaryNode<ItemType> & tree) {rootPtr = copyTree(&tree);}// see assignment
    virtual ~BinaryTree()				{clear();}// CALL clear()
    BinaryTree & operator=(const BinaryTree & sourceTree);
    bool operator == (const BinaryTree &sourceTree);
    string writeToString(ItemType &target);
        
    // common functions for all binary trees
    bool isEmpty() const				{return count == 0;}
    int size() const					{return count;}
    
    void clear(){
        cout<<"\nClearing old tree\n\n";
        destroyTree(rootPtr);
        rootPtr=0;
        count=0;
    }
    
    void preOrder(void visit(ItemType &)) const		{_preorder(visit, rootPtr);}
    void inOrder(void visit(ItemType &)) const      {_inorder(visit, rootPtr);}
    void postOrder(void visit(ItemType &)) const	{_postorder(visit, rootPtr);}
    
    // abstract functions to be implemented by derived class
    virtual bool insert(const ItemType & newData) = 0;
    virtual bool remove(const ItemType & data) = 0;
    virtual bool getEntry(const ItemType & anEntry, ItemType & returnedItem) const = 0;
    
private:
    
//    int isEqual(BinaryNode<ItemType> &, BinaryNode<ItemType> &);
    bool isEqual(BinaryNode<ItemType> &, BinaryNode<ItemType> &);
    
    // delete all nodes from the tree
    void destroyTree(BinaryNode<ItemType>* nodePtr);
    
    // internal traverse
    void _preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
    void _inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
    void _postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
    
};

#endif