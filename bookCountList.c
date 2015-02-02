// Jeffrey Deng (jkdeng) & Kevin Andres (kandres)
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bookCountList.h"
typedef struct Node {
    long data;
    int count;
    struct Node* next;
    struct Node* prev;
} NodeType;
typedef struct List {
    NodeType* first;
    NodeType* last;
    NodeType* current;
} ListType;
// Constructors
/*** Constructors-Destructors ***/
ListRef newList(void){
    ListRef list = malloc(sizeof(struct List));
    assert (list != NULL);
    list->first = NULL;
    list->current = NULL;
    list->last = NULL;
    return list;
}
void freeList(ListRef *L){ //free the memory of the program
    free(L);
}
/*** Access functions ***/
bool isEmpty(ListRef L){// returns true is list is empty else returns false.
    if(L->first == NULL){
    return true;
    }
    else{
        return false;
        
    }
 
}
bool offEnd(ListRef L){ // returns true is current == NULL
    if(L->current == NULL){
        return true;
    }
    else{
        return false;
    }
    }
bool atFirst(ListRef L){ // returns true if current == first and !offEnd()
    if(L->current == L->first && !offEnd(L)){
        return true;
    }
    return false;
}
bool atLast(ListRef L){ // returns true if current == last and !offEnd()
    if(L->current == L->last && !offEnd(L)){
        return true;
    }
    return false;
}
long getFirst(ListRef L){ // return the first element; pre: !isEmpty()
    assert(!isEmpty(L));
        return L->first->data;
    

    }

// return the second element of the list
long getSecond(ListRef L){
    return L->first->next->data;
}
long getNext(ListRef L){
     int x = L->current->next->data;
     moveNext(L);
     return x;
}

