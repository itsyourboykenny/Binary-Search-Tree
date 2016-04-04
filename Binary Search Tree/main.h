//
//  main.h
//  Binary Search Tree
//
//  Created by itsyourboykenny on 11/5/15.
//  Copyright © 2015 Ken Ishiguro. All rights reserved.
//

#ifndef main_h
#define main_h

typedef Card* PTR_CARD;

void drawCard(int &a, int &b){
    a = rand()%13+1;
    b = rand()%4;
}

// YOU WRITE THIS ONE (DESCRIBED ON THE ASSIGNMENT):
template<class ItemType>
void testDelete(BinarySearchTree<ItemType> *ptree1, BinarySearchTree<ItemType> *ptree2){
    ItemType first1, first2, last1, last2;
    ptree1->getFirst(first1);
    (ptree1->remove(first1))?cout<<"Tree1: First Success"<<endl:cout<<"Tree1: First Failed"<<endl;
    ptree2->getFirst(first2);
    (ptree2->remove(first2))?cout<<"Tree2: First Success"<<endl:cout<<"Tree2: First Failed"<<endl;
    ptree1->getLast(last1);
    (ptree1->remove(last1))?cout<<"Tree 1: Last Success"<<endl:cout<<"Tree1: Last Failed"<<endl;
    ptree2->getLast(last2);
    (ptree2->remove(last2))?cout<<"Tree 2: Last Success"<<endl:cout<<"Tree2: Last Failed"<<endl;
}

int comparePips(const PTR_CARD &left, const PTR_CARD &right){
 
    int diff = left->getPips() - right->getPips();
    int suitDiff = left->getSuitNum() - right->getSuitNum();
    
    if (diff == 0) {
        if (suitDiff < 0) {
            return -1;
        }
        else if (suitDiff > 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(diff < 0){
        return -1;
    }
    else{
        return 1;
    }
}

int compareSuits(const PTR_CARD &left, const PTR_CARD &right){
    int diff = left->getSuitNum() - right->getSuitNum();
    int pipDiff = left->getPips() - right->getPips();
    
    if (diff == 0) {
        if (pipDiff < 0) {
            return -1;
        }
        else if (pipDiff > 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if (diff < 0){
        return -1;
    }
    else{
        return 1;
    }
}

template<class ItemType>
void displayPTR_CARD(ItemType &ptrCard){
    cout << (*ptrCard);
}

template<class ItemType>
void displaySuitPTR_CARD(ItemType &ptrCard){
    cout << *ptrCard->getSuitName() << " of " << *ptrCard->getPipsName() << endl;
}

template<class ItemType>
void testBST(BinarySearchTree<ItemType> *ptree)
{
    int tempPips, tempSuitNum;
    ItemType searchItem;
    ItemType pfoundItem = new Card();
    string prompt("\n\nEnter a Card (1-13  0-4) that should be in the tree: ");
    
    for (int i = 0; i < 2; ++i)
    {
        cout << prompt;
        cin >> tempPips >> tempSuitNum;
        searchItem = new Card(tempPips, tempSuitNum);
        if (ptree->getEntry(searchItem, pfoundItem))
        {
            cout << "Found : " << *pfoundItem << endl;
        }
        else
            cout << *searchItem << " not found\n";
        
        delete searchItem;
        prompt = "\nEnter a Card (1-13  0-4) that should NOT be in the tree: ";
    } // end for
    
} // end testBST

void testCopyAndAssign(BinarySearchTree<PTR_CARD> *ptree1, BinarySearchTree<PTR_CARD> *ptree2){
    
    BinarySearchTree<PTR_CARD> *localPtrTree;
    
    localPtrTree = new BinarySearchTree<PTR_CARD>(*ptree1);
    cout << "\n\nThe local tree from copy constructor copying Pips-ordered tree\n";
    localPtrTree->inOrder(displayPTR_CARD);
    delete localPtrTree;
    
    cout << "\nChecking if Original Pips-ordered Tree was not changed: \n";
    ptree1->inOrder(displayPTR_CARD);
    
    { // BRACKETS ARE HERE TO CHECK WHEN IT GOES OUT OF SCOPE
        BinarySearchTree<PTR_CARD> localTree(compareSuits);
        localTree = *ptree2; // tests operator=
        cout << "\nThe local tree from operator= copying Suit-ordered tree\n";
        localTree.inOrder(displayPTR_CARD);
    }
    cout << "\nChecking if Original Suit-ordered Tree was not changed: \n";
    ptree2->inOrder(displayPTR_CARD);
    
}





#endif /* main_h */
