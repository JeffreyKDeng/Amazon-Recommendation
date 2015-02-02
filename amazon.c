// Jeffrey Deng (jkdeng) & Kevin Andres (kandres)

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>

#include "bookListList.h"
//#include "bookCountList.h"

int success = EXIT_SUCCESS;
char *execname = NULL;
int exit_status = 0;

int main (int argc, char **argv) {
    execname = basename (argv[0]);
    // number of customers and purchases
    int customers;
    int purchases;
    int tablesize;
    FILE *input = fopen (argv[1], "r");
    if (input == NULL) {
        // tell the user that there is something wrong with input
        fflush (NULL);
        //outputted data written to file.
        fprintf (stderr, "%s: %s: %s\n",
                 execname, argv[1], strerror (errno));
        fflush (NULL);
        // there was an error and now the program can exit
        exit_status= EXIT_FAILURE;
    }else {
        //if input is not null, we can accept parameters for number of customers and purchases
        fscanf(input,"%d", &customers);
        fscanf(input,"%d", &purchases);
        fscanf(input,"%d", &tablesize);
        ListRef list=newList();
        ListRef *customer=calloc(sizeof(list), customers);
        for(int i=1;i<=customers;i++){
            customer[i]=newList();
        }
        
        HashRef h1 = newHashTable(tablesize);
        
    
        // initialize IDs for books and customers from the inputted file
        for(int i=0; i<purchases;i++){
            int customerID;
            long bookID;
            int RecOrNot;
            fscanf(input,"%d", &customerID);
            fscanf(input, "%ld", &bookID);
            fscanf(input, "%d", &RecOrNot);
            add(customer[customerID], bookID);
        //    printList(customer[customerID]);
            if(!findHash(h1, bookID)){
                 //            printf("123");
            insertHash(h1, bookID);
            // printf("222");
           //  printHash(h1);
           // checkDouble(h1);
         //    printf("333");
           // printHash(h1);
            }
            int x = spotHash(h1, bookID);
          //   printf("444");
            increaseHash(h1, x , customer[customerID]);
          //   printf("555");
            //printHash(h1);
           //  printf("666");
            printRec(h1, RecOrNot, bookID, customer[customerID]);
        }
        
  /*      // now go through the list and change position of the spots on the list
        //how to use offEnd here???
        // check if current is null
        bool currIsNull = false;
        int curr = 0;
        for(int i=1;i<=customers;i++){
            if(!currIsNull)
            printf("%d\t",i);
            // set the current to the front of the list
            moveFirst(customer[i]);
            while(!offEnd(customer[i])){
                printf("\t%ld", getCurrent(customer[i]));
                if(!currIsNull)
                moveNext(customer[i]);
                curr = 0;
            }
            printf("\n");
            
        }
   */
        fclose (input);
        exit_status = EXIT_SUCCESS;
    }
}
