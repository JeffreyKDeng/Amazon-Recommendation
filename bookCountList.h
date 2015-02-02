// Jeffrey Deng (jkdeng) & Kevin Andres (kandres)
// Constructors
/*** Constructors-Destructors ***/
//#ifndef __bookCountList_H__
#define __bookCountList_H__

#include <stdbool.h>



typedef struct List *ListRef;
ListRef newList(void);

/*** Access functions ***/
bool isEmpty(ListRef L); // returns true is list is empty else returns false.
bool offEnd(ListRef L); // returns true is current == NULL
bool atFirst(ListRef L); // returns true if current == first and !offEnd()
bool atLast(ListRef L); // returns true if current == last and !offEnd()
long getSecond(ListRef L);
long getNext(ListRef L);
long getFirst(ListRef L); // return the first element; pre: !isEmpty()
long getLast(ListRef L); // return the last element; pre: !isEmpty()
long getCurrent(ListRef L); // return the current element pre: !offEnd()
int getLength(ListRef L); // return the length of the list
bool equals (ListRef A, ListRef B); // return true iff the two lists have the same keys
                                    // in the same order

/*** Manipulation procedures ***/
void makeEmpty(ListRef L); // make the list empty. Post: isEmpty()
void moveFirst(ListRef L); // set current marker to the first element in the list
                            // Pre: !isEmpty(); Post: !offEnd()
void moveLast(ListRef L); // set current marker to the last element in the list
                            // Pre: !isEmpty(); Post: !offEnd()
void movePrev(ListRef L); // set current marker one step backward.
                        // Pre: !offEnd(); Post: offEnd() only if atFirst() was true
void moveNext(ListRef L); // set current marker one step forward.
                        // Pre: !offEnd(); Post: offEnd() only if atLast() was true
void insertBeforeFirst(ListRef L, long data); // Inserts new element before first
                            // Post: !isEmpty()
void insertAfterLast(ListRef L, long data); // Inserts new element after last one
                                            // Post: !isEmpty()
void insertBeforeCurrent(ListRef L, long data); // Inserts new element before current one
                                            // Pre: !offEnd(); Post: !isEmpty(), !offEnd()
void insertAfterCurrent(ListRef L, long data); // Inserts new element after current one
                                                // Pre: !offEnd(); Post: !isEmpty(), !offEnd()
void increaseCount(ListRef L); // increase count of priority for copurchase list
void add(ListRef L, long bookID); // adds book ID onto the list
void deleteFirst(ListRef L); // delete the first element. Pre: !isEmpty()
void deleteLast(ListRef L); // delete the last element. Pre: !isEmpty()
void deleteCurrent(ListRef L); // delete the current element.
                                    // Pre: !isEmpty(), !offEnd(); Post: offEnd()
int getCount(ListRef L); // returns priority copurchase count
int getPrevCount(ListRef L); // returns priority of other copurchase count so they can be compared
void swap(ListRef L); // swaps two nodes on a list
bool inList(ListRef L, long bookID);
long getNewRecID(ListRef X, ListRef L);
/*** Other operations ***/
void printList(ListRef L);
ListRef copyList(ListRef L);
