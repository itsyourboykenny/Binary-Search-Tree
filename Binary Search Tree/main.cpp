//Kenichi Ishiguro
//Binary Search Tree Program

#include <iostream>
#include "BinarySearchTree.cpp"
#include "Card.h"
#include "main.h"

/*
 Write main so it has 2 POINTER to BinarySearchTree<PTR_CARD> variables.
 Assign to one of the pointer variables a new BinarySearchTree with the
 comparePips passed as an argument.  Assign to the 2nd pointer variable a new
 BinarySearchTree with compareSuits as an argument. Then do the following
 (for which most should be a function or points may be deducted if main is
 too long): (MUST BE IN THIS ORDER)
 */

/*
 call a function (that you write) to call srand(time(0)), then fill both BinarySearchTrees in a loop for 25 times (don't worry about duplicates):
 o get a random int from 1 to 13, inclusive (assign to a local int for the pips)
 o get a random int from 0 to 3, inclusive, assign to another local int for the suit number
 o DYNAMICALLY ALLOCATE a Card (passing the local random ints)
 o insert the same Card to each BinarySearchTree (through its pointer),
 one at a time
 - call each tree's inOrder function (one at a time), passing
 displayPTR_CARD for the pips‐ordered BST and displaySuitPTR_CARD for the
 suit‐ordered BST
 - call the standalone testBST function (given in the code file) for EACH
 tree (one at a time)
 - call a function that you write that tests deleting from BOTH
 BinarySearchTrees (reference or pointer parameters) in ONE function so it
 does the following:
 o Do the following for each tree:
 - get the first and last Card from the tree
 - try to remove the first, then the last, check if successful and
 display a message indicating if removed
 - call the standalone testCopyAndAssign function (given in the code file)
 - call postOrder for ONE OF THE sorted BinarySearchTree passing
 deletePTR_CARD (function), then delete EACH tree (one at a time)
 See test runs on Catalyst. DO NOT USE ANY EXTERNAL VARIABLES (variables
 declared outside of main or outside of any function)!!  (External const
 declarations are OK.)
 
 */

int main() {
    PTR_CARD deck1=new Card, deck2 = new Card;
    BinarySearchTree<PTR_CARD> *Cards1, *Cards2, *Cards3, *Cards4;
        
    int pips, suites;
    Cards1 = new BinarySearchTree<PTR_CARD>(comparePips);
    Cards2 = new BinarySearchTree<PTR_CARD>(compareSuits);
    Cards3 = new BinarySearchTree<PTR_CARD>(comparePips);
    
    srand (time(0));
    
    for (int count = 0; count < 25; count++) {
        drawCard(pips,suites);
        deck1 = new Card(pips,suites);
        Cards1->insert(deck1);
        deck1 = new Card(pips,suites);
        Cards3->insert(deck1);
        
        drawCard(pips, suites);
        deck2 = new Card(pips, suites);
        Cards2->insert(deck2);
    }
    
    cout << (Cards1==Cards3) << endl;
    cout << (Cards1==Cards2) << endl;
        
    Cards1->inOrder(displayPTR_CARD);
    cout << endl;
    Cards2->inOrder(displaySuitPTR_CARD);
    
    testBST(Cards1);
    
    testBST(Cards2);
        
    testDelete(Cards1, Cards2);
    
    testCopyAndAssign(Cards1, Cards2);
    
    return 0;
}

/*
 2 of Hearts
 2 of Hearts
 2 of Hearts
 2 of Spades
 3 of Spades
 3 of Spades
 4 of Clubs
 4 of Hearts
 5 of Hearts
 5 of Spades
 6 of Clubs
 6 of Clubs
 6 of Clubs
 6 of Diamonds
 6 of Hearts
 7 of Spades
 9 of Spades
 10 of Hearts
 10 of Hearts
 Queen of Clubs
 Queen of Diamonds
 Queen of Spades
 King of Clubs
 King of Diamonds
 King of Hearts
 
 Clubs of Ace
 Clubs of 4
 Clubs of 6
 Clubs of 10
 Clubs of Jack
 Clubs of Jack
 Clubs of King
 Diamonds of 4
 Diamonds of 6
 Diamonds of 9
 Diamonds of 9
 Diamonds of 10
 Diamonds of Jack
 Diamonds of Queen
 Hearts of 3
 Hearts of 4
 Hearts of 5
 Hearts of 7
 Hearts of 9
 Hearts of 10
 Hearts of Jack
 Hearts of Queen
 Hearts of King
 Spades of 6
 Spades of 8
 
 
 Enter a Card (1-13  0-4) that should be in the tree: 2
 2
 Found : 2 of Hearts
 
 
 Enter a Card (1-13  0-4) that should NOT be in the tree: 13 3
 King of Spades
 not found
 
 
 Enter a Card (1-13  0-4) that should be in the tree: 8 3
 Found : 8 of Spades
 
 
 Enter a Card (1-13  0-4) that should NOT be in the tree: 13 3
 King of Spades
 not found
 
 Tree1: First Success
 Tree2: First Success
 Tree 1: Last Success
 Tree 2: Last Success
 
 
 The local tree from copy constructor copying Pips-ordered tree
 2 of Hearts
 2 of Hearts
 2 of Spades
 3 of Spades
 3 of Spades
 4 of Clubs
 4 of Hearts
 5 of Hearts
 5 of Spades
 6 of Clubs
 6 of Clubs
 6 of Clubs
 6 of Diamonds
 6 of Hearts
 7 of Spades
 9 of Spades
 10 of Hearts
 10 of Hearts
 Queen of Clubs
 Queen of Diamonds
 Queen of Spades
 King of Clubs
 King of Diamonds
 
 Checking if Original Pips-ordered Tree was not changed:
 2 of Hearts
 2 of Hearts
 2 of Spades
 3 of Spades
 3 of Spades
 4 of Clubs
 4 of Hearts
 5 of Hearts
 5 of Spades
 6 of Clubs
 6 of Clubs
 6 of Clubs
 6 of Diamonds
 6 of Hearts
 7 of Spades
 9 of Spades
 10 of Hearts
 10 of Hearts
 Queen of Clubs
 Queen of Diamonds
 Queen of Spades
 King of Clubs
 King of Diamonds
 
 The local tree from operator= copying Suit-ordered tree
 4 of Clubs
 6 of Clubs
 10 of Clubs
 Jack of Clubs
 Jack of Clubs
 King of Clubs
 4 of Diamonds
 6 of Diamonds
 9 of Diamonds
 9 of Diamonds
 10 of Diamonds
 Jack of Diamonds
 Queen of Diamonds
 3 of Hearts
 4 of Hearts
 5 of Hearts
 7 of Hearts
 9 of Hearts
 10 of Hearts
 Jack of Hearts
 Queen of Hearts
 King of Hearts
 6 of Spades
 
 Checking if Original Suit-ordered Tree was not changed:
 4 of Clubs
 6 of Clubs
 10 of Clubs
 Jack of Clubs
 Jack of Clubs
 King of Clubs
 4 of Diamonds
 6 of Diamonds
 9 of Diamonds
 9 of Diamonds
 10 of Diamonds
 Jack of Diamonds
 Queen of Diamonds
 3 of Hearts
 4 of Hearts
 5 of Hearts
 7 of Hearts
 9 of Hearts
 10 of Hearts
 Jack of Hearts
 Queen of Hearts
 King of Hearts
 6 of Spades
 Program ended with exit code: 0
 */
