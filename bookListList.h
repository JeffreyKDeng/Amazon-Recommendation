// Jeffrey Deng (jkdeng) & Kevin Andres (kandres)
// Constructors
/*** Constructors-Destructors ***/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bookCountList.h"

typedef struct HashTable *HashRef;
HashRef newHashTable(int); // creates a new hashtable
void insertHash(HashRef HashTable, long ID); // takes book ID and places it on a spot on the list uses modulo in order to find an open spot
void SortOrder(HashRef h,int j);// determines if there is a copurchase count and the loop sorts the list if the number of copurchases is high for a book, it will be put in front of the list for being recommended to a customer.
void insertHash(HashRef h, long ID); // takes book ID and places it on a spot on the list uses modulo in order to find an open spot
bool findHash(HashRef h, long ID); // if there is an open space on the table, the ID will be placed there
void increaseHash(HashRef h,int j, ListRef LL); // hashtable takes bookID and linked list and changes list based on new ID
int spotHash(HashRef h, long ID); // similar to findHash, but will instead return value of spot on the list where the ID is placed
void printHash(HashRef h);// runs through hash table and prints the elements that should be recommended
void printRec(HashRef h, int YesNo, long bookID, ListRef L); // checks if book reccomendation should be printing based on whether it's value is 1 or 0.
void doubleHash(HashRef h);
void checkDouble(HashRef h);
