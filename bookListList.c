// Jeffrey Deng (jkdeng) & Kevin Andres (kandres)
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "bookListList.h"

 struct HashTable{
    int size;
    int currSize;
    ListRef *htable;
} HashType;

// creates a new hashtable
HashRef newHashTable (int s){
    HashRef h= malloc(sizeof(HashType));
    h->size = s;
    h->currSize = 0;
    h->htable= calloc(s, sizeof(ListRef));
    //for every spot on the array, there is a new list created
    for(int i = 0;i<=s; i++){
        h->htable[i]=newList();
    }
    return h;
}

// determines if there is a copurchase count and the loop sorts the list
// if the number of copurchases is high for a book, it will be put in front
// of the list for being recommended to a customer.
void SortOrder(HashRef h,int j){
    moveFirst(h->htable[j]); //sets htable[j] to first spot on list
    moveNext(h->htable[j]);
    // runs as long as it is not on the last spot on the list
    while(!atLast(h->htable[j])){
        moveNext(h->htable[j]);
        //printf("xx\n");
        if(getCurrent(h->htable[j]) == getSecond(h->htable[j])){
            moveNext(h->htable[j]);
            //printf("yy");
        }
        int currCount = getCount(h->htable[j]);
        int CompCount = getPrevCount(h->htable[j]);
        if(currCount>CompCount){
            swap(h->htable[j]);
            //printf("zz");
            movePrev(h->htable[j]);
            movePrev(h->htable[j]);
           // printf("RR\n");
        }
    }
}

// takes book ID and places it on a spot on the list
// uses modulo in order to find an open spot
void insertHash(HashRef h, long ID){

    int startingIndex = 0;
    // for loop will run through the list and will try to insert bookID on
    // a list spot. if the list spot is already taken, i increments,
    // changing the modulo value, to go to a different spot on the list
    for (int i = startingIndex; i<h->size-1; i++){
        int j = (ID+i)% (h->size);
        if(isEmpty(h->htable[j])){
            add(h->htable[j],ID);
            h->currSize++;
        break;
        }
    }
    }

// if there is an open space on the table, the ID will be placed there
bool findHash(HashRef h, long ID){
    int startingIndex = 0;
    int exist =0;
    for(int i = startingIndex; i<h->size-1; i++){
        int j = (ID+i)% (h->size);
        if(isEmpty(h->htable[j])){
        }
        else{
            if(getFirst(h->htable[j]) == ID){
            exist = 1;
               return true;
    
        }
        }
        
    if(exit == 0){
        return false;
    }
}
}

// similar to findHash, but will instead return value of spot on the list
// where the ID is placed
int spotHash(HashRef h, long ID){
    int startingIndex = 0;
    // exist will change if spot is not empty
    int exist =0;
    for(int i = startingIndex; i<h->size-1; i++){
        int j = (ID+i)% (h->size);
        if(isEmpty(h->htable[j])){
                                  return NULL;
        }
        else{
            if(getFirst(h->htable[j]) == ID){
                exist = 1;
                return j;
            }
        }

}
}

// hashtable takes bookID and linked list and changes list based on
// new ID
void increaseHash(HashRef h,int j, ListRef LL){
    moveLast(LL);
    if(getCurrent(LL) == getFirst(LL)){
       // printf("11");
        return;
    }
    long newID = getCurrent(LL);
    for(int i = 0; i<getLength(LL)-1 ; i++){
       // printf("22");
        movePrev(LL);
        long LLCurrID = getCurrent(LL);
       // printf("33");
        add(h->htable[j], LLCurrID);
       // printf("44");
        SortOrder(h, j);
       // printf("55");
        if(findHash(h,LLCurrID)){
           // printf("66");
        int x = spotHash(h,LLCurrID);
           // printf("77");
            add(h->htable[x],newID);
          //  printf("88");
          SortOrder(h, x);
        //    printf("99");
    }
    }
}
    
// checks if book reccomendation should be printing based on whether it's
// value is 1 or 0.
void printRec(HashRef h, int YesNo, long bookID, ListRef L) {
    if(YesNo == 0){
        return;
    }
    else{
        long recID;
        int x = spotHash(h, bookID);
        printf("customers buying book: %ld", bookID);
        if(getLength(h->htable[x])>=2){
        recID = getSecond(h->htable[x]);
        //start
              if(inList(L, recID)){
                          // printf("00");
                             moveFirst(h->htable[x]);
                             //printf("11");
                             moveNext(h->htable[x]);
                           recID = getNewRecID(h->htable[x], L);
                           }
                                   
        
        
        //end
                     printf("  also purchased book : %ld \n", recID);
                                  return;
        }
        else{
             printf("  and no Recommendation for this book");
             }
    }
    }
    

// runs through hash table and prints the elements that should be
// recommended
void printHash(HashRef h){
    for(int i = 0; i<h->size; i++){
        if(isEmpty(h->htable[i])){
            printf("%d empty List \n", i);
        }
        else{
        moveFirst(h->htable[i]);
        long FID = getCurrent(h->htable[i]);
        printf("%d BooKID: %ld   Recommend List:", i,FID);
        for(int x = 0; x<getLength(h->htable[i])-1; x++){
            if(atLast(h->htable[i])){
                printf("None\n");
            }
            else{
            moveNext(h->htable[i]);
            long currID = getCurrent(h->htable[i]);
            printf("  %ld,", currID);
        }
        }
            printf("\n");
}
}
}





void doubleHash(HashRef h){
     printf("doubleling \n");
     int oldLength = h->size;
       HashRef hNew = newHashTable(oldLength *2);
                    printf("before insert");
                                          printHash(hNew);
       for(int i=0; i <h->size; i++){   
                    if(!isEmpty(h->htable[i])){
                                          insertHash(hNew, getFirst(h->htable[i]));
                                          printf("after insert");
                                           printHash(hNew);
                                           printf("table #%d",i);
                                          }
               else{
                    }
                                          }
                                          
               for(int j = 0;j<hNew->size; j++){
                       printf("xxx");
                       if(getFirst(hNew->htable[j]) != NULL){
                                                    printf("yyy");
                       int x = spotHash(h, getFirst(hNew->htable[j]));
                       printf("zzz");
                            hNew->htable[j] = h->htable[x];
}                             
                                          }
                                          
                            h->htable = hNew->htable;
                            h->size= hNew->size;
                            printf("finished doubling");
                                          }



void checkDouble(HashRef h){
     int x = h->size /2;
     if(h->currSize > x){
     doubleHash(h);
                           }
                           }