long getLast(ListRef L){ // return the last element; pre: !isEmpty()
    assert(!isEmpty(L));
        return L->last->data;
    
}
long getCurrent(ListRef L){ // return the current element pre: !offEnd()
    assert(!offEnd(L));
        return L->current->data;
}
int getLength(ListRef L){ // return the length of the list
    int count = 0 ;
    NodeType *i = L->first;
    while(i != NULL){
        count ++;
        i=i->next;
    }
    return count;
}
bool equals (ListRef A, ListRef B){ // return true iff the two lists have the same keys
    // in the same order
    int x = getLength(A);
    int y = getLength(B);
    NodeType *a = A->first;
    NodeType *b = B->first;
    
    if(x == y){ //first compare if the two list have the same length
        while(a->data==b->data){ // next compare each key and see if they are the same value
            a= a->next;
            b= b->next;
            if(a == NULL && b == NULL){ // if both list reach the end of the list, return true.
                return true;
            }
        }
        return false; // if anything was different, return falst
    }
    return false;
}
/*** Manipulation procedures ***/
void makeEmpty(ListRef L){ // make the list empty. Post: isEmpty()
    L->first = NULL;
}
void moveFirst(ListRef L){ // set current marker to the first element in the list // Pre: !isEmpty(); Post: !offEnd()
    if(!isEmpty(L)){
        L->current = L->first;
    }
}
void moveLast(ListRef L){ // set current marker to the last element in the list
    // Pre: !isEmpty(); Post: !offEnd()
    if(!isEmpty(L)){
        L->current = L->last;
    }
}
void movePrev(ListRef L){ // set current marker one step backward.
    // Pre: !offEnd(); Post: offEnd() only if atFirst() was true
    if(!offEnd(L)){
        NodeType *temp = malloc(sizeof(struct Node));
        temp = L->current;
        temp = temp->prev;
        L->current = temp;
    }
}
void moveNext(ListRef L){ // set current marker one step forward.
    // Pre: !offEnd(); Post: offEnd() only if atLast() was true
    if(!offEnd(L)){
        NodeType *temp = malloc(sizeof(struct Node));
        temp = L->current;
        temp = temp->next;
        L->current = temp;
    }
}
void insertBeforeFirst(ListRef L, long data){ // Inserts new element before first
    // Post: !isEmpty()
    if(isEmpty(L)){ // if the list is empty, just put the value as the first, last and the current one
        NodeType *temp = malloc(sizeof(struct Node));
        temp->data = data;
        L->first = temp;
        L->last = L->first;
        L->current = L->first;
    }
    else if(!isEmpty(L)){ // if the list is not empty, just set the new value to first and the original's prev connect to the new value
        NodeType *temp = malloc(sizeof(struct Node));
        NodeType *fst = malloc(sizeof(struct Node));
        temp->data = data;
        fst = L->first;
        fst->prev = temp;
        temp->prev = NULL;
        temp->next = L->first;
        L->first = temp;
        L->current = temp;
    }
}
void insertAfterLast(ListRef L, long data){ // Inserts new element after last one
    // Post: !isEmpty()
    if(isEmpty(L)){ // if the list is empty, just set the data as the first, last and current.
        NodeType *temp = malloc(sizeof(struct Node));
        temp->data = data;
        L->first = temp;
        L->last = temp;
        L->current = L->last;
        temp->prev = NULL;
        temp->next = NULL;
    }
    else if(!isEmpty(L)){ // if the list is not empty, set the value to the last one and connect all the list together
        NodeType *temp = malloc(sizeof(struct Node));
        NodeType *lst = malloc(sizeof(struct Node));
        temp->data = data;
        lst= L->last;
        lst->next = temp;
        temp->prev = L->last;
        temp->next = NULL;
        L->last = temp;
        L->current = temp;
    }
}
void insertBeforeCurrent(ListRef L, long data){ // Inserts new element before current one
    // Pre: !offEnd(); Post: !isEmpty(), !offEnd()
    if(!offEnd(L)){ // first check if current is pointing to NULL
        NodeType *temp = malloc(sizeof(struct Node));
        NodeType *crt = malloc(sizeof(struct Node));
        temp->data =data;
        crt = L->current;
        if(L->current == L->first){ // if the current is pointing to the first value, we can simply just use insertBeforeFirst, but I only realize that after I am done with the function.
            temp->prev = NULL;
            crt->prev = temp;
            temp->next = crt;
            L->first = temp;
            L->current = temp;
        }
        else{ // if current if not pointing to the first one, then just connect prev->next to new data and curren->prev to the new data.
            crt->prev->next = temp;
            temp->prev= crt->prev;
            temp->next = crt;
            crt->prev = temp;
            if(L->current == L->first){
                L->first = temp;
            }
            L->current = temp;
        }
    }
}
void insertAfterCurrent(ListRef L, long data){ // Inserts new element after current one
    // Pre: !offEnd(); Post: !isEmpty(), !offEnd()
    if(!offEnd(L)){
        NodeType *temp = malloc(sizeof(struct Node));
        NodeType *crt = malloc(sizeof(struct Node));
        temp->data =data;
        crt = L->current;
        if(L->current == L->last){ // if current is pointing to the last value, just set the value to the very last one.
            temp->prev = crt;
            crt->next = temp;
            temp->next = NULL;
            L->last= temp;
            L->current = temp;
        }
        else { // if its not connecting to the last part, just connect the next and current with the new data.
            crt->prev =temp;
            temp->next = crt;
            crt->prev->next = temp;
            temp->prev = crt->prev;
            if(L->current == L->last){
                L->last = temp;
            }
            L->current = temp;
        }
    }
}
void deleteFirst(ListRef L){ // delete the first element. Pre: !isEmpty()
    if(!isEmpty(L)){
        NodeType *temp = malloc(sizeof(struct Node));
        temp=L->first;
        if(L->first == L->last){ // if the list only has 1 value, just make the list empty
            makeEmpty(L);
        }
        else{ // else, just set L->first to the next value of the original first
            temp=temp->next;
            temp->prev =NULL;
            L->first = temp;
            L->current = temp;
        }
    }
}
void deleteLast(ListRef L){ // delete the last element. Pre: !isEmpty()
    if(!isEmpty(L)){
        NodeType *temp = malloc(sizeof(struct Node));
        temp=L->last;
        if(L->first == L->last){ // if the list only has 1 value, just make the list empty.
            makeEmpty(L);
        }
        else{ // else just make last the prev of the original last.
            temp=temp->prev;
            temp->next=NULL;
            L->last = temp;
            L->current = L->last;
        }
    }
}
void deleteCurrent(ListRef L){ // delete the current element.
    // Pre: !isEmpty(), !offEnd(); Post: offEnd()
    if(!isEmpty(L) && !offEnd(L)){
        NodeType *temp = malloc(sizeof(struct Node));
        NodeType *crt=malloc(sizeof(struct Node));
        temp=L->current->prev;
        crt=L->current;
        if(L->current == L->first){ // if the current is the first one, just use the deletefirst function 
            deleteFirst(L);
        }
        else if(L->current == L->last){ //if current is the last one, just use the deletelast function 
            deleteLast(L);
        }
        else { // else just connect the prev and next of the current one together. 
            temp->next = crt->next;
            crt->next->prev = temp;
        }
    }
}
/*** Other operations ***/
void printList(ListRef L){
    moveFirst(L);
    while(!offEnd(L)){
        printf("%ld ",getCurrent(L));
        printf("%d ", L->current->count);
        moveNext(L);
    }
    printf("\n");
}

