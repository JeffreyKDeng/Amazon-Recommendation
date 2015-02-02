// Jeffrey Deng (jkdeng) & Kevin Andres (kandres)
#include <stdio.h>
 #include "bookCountList.h"
 #include "bookListList.h"
 //int main(){
 int main(){
 // long num1=234;//initilize some numbers to be inserted to the list
 // long num2=123;
 // long num3=455;
 // long num4=555;
 
 ListRef listA = newList();
 ListRef listB = newList();
 //   insertBeforeFirst(listA, 123);
 //  printList(listA);
 //   insertAfterLast(listA, 2);
 //     printList(listA);
 //    insertAfterLast(listA, 234);
 //printList(listA);
 
 add(listA, 234);
 //    printList(listA);
 add(listA, 333);
 //  printList(listA);
 add(listA, 455);
 //    printList(listA);
 add(listA, 234);
 //  printList(listA);
 add(listA, 455);
 //printList(listA);
 add(listA, 123);
 // printList(listA);
 add(listA, 123);
 // printList(listA);
 add(listA, 333);
 //printList(listA);
 add(listA, 333);
 //printList(listA);
 add(listA, 133);
 //printList(listA);
 add(listA, 30);
 add(listA, 30);
 add(listA,30);
 add(listA, 30);
 
 
 add(listB, 234);
 //    printList(listA);
 add(listB, 333);
 //  printList(listA);
 add(listB, 455);
 //    printList(listA);
 add(listB, 234);
 //  printList(listA);
 add(listB, 455);
 //printList(listA);
 add(listB, 123);
 // printList(listA);
 add(listB, 123);
 // printList(listA);
 add(listB, 333);
 //printList(listA);
 add(listB, 333);
 //printList(listA);
 add(listB, 133);
 //printList(listA);
 add(listB, 30);
 add(listB, 60);
 
 //    printList(listA);
 HashRef hashsetA = newHashTable(15);
 insertHash(hashsetA, 12334);
 insertHash(hashsetA, 30);
 insertHash(hashsetA, 60);
 insertHash(hashsetA, 133);
 insertHash(hashsetA, 123);
 insertHash(hashsetA, 455);
 insertHash(hashsetA, 333);
 insertHash(hashsetA, 234);
 insertHash(hashsetA, 34289);
 
 int x = findHash(hashsetA, 30);
 increaseHash(hashsetA, x, listA);
 int b = findHash(hashsetA, 60);
 increaseHash(hashsetA, b, listB);
 printHash(hashsetA);
 //    printf("%ld", findHash (hashsetA, 12334));
 
 
 }