ListRef copyList(ListRef L){ // print out the list in order from left to right. 
    NodeType *listL = malloc(sizeof(struct Node));
    ListRef K=newList();
    listL=L->first;
    while(listL !=NULL){
        insertAfterLast(K, listL->data);
        listL=listL->next;
    }
    //printList(K);
    return K;
}

// adds book ID onto the list
void add(ListRef L, long ID){
    if(isEmpty(L)){
    insertBeforeFirst(L, ID);
    increaseCount(L);
    return;
    }
    else if(!isEmpty(L))
    {
     moveFirst(L);
     int insert = 0;
        while( !offEnd(L)){
     if(ID == getCurrent(L)){
     increaseCount(L);
     insert = 1;
         return;
     }
        moveNext(L);
     }
     
     if(insert == 0){
         insertAfterLast(L, ID);
     increaseCount(L);
     }
     }
}

// increase count of priority for copurchase list
void increaseCount(ListRef L){
    L->current->count++;
}

// returns priority copurchase count
int getCount(ListRef L){
    return L->current->count;
}

// returns priority of other copurchase count so they can be compared
int getPrevCount(ListRef L){
    movePrev(L);
    int x = getCount(L);
    moveNext(L);
    return x;
}

// swaps two nodes on a list
// similar to swap function needed in program2
void swap(ListRef L){
    NodeType *node = malloc(sizeof(struct Node));
    NodeType *temp = malloc(sizeof(struct Node));
    if(atLast(L)){
        node->data =L->current->data;
        node->count = L->current->count;
        
        temp->data= L->current->prev->data;
        temp->count = L->current->prev->count;
        
        
        node->prev = L->current->prev->prev;
        L->current->prev->prev->next = node;
        temp->next=NULL;
        node->next = temp;
        temp->prev = node;
        L->last = temp;
        
           }
    else{
    node->data = L->current->data;
    node->count = L->current->count;
    node->prev = L->current->prev->prev;
    node->next = L->current->prev;
    L->current->prev->prev->next = node;
    L->current->prev->prev=node;
    L->current->prev->next= L->current->next;
    L->current->next->prev= L->current->prev;
    }
}

bool inList(ListRef L, long ID){
     moveFirst(L);
     for(int i=0; i<getLength(L); i++){
             if(getCurrent(L) == ID){
                              return true;
                              }
                              else{
                                   if(!atLast(L)){
                                   moveNext(L);
                                   }
                                   }
                                   
                                   }
                                   
                                   return false;
                                   }
                                   
long getNewRecID(ListRef X, ListRef L){
     moveNext(X);
     long x = getCurrent(X);
     if(inList(L, x)){
                   x = getNewRecID(X, L);
                   }
     else{
     return x;
     }
                   }
                   
                                   
                                   
                              
                              
                              
                              
                              
                              
                              

